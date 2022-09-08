#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}
 
const int N = 1e6 + 5;

vector <int> ans;
int a[N], st[N], vis[N];
int T, n, top;

void dfs1(int u) {
    if (vis[u]) {
        while (st[top + 1] != u) {
            ans.push_back(st[top]);
            --top;
        }
        return;
    }
    vis[u] = 1; st[++top] = u;
    dfs1(u - a[u]);
}

int main() {
    read(T);
    while (T--) {
        read(n); top = 0;
        for (int i = 1; i <= n; i++) read(a[i]), st[i] = vis[i] = 0;
        ans.clear(); dfs1(1);
        print((int)ans.size(), '\n');
        for (int i = 0; i < (int)ans.size(); i++) print(ans[i], ' ');
        putchar('\n');
    }
    return 0;
}