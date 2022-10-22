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

int ar[200500];
vector<int> positions[200500];
void solve()
{
    int n;
    scanf("%d", &n);
    For(i, n + 1)
        positions[i].clear();
    For(i, n)
    {
        scanf("%d", &ar[i]);
        positions[ar[i]].push_back(i);
    }
    For(i, n + 1)
        reverse(all(positions[i]));

    static vector<int> ans;
    ans.clear();
    int left = 0;
    while (left < n)
    {
        int m = 0;
        while (!positions[m].empty())
            ++m;
        ans.push_back(m);
        if (m == 0)
        {
            positions[ar[left]].pop_back();
            ++left;
            continue;
        }
        int pos = 0;
        For(i, m)
            pos = max(pos, positions[i].back());
        left = pos + 1;
        For(i, m)
            while (!positions[i].empty() && positions[i].back() <= pos)
                positions[i].pop_back();
    }
    printf("%d\n", sz(ans));
    For(i, sz(ans))
        printf("%d%c", ans[i], (i + 1 == sz(ans) ? '\n' : ' '));
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