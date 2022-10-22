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

int compress[500];
int cnt[500];

void solve()
{
    int n;
    scanf("%d", &n);
    vector<vector<int>> ar(1, vector<int>(n));
    For(i, n)
    {
        scanf("%d", &ar[0][i]);
        compress[i] = ar[0][i];
    }
    sort(compress, compress + n);
    int compress_size = unique(compress, compress + n) - compress;
    For(i, n)
        ar[0][i] = lower_bound(compress, compress + compress_size, ar[0][i]) - compress;
    fill(cnt, cnt + compress_size, 0);
    For(i, n)
        ++cnt[ar[0][i]];
    For(i, compress_size)
        if (cnt[i] % 2)
        {
            printf("-1\n");
            return;
        }
    vector<pair<int, int>> ans1;
    vector<int> ans2;
    vector<int> i(1, 0);
    int ptr = 0;
    vector<int> buffer;
    for (; !ar.empty(); ++ptr)
    {
        int e = ar.back()[i.back()];
        if ((++i.back()) == sz(ar.back()))
        {
            ar.pop_back();
            i.pop_back();
        }
        if (buffer.empty() || e != buffer.front())
        {
            buffer.push_back(e);
            continue;
        }
        for (int k = 1; k < sz(buffer); ++k)
            ans1.emplace_back(ptr + k, buffer[k]);
        if (sz(buffer) > 1)
        {
            ar.emplace_back(buffer.rbegin(), buffer.rend() - 1);
            i.emplace_back(0);
        }
        ptr += sz(buffer) - 1;
        ans2.emplace_back(sz(buffer));
        buffer.clear();
    }
    printf("%d\n", sz(ans1));
    For(i, sz(ans1))
        printf("%d %d\n", ans1[i].first, compress[ans1[i].second]);
    printf("%d\n", sz(ans2));
    For(i, sz(ans2))
        printf("%d%c", ans2[i] * 2, (i + 1 == sz(ans2) ? '\n' : ' '));
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