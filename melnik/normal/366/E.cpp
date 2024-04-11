#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 2050;
const int inf = 1e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn][maxn];
int b[maxn * maxn];

int dist[10][10];
vector <int> pos[maxn][10];

int main()
{
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    int n, m, k, l;
    scanf ("%d%d%d%d", &n, &m, &k, &l);
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < m; ++j)
    		scanf ("%d", &a[i][j]);
    for (int i = 0; i < l; ++i)
    	scanf ("%d", &b[i]);
    for (int i = 1; i <= k; ++i)
    	for (int j = 0; j < n; ++j) {
    		for (int y = 0; y < m; ++y)
    			if (a[j][y] == i) {
    				pos[j][i].pb(y);
    				break;
    			}
    		for (int y = m - 1; y >= 0; --y)
    			if (a[j][y] == i) {
    				pos[j][i].pb(y);
    				break;
    			}
    	}
    for (int i = 1; i <= k; ++i)
    	for (int j = i; j <= k; ++j)
    		for (int y = 0; y < n; ++y) {
    			if (pos[y][i].empty())
    				continue;
    			for (int u = 0; u < n; ++u) {
    				if (pos[u][j].empty())
    					continue;
    				// dist[i][j] = max(dist[i][j], abs(y - u) + abs(pos[y][i][0] - pos[u][j][0]));
    				dist[i][j] = max(dist[i][j], abs(y - u) + abs(pos[y][i][0] - pos[u][j][1]));
    				// dist[i][j] = max(dist[i][j], abs(y - u) + abs(pos[y][i][1] - pos[u][j][1]));
    				dist[i][j] = max(dist[i][j], abs(y - u) + abs(pos[y][i][1] - pos[u][j][0]));
    			}
    		}
    for (int i = 1; i <= k; ++i)
    	for (int j = 1; j <= k; ++j)
    		dist[i][j] = max(dist[i][j], dist[j][i]);
    int ans = 0;
    for (int i = 0; i < l - 1; ++i)
    	ans = max(ans, dist[b[i]][b[i + 1]]);
    printf("%d\n", ans);
    return 0;
}