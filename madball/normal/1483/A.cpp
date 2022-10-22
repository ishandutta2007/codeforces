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

void doit(vector<int>& aaa, int a)
{
    if (!aaa.empty() && aaa.back() != a)
        aaa.pop_back();
    else
        aaa.push_back(a);
}

void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<pair<int, int>> ar(m);
    vector<int> aaa;
    For(i, m)
    {
        int k;
        scanf("%d %d", &k, &ar[i].second);
        ar[i].first = ar[i].second;
        For(j, k - 1)
        {
            scanf("%d", &ar[i].first);
            swap(ar[i].first, ar[i].second);
        }
        if (ar[i].first == ar[i].second)
        {
            doit(aaa, ar[i].first);
        }
    }
    vector<int> res(m);
    vector<int> cnt(n);
    For(i, m)
    {
        if (ar[i].first == ar[i].second)
        {
            res[i] = ar[i].first;
        }
        else
        {
            if (!aaa.empty() && aaa.back() == ar[i].first)
                res[i] = ar[i].second;
            else
                res[i] = ar[i].first;
            doit(aaa, res[i]);
        }
        ++cnt[res[i] - 1];
    }
    int mx = 0;
    For(i, n)
        mx = max(mx, cnt[i]);
    if (mx > (m + 1) / 2)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
        For(i, m)
            printf("%d ", res[i]);
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
    int t;
    scanf("%d", &t);
    For(i, t)
        solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}