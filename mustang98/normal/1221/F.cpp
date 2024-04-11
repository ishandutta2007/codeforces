#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111;
ll inf = 1e18;

struct tree {
    ll a[4 * max_n], f[4 * max_n];

    void clr() {
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
    }
    tree() {
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
    }
    void push(int v, int l, int r) {
        if (f[v] != 0) {
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            a[2 * v] += f[v];
            a[2 * v + 1] += f[v];
            f[v] = 0;
        }
    }
    void update(int v, int tl, int tr, int l, int r, ll value) {
        if (tl == l && tr == r) {
            f[v] += value;
            a[v] += value;
            return;
        }
        push(v, tl, tr);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
        a[v] = max(a[2 * v], a[2 * v + 1]);
    }
    ll get_max(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return a[v];
        }
        push(v, tl, tr);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_max(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_max(2 * v + 1, mid + 1, tr, l, r);
        }
        return max(get_max(2 * v, tl, mid, l, mid), get_max(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
} tr;

int n;
int x[max_n], y[max_n], c[max_n];
vector<int> cps;

int get_sm(int lar) {
    return lower_bound(cps.begin(), cps.end(), lar) - cps.begin();
}

vector<int> v[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", x + i, y + i, c + i);
        cps.PB(x[i]);
        cps.PB(y[i]);
    }
    sort(cps.begin(), cps.end());
    cps.erase(unique(cps.begin(), cps.end()), cps.end());
    for (int i = 0; i < n; ++i) {
        x[i] = get_sm(x[i]);
        y[i] = get_sm(y[i]);
        int fr = min(x[i], y[i]);
        v[fr].PB(i);
    }
    int mx = cps.size();
    for (int i = 1; i < mx; ++i) {
        tr.update(1, 0, mx - 1, i, i, cps[0] - cps[i]);
    }
    for (int i = 0; i < n; ++i) {
        int fr = max(x[i], y[i]);
        tr.update(1, 0, mx - 1, fr, mx - 1, c[i]);
    }

    ll ans = -inf;
    ll fr = -1;
    for (ll i = 0; i < mx; ++i) {
        ll cur  = tr.get_max(1, 0, mx - 1, i, mx - 1);
        if (cur > ans) {
            ans = cur;
            fr = i;
        }
        if (i == mx - 1) {
            break;
        }
        for (int p : v[i]) {
            tr.update(1, 0, mx - 1, max(x[p], y[p]), mx - 1, -c[p]);
        }
        tr.update(1, 0, mx - 1, i, mx - 1, cps[i + 1] - cps[i]);
    }
    //cout << ans << endl;

    ////////////////////
    tr.clr();
    for (int i = 1; i < mx; ++i) {
        tr.update(1, 0, mx - 1, i, i, cps[0] - cps[i]);
    }
    for (int i = 0; i < n; ++i) {
        int fr = max(x[i], y[i]);
        tr.update(1, 0, mx - 1, fr, mx - 1, c[i]);
    }
    if (ans < 0) {
        cout << 0 << endl;
        int a = 1e9 + 100;
        cout << a << ' ' << a << ' ' << a << ' ' << a << endl;
        return 0;
    }

    cout << ans << endl;
    cout << cps[fr] << ' ' << cps[fr] << ' ';
    //exit(0);
    for (int i = 0; i < mx; ++i) {
        if (i == fr) {
            for (int j = i; j < mx; ++j) {
                if (tr.get_max(1, 0, mx - 1, j, j) == ans) {
                    cout << cps[j] << ' ' << cps[j] << endl;
                    exit(0);
                }
            }
        }
        if (i == mx - 1) {
            break;
        }
        for (int p : v[i]) {
            tr.update(1, 0, mx - 1, max(x[p], y[p]), mx - 1, -c[p]);
        }
        tr.update(1, 0, mx - 1, i, mx - 1, cps[i + 1] - cps[i]);
    }

    return 0;
}