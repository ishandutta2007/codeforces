/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000*100 + 10;
const int mod = 1e9 + 9;

int par[maxN];
int tav[maxN];

int dFind( int u ) { 
	return ( par[u] == u ? u : par[u] = dFind(par[u]) ) ; 
}

void dUnion(int u, int v) { 
	par[v] = u;
}

int main() { 
	memset( par, -1 , sizeof par )  ; 

	tav[0] = 0;
	for(int i = 1 ; i < maxN ; i++ ) 
		tav[i] = ( 2*tav[i-1] + 1 ) % mod;

	int n,m;
	cin >> n >> m;
	int used = 0;

	int comps = 0;
	
	for(int i = 0 ; i < m ; i++ ) { 
		int x,y;
		cin >> x >> y ;
		x--; y--;

		for(int k = 0 ; k < 2 ; k++ ) {
			if( par[x] == -1 ) {
				par[x] = x;
				used++;
				comps++;
			}
			swap(x,y);
		}

		if( dFind(x) != dFind(y) ) {
			comps--;
			dUnion( dFind(x), dFind(y) ) ; 
		}

		cout << tav[i + 1 - used + comps] << endl;
	}
}