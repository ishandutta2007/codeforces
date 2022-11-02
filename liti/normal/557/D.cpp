//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 1000 * 100 + 100; 
vector<int> c[maxN];
int check[maxN];

int cnt ;
int comp[maxN][2];
void dfs( int s , int co = 0) { 
	check[s] = co + 1;
	comp[cnt][co]++;
	for( auto x : c[s] ) if( !check[x] ) 
		dfs( x , co ^ 1 ) ; 
}

int main() {
	int n , m;
	cin >> n >> m;
	for( int i  = 0 ; i < m ; i++ ) {
		int a , b; cin >> a >> b; 
		a--; b--; 
		c[a].push_back( b ) ; 
		c[b].push_back( a ) ; 
	}
	for( int i =0 ; i < n; i++ ) if( !check[i] ) { 
		dfs( i ) ; 
		cnt++; 
	}
	for( int s =0 ; s < n ; s++ ) 
		for( auto x : c[s] ) 
			if( check[s] == check[x] ) { 
				cout << "0 1\n" ;
				return 0; 
			}
	ll ret = 0; 
	for( int i = 0 ; i < cnt ; i++ ) 
		for( int t = 0 ; t < 2 ; t++ ) 
			ret += ll(comp[i][t]) * ll(comp[i][t]-1) / 2;
	if( ret > 0 ) { 
		cout << "1 " << ret << endl;
		return 0; 
	}

	for( int s = 0 ; s < n ; s++ ) 
		for( auto x : c[s] ) 
			ret += ( n - 2 ); 
	if( ret > 0 ) { 
		cout << "2 " << ret/2 << endl;
		return 0;
	}
	cout << "3 " << ll(n) * ll(n-1) * ll(n-2) / 6 << endl;
}