//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<int,int> pii; 

const int maxN = 3000 + 10; 
int num[maxN][maxN]; 
int num2[maxN][maxN];
int dis[maxN][maxN]; 

int inf;
vector<int> c[maxN]; 

int que[maxN], en;
int n,m; 
int CURR; 

bool cmp( int i , int j ){ 
	return dis[CURR][i] > dis[CURR][j] ; 
}
bool cmp2( int i , int j ) { 
	return dis[i][CURR] > dis[j][CURR]; 
}

inline void bfs( int s , int * d ) { 
	en = 0; 
	que[en++] = s; 
	d[s] = 0; 
	for( int i = 0 ; i < en ; i++ ) {
		int s = que[i]; 
		for( auto x : c[s] ) if( d[x] == inf ) { 
			d[x] = d[s] + 1; 
			que[en++] = x; 
		}
	}
	for( int i = 0 ; i < n ; i++ ) 
		num[s][i] = i; 
	CURR = s; 
	sort( num[s] , num[s] + n , cmp ) ; 
}

int mx; vector<int> ans;
int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> m; 

	for( int i = 0 ; i < m ; i++) { 
		int u,v; cin >> u >> v; 
		u--; v--; 
		c[u].push_back(v); 
	}
	memset( dis , -1 , sizeof dis ) ; 
	inf = dis[0][0];
	for( int i =0 ; i < n ;i++ ) 
		bfs(i,dis[i]); 

	for( int i = 0 ; i < n ; i++ ) { 
		for( int j = 0 ; j < n ; j++ ) 
			num2[i][j] = j; 
		CURR = i; 
		sort( num2[i] , num2[i] + n , cmp2 ) ; 
	}

	for( int i = 0 ; i < n ; i++ ) 
		for( int j = 0 ; j < n ; j++ ) if( i != j  && dis[i][j] != -1 ) { 
			for( int kk = 0 ; kk < 4 ; kk++ ) if( dis[num2[i][kk]][i] != -1 ) { 
				int k = num2[i][kk];
				if( k == i || k == j ) continue;
				for( int pp = 0 ; pp < 4 ; pp++ ) if( dis[j][num[j][pp]] != -1 ) { 
					int p = num[j][pp]; 
					if( p == k || p == i || p == j) continue;
					int tmp = dis[i][j] + dis[k][i] + dis[j][p]; 
					if( tmp > mx ) { 
						mx = tmp; 
						ans.clear(); 
						ans.push_back( k ) ;
						ans.push_back( i ) ;
						ans.push_back( j ) ;
						ans.push_back( p ) ;
					}
				}
			}
		}
	cerr << mx << endl;
	for( auto x : ans ) cout << x + 1 << ' ' ; 
	cout << endl;
}