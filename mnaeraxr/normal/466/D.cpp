//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;

const int INF = 1<<30;
const double EPS = 1e-9;
const int MAXN = 2000 + 10;
const int64 MOD = 1000000007;

int64 dp[MAXN][MAXN];
/*
10 5
5 4 4 5 5 4 5 5 4 5 5 4
*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, H, v;
    cin >> N >> H >> v;
    if (v == H)
        dp[0][0] = 1;
    else if (v + 1 == H)
        dp[0][1] = dp[0][0] = 1;
    else
    {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i < N; ++i)
    {
        int v;
        cin >> v;

        if (v > H)
        {
            cout << 0 << endl;
            return 0;
        }

        int d = (H - v);
        //DB(d);
        dp[i][d - 1] += dp[i - 1][d] * d;   //DB(dp[i][d - 1]); // ]
        dp[i][d] += dp[i - 1][d - 1];       //DB(dp[i][d]);     // [
        dp[i][d - 1] += dp[i - 1][d - 1] * (d - 1);     //DB(dp[i][d]);     // ][
        dp[i][d - 1] += dp[i - 1][d - 1];   //DB(dp[i][d - 1]); // []
        dp[i][d] += dp[i - 1][d];           //DB(dp[i][d]);     // -
        dp[i][d - 1] %= MOD;
        dp[i][d] %= MOD;
    }

    cout << dp[N - 1][0] << endl;

    return 0;
}