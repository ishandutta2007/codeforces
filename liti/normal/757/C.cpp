//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef pair<int,int> pii; 


const int maxN = 1000 * 1000 + 10; 
set<int> curr[maxN]; 
int pl[maxN];
int cnt[maxN]; 

int mark[maxN], toset[maxN]; 
int fact[maxN]; 

const int mod = 1e9 + 7;

int main() { 
    ios::sync_with_stdio(false); cin.tie(0); 
    int m; 
    int n; cin >> n >> m;

    for( int i = 1 ; i <= m ; i++ ) 
        curr[0].insert( i ); 

    int en = 1; 
    int sum = 1; 
    for( int i = 0 ; i < n ; i++ ) { 
        vector<int> x; 
        int k; cin >> k; 
        for( int j = 0 ; j < k ; j++ ) { 
            int y; cin >> y; 
            x.push_back( y ); 
            cnt[y]++; 
        }
        sort( x.begin() , x.end() ) ; 
        x.resize( unique( x.begin() , x.end() ) - x.begin() ) ; 
        sort( x.begin() , x.end() , []( int i , int j ) { return cnt[i] < cnt[j] ; } ); 
        for( int h = 0, t ; h < int(x.size()) ; h = t ) { 
            for( t = h ; t < int(x.size()) && cnt[x[t]] == cnt[x[h]] ; t++ ); 
            for( int j = h ; j < t ; j++ ) { 
                int y = x[j]; 
                curr[pl[y]].erase( y ); 
                if( mark[pl[y]] != sum ) { 
                    mark[pl[y]] = sum;
                    toset[pl[y]] = en; 
                    curr[en].insert( y ); 
                    pl[y] = en; 
                    en++; 
                } else { 
                    int p = toset[pl[y]]; 
                    pl[y] = p; 
                    curr[p].insert( y ); 
                }
            }

            sum++; 
        }
        for( auto y : x ) 
            cnt[y] = 0; 
    }
    fact[0] = 1; 
    for( int i = 1 ; i < maxN ; i++ ) 
        fact[i] = (fact[i-1] * 1ll * i ) % mod; 

    int ans = 1; 
    for( int i = 0 ; i < en ; i++ ) { 
        ans = ans * 1ll * fact[curr[i].size()] % mod; 
    }
    cout << ans << endl;
}