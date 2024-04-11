#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

typedef long long ll;
typedef long double ld;

const int MAX_N = 200000;


using namespace std;
const ll MOD = 1000000007;

int d[MAX_N];

string q[MAX_N];

ll dp[MAX_N][10];
ll dps[MAX_N][10];

int n;


int main()
{
    ios_base::sync_with_stdio(false);
    d[0] = 0;
    cin >> q[0];
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        //scanf("%d->", &d[i + 1]);
        cin >> d[i + 1];
        char c;
        cin >> c >> c;
        getline(cin, q[i + 1]);
    }
    for (int i = 0; i < 10; ++i)
        dp[n + 1][i] = i;
    for (int i = 0; i < 10; ++i)
        dps[n + 1][i] = 10;
    for (int i = n; i >= 0; --i)
    {
        for (int j = 0; j < 10; ++j)
            dp[i][j] = dp[i + 1][j];
        for (int j = 0; j < 10; ++j)
            dps[i][j] = dps[i + 1][j];
        dp[i][d[i]] = 0;
        dps[i][d[i]] = 1;
        for (int j = (int)q[i].size() - 1; j >= 0; --j)
        {
            dp[i][d[i]] = (dp[i][d[i]] + dps[i][d[i]] * dp[i + 1][q[i][j] - '0']) % MOD;
            dps[i][d[i]] = (dps[i][d[i]] * dps[i + 1][q[i][j] - '0']) % MOD;
        }
        //cout << dp[i][d[i]] << "\n";
    }
    cout << dp[0][0];
    return 0;
}