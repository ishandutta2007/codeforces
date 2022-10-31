//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 5000 + 10; 
typedef long long ll;

const int inf = 1e9 + 1000;

int a[maxN], b[maxN], par[maxN];

int dp[maxN][maxN]; 
int lp[maxN][maxN];

int tmp[maxN];

int n, B; 

vector<int> c[maxN];

int dfs(int s) { 
    int sz = 1; 
    dp[s][0] = 0;
    dp[s][1] = a[s] - b[s]; 
    lp[s][0] = 0; 
    lp[s][1] = a[s];
    for( auto x : c[s] ) { 
        int v = dfs( x ); 
        tmp[0] = 0;
        for( int i = 1 ; i <= sz + v ; i++ ) 
            tmp[i] = inf;

        for( int i = 1 ; i <= sz ; i++ ) 
            for( int j = 0 ; j <= v ; j++ ) 
                tmp[i+j] = min(tmp[i+j],dp[s][i]+min(lp[x][j],dp[x][j]));

        for( int i = 0 ; i <= sz + v ; i++ ) 
            dp[s][i] = tmp[i];

        tmp[0] = 0;
        for( int i = 1 ; i <= sz + v ; i++ ) 
            tmp[i] = inf;
        for( int i = 0 ; i <= sz ; i++ ) 
            for( int j = 0 ; j <= v ; j++ ) 
                tmp[i+j] = min(tmp[i+j],lp[s][i]+lp[x][j]);
        for( int i = 0 ; i <= sz + v ; i++ ) 
            lp[s][i] = tmp[i];

        sz += v;
    }
    return sz;
}

int main() { 
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> B;

    for( int i=  0 ; i < n ; i++ ) 
        for( int j = 0 ; j <= n ; j++ ) 
            dp[i][j] = inf;

    for( int i = 0 ; i < n; i++ ) { 
        cin >> a[i] >> b[i];
        if( i > 0 )  { 
            int p; cin >> p; 
            p--; 
            c[p].push_back( i ); 
        }
    }

    dfs( 0 ); 
    for( int i = n ; i >= 0 ; i-- ) 
        if( min(lp[0][i],dp[0][i]) <= B ) { 
            cout << i << endl;
            return 0; 
        }
}