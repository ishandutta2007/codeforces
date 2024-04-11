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

void solve()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int kek = (n + k + 1) / 2;
    vector<int> ar(n);
    For(i, n)
        scanf("%d", &ar[i]);
    vector<int> ar_sorted(all(ar));
    sort(all(ar_sorted));
    vector<pair<int, int>> cnt;
    for (int l = 0, r = 1; l < n; l = r++)
    {
        while (r < n && ar_sorted[l] == ar_sorted[r])
            ++r;
        cnt.emplace_back(ar_sorted[l], r - l);
    }
    int ans_x = ar_sorted.front(), ans_y = ar_sorted.back();
    int r = 0;
    int cur_sum = 0;
    For(l, sz(cnt))
    {
        while (r < sz(cnt) && (r <= l || cur_sum < kek))
        {
            cur_sum += cnt[r].second;
            ++r;
        }
        if (cur_sum >= kek && cnt[r - 1].first - cnt[l].first < ans_y - ans_x)
        {
            ans_x = cnt[l].first;
            ans_y = cnt[r - 1].first;
        }
        cur_sum -= cnt[l].second;
    }
    printf("%d %d\n", ans_x, ans_y);
    r = 0;
    For(i, k)
    {
        int cur_cnt = 0;
        int l = r;
        while (cur_cnt <= 0)
        {
            cur_cnt += ans_x <= ar[r] && ar[r] <= ans_y ? 1 : -1;
            ++r;
        }
        if (i + 1 == k)
            r = n;
        printf("%d %d\n", l + 1, r);
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