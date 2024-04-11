#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
const int M = 1000000007;

const int maxn = 300005;
int T;
set<int> ans;
int n, m;
int p[maxn];
int q[maxn];
int vis[maxn];

int dfs(int v) {
    vis[v] = 1;
    if (!vis[q[v]])
        return dfs(q[v]) + 1;
    else
        return 0;
}

int main() {
    srand(time(0));
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) scanf("%d", p + i);
        ans.clear();

        int K = 40;
        while (K--) {
            int x = rand() % n + 1;
            int offset = x - p[x];
            if (offset < 0) offset += n;
            if (ans.find(offset) != ans.end()) continue;
            for (int i = 1; i <= n; ++i) {
                int j = i + offset;
                if (j > n) j -= n;
                q[i] = p[j];
            }
            int cnt = 0;
            fill(vis + 1, vis + n + 1, 0);
            // printf("x=%d, offset=%d\n", x, offset);
            for (int i = 1; i <= n; ++i) {
                // printf("%d ", q[i]);
                if (!vis[i]) cnt += dfs(i);
            }
            // printf(": %d\n", cnt);
            if (cnt <= m) ans.insert(offset);
        }

        printf("%d", ans.size());
        for (int u : ans) printf(" %d", u);
        puts("");
    }
    return 0;
}