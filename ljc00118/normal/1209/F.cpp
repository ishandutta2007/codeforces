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

const int N = 2e6 + 5, md = 1e9 + 7;

vector <int> adj[N][10];
vector < vector <int> > now1, now2;
vector <int> tmp;
int dis[N], vis[N];
int n, m, tot;

inline void addedge(int u, int v, int val) {
    while(val >= 10) {
        adj[++tot][val % 10].push_back(v);
        v = tot; val /= 10;
    }
    adj[u][val].push_back(v);
}

int main() {
    read(n); read(m); tot = n;
    for(register int i = 1; i <= m; i++) {
        int u, v;
        read(u); read(v);
        addedge(u, v, i); addedge(v, u, i);
    }
    tmp.push_back(1); now1.push_back(tmp); vis[1] = 1;
    while(now1.size()) {
        now2.clear();
        for(register int i = 0; i < (int)now1.size(); i++) {
            for(register int z = 0; z <= 9; z++) {
                tmp.clear();
                for(register int t = 0; t < (int)now1[i].size(); t++) {
                    int u = now1[i][t];
                    for(register int j = 0; j < (int)adj[u][z].size(); j++) {
                        int v = adj[u][z][j];
                        if(!vis[v]) {
                            dis[v] = (1ll * dis[u] * 10 + z) % md;
                            vis[v] = 1; tmp.push_back(v);
                        }
                    }
                }
                if(tmp.size()) now2.push_back(tmp);
            }
        }
        now1 = now2;
    }
    for(register int i = 2; i <= n; i++) print(dis[i], '\n');
    return 0;
}