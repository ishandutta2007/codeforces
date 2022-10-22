#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 5e5 + 5;

int n, P, Q, R;
int a[N];
int b[N];
int c[N];
int mxb[N];
int mxc[N];
int mn[4 * N];
int mx[4 * N];
int pu[4 * N];
ll sm[4 * N];

void update(int v, int tl, int tr, int val) {
    mn[v] = val;
    mx[v] = val;
    sm[v] = 1ll * (tr - tl + 1) * val;
    pu[v] = val;
}

void push(int v, int tl, int tm, int tr) {
    if(pu[v]) {
        update(v << 1, tl, tm, pu[v]);
        update(v << 1 | 1, tm + 1, tr, pu[v]);
        pu[v] = 0;
    }
}

void merge(int v) {
    mn[v] = min(mn[v << 1], mn[v << 1 | 1]);
    mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
    sm[v] = sm[v << 1] + sm[v << 1 | 1];
    pu[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val) {
    if(l <= tl && tr <= r) {
        update(v, tl, tr, val);
    }else {
        int tm = (tl + tr) >> 1;
        push(v, tl, tm, tr);
        if(l <= tm) {
            update(v << 1, tl, tm, l, r, val);
        }
        if(r > tm) {
            update(v << 1 | 1, tm + 1, tr, l, r, val);
        }
        merge(v);
    }
}

int getLeft(int v, int tl, int tr, int val) {
    if(tl == tr) {
        if(mn[v] <= val) {
            return tl;
        }else {
            return -1;
        }
    }else {
        int tm = (tl + tr) / 2, res;
        push(v, tl, tm, tr);
        if(mn[v << 1] <= val) {
            res = getLeft(v << 1, tl, tm, val);
        }else {
            res = getLeft(v << 1 | 1, tm + 1, tr, val);
        }
        merge(v);
        return res;
    }
}

ll getSum(int v, int tl, int tr, int l, int r) {
    if(l <= tl && tr <= r) {
        return sm[v];
    }else {
        int tm = (tl + tr) >> 1;
        push(v, tl, tm, tr);
        ll res = 0;
        if(l <= tm) {
            res += getSum(v << 1, tl, tm, l, r);
        }
        if(r > tm) {
            res += getSum(v << 1 | 1, tm + 1, tr, l, r);
        }
        merge(v);
        return res;
    }
}

vec< int > add[N];

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d %d", &n, &P, &Q, &R);

    for(int i = 1;i <= n;i++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        add[a[i]].push_back(i);
    }

    for(int i = P;i >= 1;i--) {
        if(i < P) {
            mxb[i] = mxb[i + 1];
            mxc[i] = mxc[i + 1];
        }else {
            mxb[i] = 0;
            mxc[i] = 0;
        }
        for(int id : add[i]) {
            mxb[i] = max(mxb[i], b[id]);
            mxc[i] = max(mxc[i], c[id]);
        }
    }

    ll result = 0;

    for(int p = 1;p <= P;p++) {
        if(p == 1) {
            result += 1ll * (Q - mxb[p]) * (R - mxc[p]);
        }else {
            if(mxb[p] < Q) {
                int le = getLeft(1, 1, Q, mxc[p]);
                ll tot = 1ll * (Q - mxb[p] + 1) * (R - mxc[p] + 1);
                tot -= (R - mxc[p] + 1);
                if(le == -1) {
                    tot -= (getSum(1, 1, Q, mxb[p] + 1, Q) - 1ll * (mxc[p] - 1) * (Q - mxb[p]));
                }else {
                    if(le <= mxb[p] + 1) {
                        tot -= (Q - mxb[p]);
                    }else {
                        tot -= (Q - le + 1);
                        tot -= (getSum(1, 1, Q, mxb[p] + 1, le - 1) - 1ll * (mxc[p] - 1) * (le - 1 - mxb[p]));
                    }
                }
                result += tot;
            }
        }
        for(int id : add[p]) {
            int le = getLeft(1, 1, Q, c[id]);
            if(le == -1 || le > b[id]) { }
            else {
                update(1, 1, Q, le, b[id], c[id]);
            }
        }
    }

    cout << result << "\n";

    return 0;
}