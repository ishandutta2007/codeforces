#define push_back pb
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 200000;

vector<int> nei[N];
int64_t res[N][6], n, k, a, b, ans, t, vis[N], sz[N];
//int64_t sres[N][6], n, k, a, b, ans, t, vis[N], sz[N];

void count(int v)
{
    vis[v] = ++t;
    sz[v] = 1;
    int prev = -1;
    for (auto i: nei[v]) if (!vis[i])
    {
        count(i);
        ++res[i][0];
        sz[v] += sz[i];
        if (prev != -1)
        {
            ans += res[v][k] * sz[i];
            ans += (res[i][k] + res[i][0]) * (sz[v] - sz[i] - 1);
            for (int j = 0; j < k; ++j)
                for (int l = 0; l < k; ++l)
                    if (j != 0 && j + l + 1 <= k)
                        ans -= res[v][j] * res[i][l];
        }
        for (int j = 0; j < k; ++j)
            res[v][(j + 1) % k] += res[i][j];
        res[v][k] += res[i][k] + res[i][0];
        prev = i;
    }
    ans += res[v][k];
}

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i < n; ++i)
        cin >> a >> b, nei[--a].pb(--b), nei[b].pb(a);
    count(0);
    cout << ans;
    return 0;
}