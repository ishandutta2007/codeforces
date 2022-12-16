#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define fir first
#define sec second
const int maxn = 4010;
int n, vis[maxn];
char mp[maxn][maxn];

vi vec, mn;
void dfs(int u) {
    vis[u] = 1, vec.push_back(u);
    for (int v = 1; v <= n; ++v) if (mp[u][v] == '1' && !vis[v]) dfs(v);
}

void work() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%s", mp[i] + 1), vis[i] = 0;
    mn.assign(n + 1, 0);
    int comp = 0;
    for (int i = 1; i <= n; ++i) if (!vis[i]) {
        vec.clear(), dfs(i);
        if ((int) vec.size() == n) return printf("0\n"), void();
        if (vec.size() == 1) return printf("1\n%d\n", i), void();
        pii p = {n + 1, -1};
        for (int u : vec) {
            int cnt = 0;
            for (int v = 1; v <= n; ++v)
                if (mp[u][v] == '1') cnt++;
            p = min(p, pii(cnt, u));
        }
        if (p.fir < (int) vec.size() - 1) return printf("1\n%d\n", p.sec), void();
        comp++;
        if (mn.size() > vec.size()) swap(vec, mn);
    }
    if (comp >= 3) {
        sort(begin(mn), end(mn));
        for (int x : mn) vis[x] = 0;
        printf("2\n");
        for (int i = 1; i <= n; ++i) if (vis[i]) { printf("%d ", i); break; }
        printf("%d\n", mn[0]);
        return;
    }
    printf("%zu\n", mn.size());
    for (int x : mn) printf("%d ", x);
    printf("\n");
}

int main() {
    int T; scanf("%d", &T);
    while (T--) work();
	return 0;
}