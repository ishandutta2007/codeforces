//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 1000*100 + 100;
vector<pair<int,int>> c[maxN];
int sz[maxN];
int dsz( int s , int p = -1 ) { 
	for( auto x : c[s] ) 
		if( x.first != p ) 
			sz[s] += dsz( x.first , s ) ; 
	return ++sz[s];
}

int find_centroid( int s ) { 
	int mn = dsz(s) / 2;
	int p = -1; 
	bool found = false;
	do {
		found = false; 
		for( auto x : c[s] ) 
			if( x.first != p && sz[x.first] > mn ) { 
				p = s, s = x.first, found = true;
				break;
			}
	} while( found ) ;
	return s; 
}

ll ans;
int col[maxN];
set<int> val[maxN];
void dfs( int s , int co, int p = -1 , ll d = 0 ) { 
	col[s] = co;
	val[co].insert( s ) ; 
	ans += 2 * d; 
	for( auto x : c[s] ) if( x.first != p ) 
		dfs( x.first , co , s , d + x.second ) ; 
}

set<pair<int,int>> curr, bad;

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	int n; 
	cin >> n; 
	for( int i = 0 ; i < n - 1 ; i++ ) { 
		int u,v,w; cin >> u >> v >> w; 
		u--; v--;
		c[u].push_back( { v , w } ) ; 
		c[v].push_back( { u , w } ) ;
	}
	int s = find_centroid(0);
	col[s] = 0; 
	val[0].insert( s ); 
	int cnt = 1;
	for( auto x : c[s] ) 
		dfs( x.first , cnt++ , s , x.second ) ;
	cout << ans << '\n';
	memset( sz , 0 , sizeof sz ) ; 
	for( int i = 0 ; i < cnt ; i++ ) { 
		curr.insert( { *val[i].begin() , i } ); 
		if( i ) 
			bad.insert( { 2*val[i].size() , i } ) ; 
		sz[i] = val[i].size();
	}
	int sum = n;

	for( int i = 0 ; i < n ; i++ ) { 
		auto it = curr.begin();
		while( ( col[i] && it->second == col[i] )  && it != curr.end() ) it++;
		assert( it != curr.end() ) ; 

		if( bad.size() ) { 
			auto p = *bad.rbegin();
			if( col[i] != p.second ) { 
				int x = sum;
				if( it->second != p.second ) x--;
				// maximize p.first - x -> maximize
				// p.first + val[p.second] 
				if( p.first > x ) 
					it = curr.find( { *val[p.second].begin() , p.second } ) ; 
			}
			sum--;
			bad.erase( { sz[col[i]] + val[col[i]].size() ,col[i] } ) ; 
			sz[col[i]]--;
			if( col[i] != 0 ) 
				bad.insert( { sz[col[i]] + val[col[i]].size() , col[i] } ) ; 
		}


		cout << it->first + 1 << " \n"[i==n-1]; 
		int x = it->second;
		bad.erase( { sz[x] + val[x].size() , x  } ) ; 
		val[x].erase( it->first ) ; 
		if( x != 0 ) 
			bad.insert( { sz[x] + val[x].size() , x  } ) ; 
		curr.erase(it);
		if( val[x].size() ) 
			curr.insert( { *val[x].begin() , x } ) ; 
	}
}