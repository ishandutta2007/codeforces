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
#include <deque>
using namespace std;

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

deque<int> ar[111];
int ans[111][111];

void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);
    For(i, n)
    {
        static int cur[111];
        For(j, m)
            scanf("%d", &cur[j]);
        sort(cur, cur + m);
        For(j, m)
            ar[i].push_back(cur[j]);
    }
    For(j, m)
    {
        int ii = 0;
        For(i, n)
            if (ar[i].front() < ar[ii].front())
                ii = i;
        For(i, n)
        {
            if (i == ii)
            {
                ans[i][j] = ar[i].front();
                ar[i].pop_front();
            }
            else
            {
                ans[i][j] = ar[i].back();
                ar[i].pop_back();
            }
        }
    }
    For(i, n) For(j, m)
        printf("%d%c", ans[i][j], (j + 1 == m ? '\n' : ' '));
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
    scanf("%d", &t);
    For(i, t)
        solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}