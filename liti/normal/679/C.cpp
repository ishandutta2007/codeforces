//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 500 + 10; 

string a[maxN]; 
int par[maxN*maxN], sz[maxN*maxN]; 
int fath[maxN][maxN]; 
int mark[maxN*maxN]; 
vector<int> last; 

int dx[] = { 0 , 1 , -1 , 0 } ; 
int dy[] = { 1 , 0 ,  0 , -1 } ; 
int n,K;

inline bool valid( int x , int y ) { 
	return min(x,y) >= 0 && max(x,y) < n && a[x][y] == '.'; 
}
inline int gg( int x , int y ) { 
	return x * n + y; 
}

int dfind( int u ) { 
	return par[u] == -1 ? u : par[u] = dfind( par[u] ); 
}
inline void dmerge( int u , int v ) { 
	u = dfind(u) , v = dfind(v); 
	if( u == v ) return;
	if( sz[u] > sz[v] ) swap( u , v ); 
	par[u] = v; 
	sz[v] += sz[u] ;
}


set<int> curr; 
int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	 cin >> n >> K;
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i]; 
	memset( par , -1 , sizeof par ); 
	int ret = 0;
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < n ; j++ ) if( valid(i,j) ) { 
			sz[gg(i,j)] = 1 ; 
			for( int k = 2 ; k < 4 ; k++ ) { 
				int x = i + dx[k] , y = j + dy[k]; 
				if( valid( x , y ) ) 
					dmerge( gg(x,y) , gg(i,j) ) ; 
			}
			ret = max( ret , sz[gg(i,j)] );
		}
	for( int i =0 ; i < n ; i++ ) 
		for( int j = 0 ; j < n ; j++ ) 
			fath[i][j] = dfind(gg(i,j)); 
	/*for( int i = 0 ; i < n ; i++ ) {
		for( int j = 0 ; j < n; j++ ) 
			cout << sz[dfind(gg(i,j))] << ' ' ; 
		cout << endl;
	}*/
	for( int i = 0 ; i + K <= n ; i++ ) { 
		for( int j = 0 ; j < K ; j++ ) 
			for( int k = i ; k < i + K ; k++ ) 
				if( a[k][j] == '.' ) 
					sz[fath[k][j]]--; 
		for( int j = 0 ; j + K <= n ; j++ ) { 
			curr.clear();
			int ans = 0; 
			if( i ) 
				for( int p = j ; p < j + K ; p++ ) { 
					int v = fath[i-1][p];
					if( !mark[v] ) { 
			//			cout << "   ! ! " << v/n<< ' ' << v % n << ' ' << sz[v] << endl;
						mark[v] = true;
						last.push_back(v);
						ans += sz[v]; 
					}
				}
			if( j ) 
				for( int k = i ; k < i + K ; k++ ) { 
					int v = fath[k][j-1];
					if( !mark[v] ) { 
			//			cout << "   ! ! " << v/n<< ' ' << v % n << ' ' << sz[v] << endl;
						mark[v] = true;
						last.push_back(v);
						ans += sz[v]; 
					}
				}
			if( i + K < n ) 
				for( int p = j ; p < j + K ; p++ ) { 
					int v = fath[i+K][p];
					if( !mark[v] ) { 
			//			cout << "   ! ! " << v/n<< ' ' << v % n << ' ' << sz[v] << endl;
						mark[v] = true;
						last.push_back(v);
						ans += sz[v]; 
					}
				}
			if( j + K < n ) 
				for( int k = i ; k < i + K ; k++ ) { 
					int v = fath[k][j+K]; 
					if( !mark[v] ) { 
			//			cout << "   ! ! " << v/n<< ' ' << v % n << ' ' << sz[v] << endl;
						mark[v] = true;
						last.push_back(v);
						ans += sz[v]; 
					}
				}
			ret= max( ret , ans + K * K );
			//cerr << i << ' ' << j << ' ' << ans + K * K << endl;

			for( int k = i ; k < i + K ; k++ ) 
				if( a[k][j] == '.' ) 
					sz[fath[k][j]]++; 
			if( j + K < n ) 
				for( int k = i ; k < i + K ; k++ ) 
					if( a[k][j+K] == '.' ) 
						sz[fath[k][j+K]]--;
			for( auto x : last ) mark[x] = false;
			last.clear();
		}
		for( int j = n - K + 1 ; j < n ; j++ ) 
			for( int k = i ; k < i + K ; k++ ) 
				if( a[k][j] == '.' ) 
					sz[fath[k][j]]++; 
	}
	cout << ret << endl;
}