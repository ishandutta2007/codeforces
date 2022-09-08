#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
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

    void clear() { *this = hash_map_t(mod); }

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

const int N = 1e5 + 5;

vector < vector <int> > ans;
set <pii> tr;
set <pii> :: iterator it;
int a[N], b[N], f[N], maxn[N], wz[N], pre[N], vis[N];
int T, n, nn, len;

inline int lowbit(int x) { return x & -x; }

inline void add(int x, int y, int z) {
    for(register int i = x; i <= nn; i += lowbit(i)) {
        if(y > maxn[i]) {
            maxn[i] = y;
            wz[i] = z;
        }
    }
}

inline pii query(int x) {
    int ans1 = 0, ans2 = 0;
    for(register int i = x; i; i ^= lowbit(i)) {
        if(maxn[i] > ans1) {
            ans1 = maxn[i];
            ans2 = wz[i];
        }
    }
    return make_pair(ans1, ans2);
}

void clear(int x) {
    for(register int i = x; i <= nn; i += lowbit(i)) {
        maxn[i] = 0;
        wz[i] = 0;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    read(T);
    for(register int i = 1; i <= 100000; i++) {
        f[i] = f[i - 1];
        if((f[i] + 1) * (f[i] + 2) / 2 <= i) ++f[i];
    }
    // for(register int i = 1; i * (i + 1) / 2 <= 100000; i++) ++f[i * (i + 1) / 2];
    // for(register int i = 1; i <= 100000; i++) f[i] += f[i - 1];
    while(T--) {
        read(n); nn = n; ans.clear();
        for(register int i = 1; i <= n; i++) read(a[i]);
        while(n) {
            // fprintf(stderr, "n = %d\n", n);
            int maxn = 0, wz;
            for(register int i = 1; i <= n; i++) {
                pii t = query(a[i]);
                int nowdp = 1;
                if(!t.first) add(a[i], 1, i);
                else nowdp = t.first + 1, add(a[i], nowdp, i), pre[i] = t.second;
                if(nowdp > maxn) maxn = nowdp, wz = i;
            }
            if(maxn > f[n]) {
                vector <int> now;
                int tmp = wz;
                while(tmp) {
                // fprintf(stderr, "n = %d\n", n);
                    // fprintf(stderr, "tmp = %d\n", tmp);
                    now.push_back(a[tmp]);
                    vis[tmp] = 1;
                    tmp = pre[tmp];
                }
                reverse(now.begin(), now.end());
                ans.push_back(now);
                // assert(maxn == now.size());
                len = 0;
                for(register int i = 1; i <= n; i++) {
                    if(!vis[i]) {
                        b[++len] = a[i];
                    }
                }
                for(register int i = 1; i <= n; i++) clear(a[i]), vis[i] = pre[i] = 0;
                n = len;
                for(register int i = 1; i <= n; i++) a[i] = b[i];
            } else {
                // fprintf(stderr, "ok\n");
                tr.clear();
                for(register int i = 1; i <= n; i++) {
                    // fprintf(stderr, "i = %d\n", i);
                    it = tr.lower_bound(make_pair(a[i], 0));
                    if(it == tr.end()) {
                        ans.push_back(vector <int> (1, a[i]));
                        tr.insert(make_pair(a[i], (int)ans.size() - 1));
                    } else {
                        int id = it -> second;
                        ans[it -> second].push_back(a[i]);
                        tr.erase(it);
                        tr.insert(make_pair(a[i], id));
                    }
                }
                for(register int i = 1; i <= n; i++) clear(a[i]), pre[i] = 0;
                break;
            }
        }
        print(ans.size(), '\n');
        for(register unsigned i = 0; i < ans.size(); i++) {
            print(ans[i].size(), ' ');
            for(register unsigned j = 0; j < ans[i].size(); j++) {
                print(ans[i][j], ' ');
            }
            putchar('\n');
        }
    }
    return 0;
}