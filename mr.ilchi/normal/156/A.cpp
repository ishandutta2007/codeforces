/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <complex>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;

const int maxL = 2000 + 10;

string s,t;
int n,m;
int dp[maxL][maxL];

int main(){
    
    cin >> s >> t;

    n = (int)s.size();
    m = (int)t.size(); 

    for (int i=0; i<=n; i++)
        for (int j=0; j<=m; j++){
            if (i==0)
                dp[i][j] = j;
            else if (j==0)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i-1][j-1] + (s[i-1]!=t[j-1]);
        }

    int ans = m;

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++){
            if (i>=j)
                ans = min (ans , dp[i+1][j+1] + m - j - 1);
            else
                ans = min (ans , dp[i+1][j+1] + m - j - 1);
        }

    cout << ans << endl;

    return 0;
}