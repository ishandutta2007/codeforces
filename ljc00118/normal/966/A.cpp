#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }

    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};

int n, m, cl, ce, v, q;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> cl >> ce >> v;
    vector <int> l(cl), d(ce);
    for(register int i = 0; i < cl; i++) cin >> l[i];
    for(register int i = 0; i < ce; i++) cin >> d[i];
    sort(l.begin(), l.end()); sort(d.begin(), d.end());
    cin >> q;
    while(q--) {
        int x, y, _x, _y, ans = 0x7fffffff;
        cin >> x >> y >> _x >> _y;
        if(x == _x) {
            cout << abs(_y - y) << endl;
            continue;
        }
        if(cl) {
            if(l[cl - 1] >= y) {
                int wz = lower_bound(l.begin(), l.end(), y) - l.begin();
                ans = min(ans, abs(l[wz] - y) + abs(l[wz] - _y) + abs(_x - x));
            }
            if(l[0] <= y) {
                int wz = upper_bound(l.begin(), l.end(), y) - l.begin() - 1;
                ans = min(ans, abs(l[wz] - y) + abs(l[wz] - _y) + abs(_x - x));
            }
        }
        if(ce) {
            if(d[ce - 1] >= y) {
                int wz = lower_bound(d.begin(), d.end(), y) - d.begin();
                ans = min(ans, abs(d[wz] - y) + abs(d[wz] - _y) + (abs(_x - x) + v - 1) / v);
            }
            if(d[0] <= y) {
                int wz = upper_bound(d.begin(), d.end(), y) - d.begin() - 1;
                ans = min(ans, abs(d[wz] - y) + abs(d[wz] - _y) + (abs(_x - x) + v - 1) / v);
            }
        }
        cout << ans << endl;
    }
    return 0;
}