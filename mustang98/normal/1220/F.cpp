#include <bits/stdc++.h>
 
#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
const int max_n = 200111, inf = 1000111222;
 
int n;
int m[max_n];
 
bool debug = 0;
 
struct segment_tree_mn {
    int tr[max_n * 4];
    void build(int cur, int l, int r) {
        if (l == r) {
            tr[cur] = l;
            return;
        }
        int mid = (l + r) / 2;
        build(cur * 2, l, mid);
        build(cur * 2 + 1, mid + 1, r);
        if (m[tr[cur * 2]] < m[tr[cur * 2 + 1]]) {
            tr[cur] = tr[cur * 2];
        } else {
            tr[cur] = tr[cur * 2 + 1];
        }
    }
    int get_min(int cur, int l, int r, int ql, int qr) {
        if (l == ql && r == qr) {
            return tr[cur];
        }
        if (qr < l || ql > r) {
            return inf;
        }
        int mid = (l + r) / 2;
        int r1 = get_min(cur * 2, l, mid, ql, min(mid, qr));
        int r2 = get_min(cur * 2 + 1, mid + 1, r, max(mid + 1, ql), qr);
        if (r1 == inf) {
            return r2;
        }
        if (r2 == inf) {
            return r1;
        }
        if (m[r1] < m[r2]) {
            return r1;
        } else {
            return r2;
        }
    }
} trmin;
 
struct segment_tree_mx {
    int tr[max_n * 4];
    int mx[max_n * 4];
    void build() {
        memset(tr, 0, sizeof(tr));
        for (int i = 0; i < max_n * 4; ++i) {
            mx[i] = -1;
        }
    }
    void sett(int cur, int l, int r, int pos, int val) {
        if (mx[cur] != -1) {
            exit(228);
        }
        if (l == r) {
            tr[cur] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            sett(cur * 2, l, mid, pos, val);
        } else {
            sett(cur * 2 + 1, mid + 1, r, pos, val);
        }
    }
    int gett(int cur, int l, int r, int pos) {
        if (l == r) {
            if (tr[cur] == 0) {
                exit(228);
            }
            return max(tr[cur], mx[cur]);
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            return max(mx[cur], gett(cur * 2, l, mid, pos));
        } else {
            return max(mx[cur], gett(cur * 2 + 1, mid + 1, r, pos));
        }
    }
 
    void setmx(int cur, int l, int r, int ql, int qr, int x) {
        if (l == ql && r == qr) {
            mx[cur] = max(mx[cur], x);
            return;
        }
        if (qr < l || ql > r) {
            return;
        }
        int mid = (l + r) / 2;
        setmx(cur * 2, l, mid, ql, min(mid, qr), x);
        setmx(cur * 2 + 1, mid + 1, r, max(mid + 1, ql), qr, x);
    }
} trmax;
 
void rec(int l, int r, int a) {
    int mn = trmin.get_min(1, 0, n - 1, l, r);
    int val;
    if (mn != l)  {
        rec(l, mn - 1, a);
        val = trmax.gett(1, 0, n - 1, mn - 1) + 1;
    } else {
        val = a + 1;
    }
    trmax.sett(1, 0, n - 1, mn, val);
    if (mn == r) {
        return;
    }
    rec(mn + 1, r, a + 1);
    trmax.setmx(1, 0, n - 1, mn + 1, r, val);
}
 
vector<int> solve(vector<int> v) {
    for (int i = 0; i < n; ++i) {
        m[i] = v[i];
    }
    trmin.build(1, 0, n - 1);
    trmax.build();
    rec(0, n - 1, 0);
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        ans.PB(trmax.gett(1, 0, n - 1, i));
    }
    return ans;
}
 
 
 
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    if (n == 1) {
        cout << "1 0" << endl;
        return 0;
    }
    int p1;
    for (int i = 0; i < n; ++i) {
        //m[i] = i + 1;
        scanf("%d", m + i);
        if (m[i] == 1) {
            p1 = i;
        }
    }
    vector<int> l, r;
    for (int i = 0; i < n; ++i) {
        r.PB(m[(p1 + i) % n]);
        l.PB(m[(p1 - i + n) % n]);
    }
    //reverse(l.begin(), l.end());
    vector<int> al = solve(l);
    if (debug) {
        for (int a : l) {
            cout << a << ' ';
        }
        cout << endl;
        for (int a : al) {
            cout << a << ' ';
        }
        cout << endl;
    }
    vector<int> ar = solve(r);
    if (debug) {
        for (int a : r) {
            cout << a << ' ';
        }
        cout << endl;
        for (int a : ar) {
            cout << a << ' ';
        }
        cout << endl;
    }
    int mn = inf;
    for (int i = 0; i < n; ++i) {
        int cur = max(al[i], ar[n - i - 1]);
        if (cur < mn) {
            mn = cur;
        }
    }
    for (int i = 0; i < n; ++i) {
        int cur = max(al[i], ar[n - i - 1]);
        //cout << i << ' ' << al[i] << ' ' << ar[i] << ' ' << cur << endl;
        if (cur == mn) {
            cout << mn << ' ';
        } else {
            continue;
        }
        int sh = (p1 - i + n) % n;
        cout << sh << endl;
        return 0;
    }
    return 0;
}