/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000*100*10 + 10;
const int mod = 1e9 + 7;

int par[maxN], val[maxN];
set<pair<int,int>> mo[maxN];

int dFind( int u ) { 
	return par[u] == -1 ? u : par[u] = dFind( par[u] ) ; 
}

void dUnion( int u , int v ) { 
	if( mo[u].size() < mo[v].size() ) 
		swap(u,v);

	while( mo[v].size() ) { 
		auto x = mo[v].begin();
		mo[u].insert( {x->first , ( ( ( (x->second + val[v]) % mod + mod ) % mod - val[u] ) % mod + mod ) % mod } ) ;
//		cout << x->first << ' ' <<  ( ( ( (x->second + val[v]) % mod + mod ) % mod - val[u] ) % mod + mod ) % mod << endl;
		mo[v].erase( mo[v].begin() ) ; 
	}
	par[v] = u;
}

int main() { 
	memset( par , -1 ,sizeof par ) ; 
	int n;
	cin >> n;

	int ans = 0; 

	for( int i = 0 ; i < n ; i++ ) { 
		int k ; 
		cin >> k;
		mo[i].insert( make_pair( i , 0 ) ) ; 

		for( int j = 0 ; j < k ; j++ ) { 
			int v, x;
			cin >> v >> x;
			v--;
			int last = ans;
			ans = ( ans + mo[dFind(v)].lower_bound( {v, 0} )->second ) % mod;
//			cout << "DD " << mo[dFind(v)].lower_bound( {v, 0} )->second << endl;
			ans = ( ans + val[dFind(v)] ) % mod;
			ans =(  ans +  (  x + mod ) % mod ) % mod;
//			cout << ans << endl;
			if( ans < 0 ) {
				cout << "Hoy!" << i << ' ' << j << endl;
			}
			val[dFind(v)] = ( val[dFind(v)] + (  ( ans - last ) % mod + mod ) % mod ) % mod;
			dUnion( dFind(i) , dFind(v) ) ;
		}
	}

	cout << ans << endl;
}