//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 11; 
int pr[19] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67 }; 

int cnt[19];
int dp[1<<maxN], odp[1<<maxN];
int mask[71];

const int mod = 1e9 + 7; 

inline int sum(int a, int b) { 
    int c = a + b; 
    if( c >= mod ) c -= mod; 
    return c;
}

int main() { 
    ios::sync_with_stdio(false); cin.tie(0);
    for(int i = 2 ; i < 71 ; i++ )  { 
        int v = i;
        int v_mask = 0;
        for(int j = 0 ; j < 19 ; j++)
            while( v % pr[j] == 0 ) {
                if( j >= maxN ) { 
                    mask[i] = -1; 
                    break;
                }
                v_mask ^= (1<<j); 
                v /= pr[j];
            }

        if( mask[i] != -1 ) 
            mask[i] = v_mask;
    }

    int n; 
    cin >> n;

    dp[0] = 1; 
    int z = 1; 

    for(int i = 0 ; i < n ; i++) { 
        int v; cin >> v; 
        int v_mask = mask[v];
        if( v_mask == -1 ) {
            cnt[v]++; 
            if( cnt[v] > 1 ) 
                z = sum(z,z);
            continue;
        }
            
        swap(dp, odp); 
        memset(dp, 0, sizeof dp);
        for(int mask = 0; mask < (1<<maxN); mask++) {
            dp[mask^v_mask] = sum(dp[mask^v_mask], odp[mask]);
            dp[mask] = sum(dp[mask], odp[mask]);
        }
    }

    cout << sum( 1ll*z*dp[0] % mod, mod-1)  << endl;
}