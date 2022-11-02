//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef pair<int,int> pii; 

const int mod = 1e9 + 7; 
const int maxS = (1<<20); 
const int maxN = 75 + 2;

int dp[maxN][maxS]; 

inline int sum( int a , int b ) { 
    int c = a + b; 
    if( c >= mod ) c -= mod; 
    return c; 
}

int main() { 
    int n; 
    cin >> n;
    string s; cin >> s; 

    int ans = 0; 
    for( int i = 0 ; i < n ; i++ ) { 
        dp[i][0] = 1; 
        int z = 1; 
        int num = 0; 
        for( int j = i ; j >= 0 ; j-- ) { 
            num += z * (s[j]-'0'); 
            z = min( maxS * 2 , z * 2 ) ; 
            if( num > 20 ) break;
            if( num == 0 ) continue;
            int ss = num - 1; 
            for( int mask = 0 ; mask < maxS ; mask++ ) { 
                if( (mask>>ss) & 1 ) { 
                    dp[i+1][mask] = sum(dp[i+1][mask],dp[j][mask^(1<<ss)]); 
                    dp[i+1][mask] = sum(dp[i+1][mask],dp[j][mask]);
                }
            }
        }
        for( int v = 1 ; v < maxS ; v = v * 2 + 1 ) { 
            ans = sum( ans , dp[i+1][v] ); 
        }
    }
    if( dp[n][maxS-1] ) 
        cout << "HI " << __builtin_popcount(maxS-1) << endl;
    cout << ans << endl;
}