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

const int N = 755, MAXN = 1e7 + 5;

queue <int> q;
char c[MAXN];
vector <int> adj[N << 1];
int ch[MAXN][2], fail[MAXN], id[MAXN], l[N], r[N], pre[N << 1], used[N << 1], vis[N << 1];
int f[N][N], n, len, tot, dfn, ans;

int dfs1(int u) {
    for(register unsigned i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(used[v] != dfn) {
            used[v] = dfn;
            if(!pre[v] || dfs1(pre[v])) {
                pre[v] = u; pre[u] = v;
                return 1;
            }
        }
    }
    return 0;
}

void dfs2(int u) {
    vis[u] = 1;
    for(register unsigned i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(!vis[v] && pre[v]) vis[v] = 1, dfs2(pre[v]);
    }
}

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) {
        scanf("%s", c + r[i - 1] + 1);
        len = strlen(c + r[i - 1] + 1);
        l[i] = r[i - 1] + 1;
        r[i] = l[i] + len - 1;
        int now = 0;
        for(register int j = l[i]; j <= r[i]; j++) {
            int x = c[j] - 'a';
            if(!ch[now][x]) ch[now][x] = ++tot;
            now = ch[now][x];
        }
        id[now] = i;
    }
    for(register int i = 0; i <= 1; i++) if(ch[0][i]) q.push(ch[0][i]);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(register int i = 0; i <= 1; i++) {
            int v = ch[u][i];
            if(!v) continue;
            // fail[v] = ch[fail[u]][i];
            int now = fail[u], last = 1;
            while(last) {
                if(ch[now][i]) {
                    fail[v] = ch[now][i];
                    break;
                }
                last = now;
                now = fail[now];
            }
            if(!id[v]) id[v] = id[fail[v]];
            q.push(v);
        }
    }
    for(register int i = 1; i <= n; i++) {
        int now = 0;
        for(register int j = l[i]; j <= r[i]; j++) {
            int x = c[j] - 'a';
            now = ch[now][x];
            if(j == r[i]) f[i][id[fail[now]]] = 1;
            else f[i][id[now]] = 1;
        }
    }
    for(register int k = 1; k <= n; k++) {
        for(register int i = 1; i <= n; i++) {
            for(register int j = 1; j <= n; j++) {
                f[i][j] |= (f[i][k] & f[k][j]);
            }
        }
    }
    for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= n; j++) {
            if(f[i][j]) {
                // fprintf(stderr, "%d %d\n", i, j);
                adj[i].push_back(j + n);
                adj[j + n].push_back(i);
            }
        }
    }
    ans = n;
    for(register int i = 1; i <= n; i++) if(!pre[i]) ++dfn, ans -= dfs1(i);
    print(ans, '\n');
    for(register int i = 1; i <= n; i++) if(!pre[i]) dfs2(i);
    for(register int i = 1; i <= n; i++) if(vis[i] && !vis[i + n]) print(i, ' ');
    putchar('\n');
    return 0;
}