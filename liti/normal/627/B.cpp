//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

#define __sz(x) ((int)(x).size())
typedef long long ll; 

const int maxN = 200 * 1000 + 100; 
ll fen[2][maxN]; 

inline ll get( int id , int x ) { 
	ll ret = 0; 
	for( ; x ; x -= x & -x ) 
		ret += fen[id][x]; 
	return ret;
}
void add( int id , int x , int v ) { 
	x++; 
	for( ; x < maxN ; x += x & -x ) 
		fen[id][x] += v; 
}

ll arr[maxN]; 
bool ok[2][maxN]; 

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	int n,k,a,b,q; cin >> n >> k >> a >> b >> q; 

	for( int i = 0 ; i < q ; i++ ) { 
		int t; cin >> t; 
		if( t == 1 ) { 
			int x,v; cin >> x >> v; 
			x--; 
			int last = arr[x]; 
			arr[x] += v; 
			if( !ok[0][x] && arr[x] >= b ) { 
			   ok[0][x] = 1; 
			   add( 0 , x , b - last ); 
			} else if( !ok[0][x] ) 
				add( 0 , x , v ); 
			if( !ok[1][x] && arr[x] >= a ) { 
				ok[1][x] = 1; 
				add( 1 , n - x - 1 , a - last ); 
			} else if( !ok[1][x] ) 
				add( 1 , n - x - 1 , v ); 
		} else { 
			int l; cin >> l; l--; 
			int r = l + k; 
			cout << get( 0 , l ) + get( 1 , n - r ) << endl;
		}
	}
}