//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef pair<int,int> pii; 

const int maxN = 1000 * 1000 + 1; 
const int mod = 1e9 + 7; 

vector<int> p[maxN]; 

int dp[maxN][50]; 

int main() { 
    ios::sync_with_stdio(false); cin.tie(0);
    for( int i = 2 ; i < maxN ; i++ ) { 
        if( p[i].size() ) continue; 
        for( int j = i ; j < maxN ; j += i ) 
            p[j].push_back( i ); 
    }

    for( int i = 0 ; i < maxN ; i++ ) 
        dp[i][0] = i + 2; 
    for( int j = 1 ; j < 50 ; j++ ) 
        for( int i = 0 ; i < maxN ; i++ ) 
            dp[i][j] = ( dp[i][j-1] + ( i ? dp[i-1][j] : 0 ) ) % mod; 


    int q; cin >> q; 
    for( int i = 0 ; i < q ; i++ ) { 
        int r,n; cin >> r >> n; 
        int ret = 1; 
        for( auto x : p[n] ) { 
            int cnt = 0; 
            for( int y = n ; y % x == 0; cnt++, y /= x ); 
            ret = ret * 1ll * dp[r][cnt-1] % mod; 
        }
        cout << ret << '\n';
    }
}