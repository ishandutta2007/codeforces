#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N;
vi adj[2005];
int num[2005], low[2005], cnt;

void dfs(int u) {
    low[u] = num[u] = ++cnt;
    ff(i, 0, (int)adj[u].size() - 1) {
        int v = adj[u][i];
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (u != 1 && num[u] == low[u]) { cout << "NO" << endl; exit(0); }
}

int main(void) {
    scanf("%d", &N);
    char x = getchar();
    ff(i, 1, N) ff(j, 1, N) {
        while ('0' <= x && x <= '9') x = getchar();
        x = getchar();
        if (x != '0') adj[i].pb(j);
    }
    dfs(1);
    ff(i, 1, N) if (!num[i]) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    return 0;
}