//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 1000 * 100 + 100;
bool mark[maxN]; 
vector<int> c[maxN]; 
int par[maxN];

int n, m; 
int ans[maxN];

void dfs( int s , int p = -1 ) { 
    mark[s] = true; 
    par[s] = p;
    for( auto x : c[s] ) 
        if( x != p ) { 
            if( mark[x] ) { 
                int v = s; 
                ans[v] = 1;
                do { 
                    v = par[v]; 
                    ans[v] = 1;
                } while( v != x );
                throw(0);
            } else 
                dfs( x , s );
        }
    if( p != -1 ) 
        c[s].erase( find(c[s].begin(),c[s].end(),p) );
}

const int S = 6;
vector<int> dp[maxN][S], up[maxN][S];

void solve( int s ) {
    mark[s] = true;
    auto& d = dp[s];
    for( int j = 0 ; j < S ; j++ ) 
        d[j].push_back( - (j+1)*(j+1) );

    auto& upd = up[s];

    for( auto x : c[s] ) { 
        solve( x ); 
        for( int j = 0 ; j < S ; j++ ) { 
            auto& last = d[j].back();

            int sz = c[x].size();

            int u = 0; 
            int v = last + dp[x][0][sz] + (j+1) * 1;

            for( int k = 1 ; k < S ; k++ ) { 
                if( v < last + dp[x][k][sz] + (j+1) * (k+1) ) { 
                    v = last + dp[x][k][sz] + (j+1) * (k+1);
                    u = k; 
                }
            }

            d[j].push_back(v);
            upd[j].push_back(u);
        }
    }
}

void calc(int s, int j, int k) {
    if( k == 0 ) {
        ans[s] = j+1;
        return;
    }
    calc( c[s][k-1] , up[s][j][k-1] , c[c[s][k-1]].size() );
    calc( s , j , k - 1 );
}

int main() { 

    int T; cin >> T;
    for( int tt = 0 ; tt < T ; tt++ ) { 
        try {
            cin >> n >> m;
            memset( mark , 0 , sizeof mark ); 
            memset( par , -1 , sizeof par ); 
            memset( ans , 0 , sizeof ans ) ;
            fill( c , c + n , vector<int>() );
            for( int i = 0 ; i < n ; i++ ) 
                for( int j = 0 ; j < S ; j++ ) 
                    dp[i][j] = up[i][j] = vector<int>();

            for( int i = 0 ; i < m ; i++ ){ 
                int u, v; cin >> u >> v;
                u--; v--; 
                c[u].push_back(v); 
                c[v].push_back(u);
            }
            for( int i = 0 ; i < n ; i++ ) 
                if( !mark[i] ) 
                    dfs( i );

            memset( mark , 0 , sizeof mark ); 
            for( int i = 0 ; i < n ; i++ ) 
                if( !mark[i] ) { 
                    solve(i); 
                    int k = c[i].size();
                    for( int j = 0 ; j < S ; j++ ) { 
                        if( dp[i][j][k] >= 0 ) {
                            calc(i,j,k);
                            throw(0);
                        }
                    }
                }

            cout << "NO\n" ; 
        } catch( int v ) { 
            cout << "YES" << '\n';
            for( int i= 0 ; i < n ; i++ ) 
                cout << ans[i] << ' ' ; 
            cout << '\n';
        }
    }
}