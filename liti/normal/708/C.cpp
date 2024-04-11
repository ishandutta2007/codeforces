//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
const int maxN = 400 * 1000 + 100 ; 
vector<int> c[maxN]; 
int sz[maxN]; 
int n;

vector<int> good; 
bool ans[maxN]; 

int dsz( int s , int p = -1 ) { 
	bool canDo = true; 
	for( auto x : c[s] ) 
		if( x != p ) { 
			sz[s] += dsz(x,s); 
			if( sz[x] > n/2 ) 
				canDo = false;
		}
	sz[s]++; 
	if( n - sz[s] > n/2 ) canDo = false; 
	if( canDo ) { 
		good.push_back(s); 
		ans[s] = 1; 
	}

	return sz[s];
}

int V; 
void solve( int s , int p = -1 ) { 
	bool canDo = true; 
	for( auto x : c[s] ) 
		if( x != p ) { 
			solve( x , s ); 
			if( sz[x] > n/2 ) canDo = false; 
		}
	if( canDo && n - sz[s] - V <= n/2 ) ans[s] = true; 
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	 cin >> n; 
	for( int i = 0 ; i < n - 1 ; i++ ) { 
		int u,v; cin >> u >> v; 
		u--; v--; 
		c[u].push_back(v); 
		c[v].push_back(u); 
	}
	dsz(0); 
	for( auto s : good ) { 
//		cerr << s << endl;
		memset( sz , 0 , sizeof sz ); 
		dsz(s); 
		vector<pair<int,int>> curr; 
		for( auto x : c[s] ) 
			curr.push_back( { sz[x] , x } ); 
		sort( curr.begin() , curr.end() ); 
		int en = curr.size(); 
		for( auto x : c[s] ) { 
			int v = n - sz[x]; 
			if( v > n/2 ) v = 0; 
			if( en && curr.back().second != x ) 
				v = max( v , curr.back().first ); 
			else if( en > 1 ) 
				v = max( v , curr[en-2].first ); 
			V = v; 
			solve(x,s); 
		}
	} 
	for( int i = 0 ; i < n ; i++ ) 
		cout << ans[i] << " " ; 
	cout << '\n'; 
}