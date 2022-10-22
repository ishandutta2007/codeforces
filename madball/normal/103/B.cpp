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

bool been[100];
vector<int> graph[100];
void dfs(int v)
{
    been[v] = true;
    for (auto e : graph[v])
        if (!been[e])
            dfs(e);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    if (n != m)
    {
        cout << "NO\n";
        return;
    }
    For(i, m)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0);
    For(i, n)
        if (!been[i])
        {
            cout << "NO\n";
            return;
        }
    cout << "FHTAGN!\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}