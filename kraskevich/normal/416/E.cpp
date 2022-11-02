#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second

const int INF = (int)1e9;
const int N = 500;

int d[N][N];
int e[N][N];
int ans[N][N];
int L[N];

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            e[i][j] = i == j ? 0 : INF;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        --a;
        --b;
        e[a][b] = e[b][a] = w;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = e[i][j];
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[i][j] = 0;
    for (int s = 0; s < n; s++)
        for (int u = 0; u < n; u++) {
            int cnt = 0;
            for (int v = 0; v < n; v++)
                if (v != u && d[s][v] + e[v][u] == d[s][u])
                    cnt++;
            for (int t = 0; t < n; t++)
                if (s < t && d[s][t] != INF && d[t][u] != INF) {
                    int cur = d[s][t] - d[t][u];
                    if (cur == d[s][u])
                        ans[s][t] += cnt;
                }
        }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            cout << ans[i][j] << " ";
    }
    return 0;
}