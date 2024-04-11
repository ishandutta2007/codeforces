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

const int MAXN = (int)5e5 + 5;
lint ar[MAXN];
vector<int> graph[MAXN];
unordered_map<lint, vector<int>> edges;
bool been[MAXN];

const int MOD = (int)1e9 + 7;
int add(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}
int sub(int a, int b)
{
    return add(a, MOD - b);
}
int mul(int a, int b)
{
    return ((lint)a * b) % MOD;
}
int pw(int a, lint b)
{
    return b == 0 ? 1 : b % 2 ? mul(a, pw(a, b - 1)) : pw(mul(a, a), b / 2);
}

void solve()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    For(i, n)
        scanf("%lld", &ar[i]);
    For(i, m)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        auto it = edges.find(ar[a] ^ ar[b]);
        if (it == edges.end())
        {
            vector<int> kek{ a, b };
            edges.emplace(ar[a] ^ ar[b], kek);
        }
        else
        {
            it->second.push_back(a);
            it->second.push_back(b);
        }
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int res = mul(pw(2, n), sub(pw(2, k), sz(edges)));
    for (const auto& e : edges)
    {
        int comp = n;
        for (auto from : e.second)
        {
            if (been[from])
                continue;
            ++comp;
            static queue<int> q;
            q.push(from);
            been[from] = true;
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                --comp;
                lint a = ar[cur] ^ e.first;
                for (auto nxt: graph[cur])
                    if (!been[nxt] && ar[nxt] == a)
                    {
                        been[nxt] = true;
                        q.push(nxt);
                    }
            }
        }
        for (auto v : e.second)
            been[v] = false;
        res = add(res, pw(2, comp));
    }
    printf("%d\n", res);
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