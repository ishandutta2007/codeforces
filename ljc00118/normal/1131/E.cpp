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

const int N = 100005;

string p[N];
int n, ans, maxn;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(register int i = 1; i <= n; i++) cin >> p[i];
    for(char c = 'a'; c <= 'z'; c++) {
        maxn = 0;
        for(register int i = 1; i <= n; i++) {
            bool ok = 1;
            for(register unsigned j = 0; j < p[i].size(); j++) {
                if(p[i][j] != c) {
                    ok = 0;
                    break;
                }
            }
            int left = 0, mid = 0, right = 0, now = 0;
            for(register unsigned j = 0; j < p[i].size(); j++) {
                if(p[i][j] == c) ++now;
                else now = 0;
                mid = max(mid, now);
            }
            for(register unsigned j = 0; j < p[i].size(); j++) {
                if(p[i][j] == c) ++left;
                else break;
            }
            for(register unsigned j = p[i].size() - 1; j >= 0; j--) {
                if(p[i][j] == c) ++right;
                else break;
            }
            ll new_ans = 0;
            if(ok) {
                new_ans = maxn + 1ll * (maxn + 1) * mid;
            } else if(maxn) {
                new_ans = max(mid, left + right + 1);
            } else new_ans = mid;
            if(new_ans > (int)1e9) new_ans = (int)1e9;
            maxn = new_ans;
        }
        ans = max(ans, maxn);
    }
    cout << ans << endl;
    return 0;
}