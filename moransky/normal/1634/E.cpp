// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 3e5 + 5;

int m, n, a[N], id, du[N];
 
map<int, int> M;

int inline get(int x) {
    if (!M.count(x)) return M[x] = ++id;
    return M[x];
}

int head[N], numE = 1;

struct E{
    int next, v, x, y;
} e[N << 1];

void inline add(int u, int v, int x, int y) {
    e[++numE] = (E) { head[u], v, x, y } ;
    head[u] = numE;
    du[u]++;
}

vector<char> ans[N];

int now = 0;

bool st[N << 1];

void dfs(int u) {
    for (int &i = head[u]; i; i = e[i].next){
        while (i && st[i >> 1]) i = e[i].next;
        if (!i) break;
        st[i >> 1] = 1;
        E z = e[i];
        dfs(z.v);
        ans[z.x][z.y] = now;
        now ^= 1;
    }
}

int main() {
    read(m); id = m;
    for (int i = 1; i <= m; i++) {
        read(n);
        ans[i].resize(n + 1);
        for (int j = 1; j <= n; j++) {
            int x; read(x);
            int u = get(x);
            add(u, i, i, j);
            add(i, u, i, j);
        }
    }
    for (int i = 1; i <= id; i++) {
        if (du[i] & 1) {
            puts("NO");
            return 0;
        }
        dfs(i);
    }
    puts("YES");
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j < ans[i].size(); j++)
            putchar(ans[i][j] ? 'L' : 'R');
        puts("");
    }
    return 0;
}