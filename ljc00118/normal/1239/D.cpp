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

const int N = 1e6 + 5;

vector <int> a[N], b[N];
queue <int> q;
int ans[N];
int T, n, m;

void dfs1(int u) {
    for(register int i = 0; i < (int)a[u].size(); i++) {
        int v = a[u][i];
        if(ans[v]) continue;
        ans[v] = 1; dfs1(v);
    }
}

void dfs2(int u) {
    for(register int i = 0; i < (int)b[u].size(); i++) {
        int v = b[u][i];
        if(ans[v]) continue;
        ans[v] = 1; dfs2(v);
    }
}

int main() {
    read(T);
    while(T--) {
        read(n); read(m);
        for(register int i = 1; i <= n; i++) a[i].clear(), b[i].clear(), ans[i] = 0;
        for(register int i = 1; i <= m; i++) {
            int u, v;
            read(u); read(v);
            a[u].push_back(v);
            b[v].push_back(u);
        }
        ans[1] = 1; dfs1(1);
        int cnt = 0;
        for(register int i = 1; i <= n; i++) {
            if(ans[i] == 0) {
                ++cnt;
            }
        }
        if(cnt) {
            printf("Yes\n");
            print(n - cnt, ' '); print(cnt, '\n');
            for(register int i = 1; i <= n; i++) {
                if(ans[i] == 1) {
                    print(i, ' ');
                }
            }
            putchar('\n');
            for(register int i = 1; i <= n; i++) {
                if(ans[i] == 0) {
                    print(i, ' ');
                }
            }
            putchar('\n');
            continue;
        }
        for(register int i = 1; i <= n; i++) ans[i] = 0;
        ans[1] = 1; dfs2(1);
        cnt = 0;
        for(register int i = 1; i <= n; i++) {
            if(ans[i] == 0) {
                ++cnt;
            }
        }
        if(cnt) {
            printf("Yes\n");
            print(cnt, ' '); print(n - cnt, '\n');
            for(register int i = 1; i <= n; i++) {
                if(ans[i] == 0) {
                    print(i, ' ');
                }
            }
            putchar('\n');
            for(register int i = 1; i <= n; i++) {
                if(ans[i] == 1) {
                    print(i, ' ');
                }
            }
            putchar('\n');
            continue;
        }
        printf("No\n");
    }
    return 0;
}