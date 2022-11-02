#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pii pair<int, int>
#define F first
#define S second

void solve()
{
    long long n, k, f, t, ans = -(1ll << 60);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> f >> t;
        if (t > k)
            ans = max(ans, f - (t - k));
        else
            ans = max(ans, f);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}