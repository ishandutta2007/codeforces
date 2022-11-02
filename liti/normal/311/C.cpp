//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxK = 10000 + 10; 
const int maxN = 1000*100 + 100;
ll dis[maxK];
vector<int> con[maxK];
ll moves[30]; int movecnt;
ll p[maxN];
int a[maxN];
set<pair<int,int>> curr;
set<pair<ll,int>> dcurr;
int n,m,k;

void dij() { 
	memset( dis , 31 , sizeof dis );
	dis[1] = 0;
	dcurr.insert( { 0 , 1 } ) ; 
	while( dcurr.size() ) { 
		int s = dcurr.begin()->second;
		dcurr.erase( dcurr.begin() ) ; 
		for( int j = 0 ; j < movecnt ; j++ ) { 
			int x = (s+moves[j]) % k;
			ll nd = ( s + dis[s]*k + moves[j] ) / k;
			if( nd < dis[x] ) { 
				dcurr.erase( { dis[x] , x } ) ; 
				dis[x] = nd;
				dcurr.insert( { dis[x] , x } ) ; 
			}
		}
	}
	curr.clear();
	for( int i = 0 ; i < k ; i++ ) 
		for( auto x : con[i] ) 
			if( p[x] / k >= dis[i] ) 
				curr.insert( { -a[x] , x } ) ; 
}
int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	ll h;
	cin >> h >> n >> m >> k; 
	for( int i = 0 ; i < n ; i++ ) { 
		cin >> p[i] >> a[i];
		con[p[i]%k].push_back(i) ; 
	}
	dij();
	for( int i = 0 ; i < m ; i++ ) { 
		int t; cin >> t;
		if( t == 1 ) { 
			ll x; cin >> x;
			moves[movecnt++] = x; 
			dij(); 
		} else if( t == 2 ) { 
			int x, y;
			cin >> x >> y; x--; 
			if( curr.erase( { -a[x] , x } )  ) { 
				a[x] -= y;
				curr.insert( { -a[x] , x } ) ;
			} else 
				a[x] -= y;
		} else {
			cout << (curr.size()?-curr.begin()->first:0) << '\n';
			if( curr.size() ) { 
				int x = curr.begin()->second, y = a[x];
				curr.erase( { -a[x] , x } ) ;
				a[x] -= y;
			}
		}
	}
}