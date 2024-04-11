//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    
typedef pair<ll,int> pii;

const int maxN = 300*1000 + 100; 
vector<pii> c[maxN];
vector<int> ans; 

ll d[maxN];
pii u[maxN];

set<pii> curr;
map<pii,int> ed;
ll sum = 0;
void dij( int s ) { 
    memset( d , 31 , sizeof d ) ; 
    memset( u , -1 , sizeof u ) ; 
    d[s] = 0; 

    curr.insert( {0 , s} ) ; 
    while( curr.size() ) { 
	s = curr.begin()->second;
	if( u[s].first != -1 ) {
	    ans.push_back( ed[pii(u[s].first , s)] ) ;
	    sum += u[s].second;
	}
	curr.erase( curr.begin() ) ; 
	for( auto x : c[s] ) {
	    ll dis = x.second + d[s]; 
	    if( d[x.first] > dis || (d[x.first] == dis && u[x.first].second > x.second ) ) {
		curr.erase( { d[x.first] , x.first} ) ; 
		d[x.first] = dis; 
		u[x.first] = { s , x.second } ; 
		curr.insert( { d[x.first] , x.first} ) ; 
	    }
	}
    }
}

int main() { 
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m; 
    for( int i = 0 ; i < m ; i++ )  {
	int u,v,w; cin >> u >> v >> w; 
	u--; v--; 
	c[u].emplace_back( v , w ) ; 
	c[v].emplace_back( u , w ) ; 
	ed[pii(u,v)] = i ;
	ed[pii(v,u)] = i ;
    }
    int s  ; cin >> s; s--; 
    dij(s) ; 
    cout << sum << endl;
    for( int i = 0 ; i < __sz(ans) ; i++ ) 
	cout << ans[i] + 1 << ' ';
}