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

const int N = 2e6 + 5;

vector <int> adj[N];
char c[N];
int in[N];
int T, n, m;

int main() {
    read(T);
    while(T--) {
        read(n); m = n;
        for(register int i = 1; i <= n * 4; i++) in[i] = 0, adj[i].clear();
        for(register int i = 1; i < n; i++) {
            int u, v;
            read(u); read(v);
            ++in[u]; ++in[v];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        scanf("%s", c + 1);
        for(register int i = 1; i <= n; i++) {
            if(c[i] == 'W') {
                ++in[i];
                ++m; in[m] = 3;
                adj[i].push_back(m);
                adj[m].push_back(i);
                ++m; in[m] = 1;
                adj[m].push_back(m - 1);
                adj[m - 1].push_back(m);
                ++m; in[m] = 1;
                adj[m].push_back(m - 2);
                adj[m - 2].push_back(m);
            }
        }
        int ans = 0, cnt = 0;
        // for(register int i = 1; i <= m; i++) fprintf(stderr, "in[%d] = %d\n", i, in[i]);
        for(register int i = 1; i <= m; i++) {
            if(in[i] >= 4) {
                ans = 1;
                break;
            }
            if(in[i] == 3) {
                ++cnt; int cnt2 = 0;
                for(register unsigned j = 0; j < adj[i].size(); j++) {
                    int v = adj[i][j];
                    if(in[v] != 1) ++cnt2;
                }
                if(cnt2 >= 2) {
                    ans = 1;
                    break;
                }
            }
        }
        if(ans == 1) {
            printf("White\n");
            continue;
        }
        if(cnt == 2 && m & 1) printf("White\n");
        else printf("Draw\n");
    }
    return 0;
}