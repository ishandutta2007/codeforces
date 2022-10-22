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
#include <bitset>
using namespace std;

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

const int MAXN = (int)2e5 + 5;
const int INF = (int)1e9 + 7;

int deg[MAXN];
bool mark[MAXN];
vector<int> graph[MAXN];

void solve()
{
    int n;
    scanf("%d", &n);
    For(i, n)
        graph[i].clear();
    if (n == 1)
    {
        printf("0\n");
        return;
    }
    if (n == 2)
    {
        scanf("%d", &n);
        scanf("%d", &n);
        printf("1\n");
        return;
    }
    fill(deg, deg + n, 0);
    fill(mark, mark + n, 0);
    For(i, n - 1)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        ++deg[a];
        ++deg[b];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int l = 0;
    static vector<int> leaves;
    leaves.clear();
    For(i, n)
        if (deg[i] == 1)
        {
            ++l;
            leaves.push_back(i);
        }
    if (l == 2)
    {
        printf("1\n");
        return;
    }
    for (auto e : leaves)
    {
        int prv = -1;
        int cur = e;
        while (sz(graph[cur]) <= 2)
        {
            prv = graph[cur][0] != prv ? graph[cur][0] : graph[cur][1];
            swap(prv, cur);
        }
        mark[cur] = true;
    }
    For(i, n)
        l -= mark[i];
    printf("%d\n", l);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    For(i, t)
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}