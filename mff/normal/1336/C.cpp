#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <chrono>
#include <string>
#include <assert.h>
#include <map>
#include <cstring>

using namespace std;

#define endl '\n'

const int mod = 998244353;

void add(int &a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}

string A, B;

int dp[3002][3002];
int p2[3002];

int solve(int n, int m)
{
    int &ans = dp[n][m];
    if (ans != -1)
        return ans;
    ans = 0;

    if (n == 0)
    {
        ans = 1;
        // cout << n << " " << m << " " << ans << endl;
        return ans;
    }

    if (m == B.size())
    {
        ans = p2[n];
        // cout << n << " " << m << " " << ans << endl;
        return ans;
    }

    if (m < B.size() && A[n - 1] == B[m])
    {
        add(ans, solve(n - 1, m + 1));
    }

    if (m + n - 1 < B.size())
    {
        if (B[m + n - 1] == A[n - 1])
            add(ans, solve(n - 1, m));
    }
    else
    {
        add(ans, solve(n - 1, m));
    }

    // cout << n << " " << m << " " << ans << endl;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;
    memset(dp, -1, sizeof dp);
    p2[0] = 1;
    for (int i = 1; i < 3002; ++i)
    {
        p2[i] = p2[i - 1];
        add(p2[i], p2[i]);
    }

    int answer = 0;

    for (int i = B.size(); i <= A.size(); ++i)
        add(answer, solve(i, 0));

    cout << answer << endl;

    return 0;
}