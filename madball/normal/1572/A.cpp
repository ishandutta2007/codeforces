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

const int MAXN = (int)2e5 + 10;
vector<int> graph[MAXN];
int degree[MAXN];
set<int> st;

void solve()
{
    int n;
    scanf("%d", &n);
    For(i, n)
    {
        graph[i].clear();
        degree[i] = 0;
    }
    st.clear();
    For(i, n)
    {
        int k;
        scanf("%d", &k);
        degree[i] = k;
        For(j, k)
        {
            int a;
            scanf("%d", &a);
            --a;
            graph[a].push_back(i);
        }
        if (k == 0)
            st.insert(i);
    }
    int done = 0;
    For(i, n)
    {
        int cur = 0;
        while (true)
        {
            auto it = st.lower_bound(cur);
            if (it == st.end())
                break;
            cur = *it;
            st.erase(it);
            ++done;
            for (auto e : graph[cur])
            {
                --degree[e];
                if (degree[e] == 0)
                    st.insert(e);
            }
        }
        if (done == n)
        {
            printf("%d\n", i + 1);
            return;
        }
    }
    printf("-1\n");
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