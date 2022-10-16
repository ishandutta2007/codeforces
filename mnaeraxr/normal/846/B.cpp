#include <algorithm>
#include <array>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <istream>

#include <map>
#include <math.h>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace asl
{
    typedef long long i64;
    
} 
#include <stdint.h>

#include <experimental/optional>

#include <utility>

#include <tuple>

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

int n, k;
i64 M;
i64 w[50];
i64 dp[50][50][50 * 50];

i64 solve(int r, int p, int pnt)
{
    i64 &ans = dp[r][p][pnt];

    if (ans != -1)
        return ans;

    if (pnt == 0)
        return ans = 0;

    if (r == 0)
        return ans = M + 1;

    ans = solve(r - 1, 0, pnt);

    if (p + 1 == k)
        ans = min(ans, solve(r - 1, 0, max(pnt - 2, 0)) + w[p]);
    else
        ans = min(ans, solve(r, p + 1, pnt - 1) + w[p]);

    return ans;
}

void solve()
{
    memset(dp, -1, sizeof dp);
    cin >> n >> k >> M;

    for (int i = 0; i < k; ++i)
        cin >> w[i];

    sort(w, w + k);

    int ans = 0;
    for (int i = 0; i <= n * (k + 1); ++i)
    {
        if (solve(n, 0, i) <= M)
            ans = i;
        else
            break;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int i = 1; i <= t; ++i)
    {
        solve();
    }

    return 0;
}