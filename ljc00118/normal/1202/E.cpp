#pragma GCC optimize(2)
#pragma GCC optimize(3)
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
 
const int N = 2e5 + 5;
 
struct ac_t {
    queue <int> q;
    vector <int> adj[N];
    int ch[N][26], fail[N], cnt[N], tot;
 
    void insert(char *c, int len) {
        int now = 0;
        for(register int i = 1; i <= len; i++) {
            int x = c[i] - 'a';
            if(!ch[now][x]) ch[now][x] = ++tot;
            now = ch[now][x];
        }
        ++cnt[now];
    }
 
    void buildFail() {
        for(register int i = 0; i <= 25; i++) if(ch[0][i]) q.push(ch[0][i]), adj[0].push_back(ch[0][i]);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(register int i = 0; i <= 25; i++) {
                int v = ch[u][i];
                if(!v) continue;
                int now = fail[u], las = 1;
                while(las) {
                    if(ch[now][i]) {
                        fail[v] = ch[now][i];
                        break;
                    }
                    las = now; now = fail[now];
                }
                adj[fail[v]].push_back(v);
                q.push(v);
            }
        }
    }
 
    void dfs(int u) {
        for(register int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i];
            cnt[v] += cnt[u];
            dfs(v);
        }
    }
 
    void query(char *c, ll *ans, int len) {
        int now = 0;
        for(register int i = 1; i <= len; i++) {
            int x = c[i] - 'a';
            while(now && !ch[now][x]) now = fail[now];
            if(ch[now][x]) now = ch[now][x];
            ans[i] += cnt[now];
        }
    }
} ac1, ac2;
 
char s[N], c[N];
ll ans1[N], ans2[N], ans;
int n, len;
 
int main() {
    scanf("%s", s + 1); read(n);
    for(register int i = 1; i <= n; i++) {
        scanf("%s", c + 1);
        len = strlen(c + 1);
        ac1.insert(c, len);
        reverse(c + 1, c + len + 1);
        ac2.insert(c, len);
    }
    ac1.buildFail(); ac2.buildFail(); ac1.dfs(0); ac2.dfs(0);
    len = strlen(s + 1);
    ac1.query(s, ans1, len);
    reverse(s + 1, s + len + 1);
    ac2.query(s, ans2, len);
    reverse(ans2 + 1, ans2 + len + 1);
    for(register int i = 1; i < len; i++) ans += ans1[i] * ans2[i + 1];
    print(ans, '\n');
    return 0;
}