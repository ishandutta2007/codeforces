#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <deque>
#include <cassert>
#include <cctype>
#include <ctime>

using namespace std;



const int N = 100 * 1000 + 100;
long long cnt[N];
long long len[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> len[i] >> cnt[i];

    long long mx = 0;
    for (int i = 0; i < n; ++i)
    {
        long long cur_pow = 1;
        while ((1ll << (2 * cur_pow)) < cnt[i])
            ++cur_pow;
        mx = max(mx, cur_pow + len[i]);
    }

    cout << mx;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}