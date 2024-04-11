#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <random>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
using namespace std;

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

const int MAXN = 600;
lint dist[MAXN];
vector<int> turrets[MAXN];
int wait_time[MAXN][MAXN];
bool done[MAXN];

void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);
    memset(wait_time, 63, sizeof(wait_time));
    For(i, m) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        wait_time[a][b] = min(wait_time[a][b], c);
    }
    For(i, n)
    {
        For(j, n * 2 + 2)
        {
            int cur = j % n;
            int nxt = (j + 1) % n;
            if (wait_time[i][nxt] > wait_time[i][cur] + 1)
            {
                wait_time[i][nxt] = wait_time[i][cur] + 1;
            }
        }
    }
    For(start, n)
    {
        memset(dist, 63, sizeof(dist));
        memset(done, 0, sizeof(done));
        dist[start] = 0;
        For(_, n)
        {
            int v = -1;
            For(i, n)
                if (!done[i] && (v == -1 || dist[i] < dist[v]))
                    v = i;
            done[v] = true;
            For(i, n)
            {
                int t = (i - dist[v]) % n;
                if (t < 0)
                    t += n;
                dist[i] = min(dist[i], dist[v] + wait_time[v][t]);
            }
        }
        For(i, n)
            printf("%lld ", dist[i]);
        printf("\n");
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //scanf("%d", &t);
    For(i, t)
        solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}