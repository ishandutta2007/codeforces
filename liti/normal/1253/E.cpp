//be naame khodaa
#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <numeric>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

const int N = 80 + 10;
const int M = 2000*100 +  10;

pii a[N]; 

int dp[M];

int main() {
    int n, m; 
    cin >> n >> m; 
    for(int i = 0; i < n; i++) 
        cin >> a[i].F >> a[i].S; 
    sort(a, a + n); 

    memset(dp, 63, sizeof dp); 

    dp[0] = 0;

    int ans = dp[1];
    for(int i = 1; i <= 2*m; i++) { 
        dp[i] = i;
        for(int j = 0; j < n; j++) 
            if( a[j].F <= i ) {  
                int r = a[j].S;
                int c = 0;
                if( a[j].F + r < i ) {
                    c = i - a[j].F - r;
                    r = i - a[j].F;
                }
                dp[i] = min(dp[i], dp[max(0, a[j].F-r-1)] + c);
            } else if( a[j].F - a[j].S <= i ) 
                dp[i] = min(dp[i], dp[max(0, a[j].F - a[j].S -1)]);

        if(i >= m) ans = min(ans,dp[i]);
    }

    cout << ans << endl;
    return 0;
}