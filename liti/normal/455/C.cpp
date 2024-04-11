/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 3000*100 + 10; 

int par[maxN];
int b[maxN];

int dFind( int u ) { 
	return ( par[u] == -1 ? u : par[u] = dFind( par[u] ) ) ; 
}

void dUnion( int u, int v ) { 
	b[u] = max( b[u] , max( b[v] ,  ( b[u] + 1 ) / 2 + (b[v] + 1 ) / 2 + 1) ) ; 
	par[v] = u;
}

int ch1[maxN], ch2[maxN];
vector<int> c[maxN];

pair<int,int> dfs( int node , int h, int* ch ) { 
	int x = h;
	int ret = node;
	ch[node] = true;
	for(int i = 0 ; i < c[node].size() ; i++ ) 
		if( !ch[c[node][i]]  ) {  
			pair<int,int> val = dfs( c[node][i] , h + 1, ch ) ;
			if( val.first > x ) { 
				ret = val.second ;
				x = val.first;
			}
		}


	return make_pair(x,ret);
}

int main() { 
	ios::sync_with_stdio(false);
	memset( par, -1 , sizeof par ) ; 
	int n,m;
	cin >> n >> m;
	int q;
	cin >> q;

	for(int i = 0 ; i < m ; i++ ) { 
		int x,y;
		cin >> x >> y ; 
		x--; y--; 
		if( dFind(x) != dFind(y) ) 
			dUnion( dFind(x) , dFind(y) ) ; 
		c[x].push_back(y);
		c[y].push_back(x); 
	} 

	for(int i = 0 ; i < n ; i++ ) { 
		if( !ch1[i] ) { 
			int x = dfs(i, 0, ch1 ).second ; 
			int val = dfs(x, 0, ch2).first;
	//		cerr << i << ' ' << val << "\n";
			b[ dFind(i) ] = val;
		}
	}

	for(int i = 0 ; i < q ; i++ ) { 
		int num;
		cin >> num;
		if( num == 1 ) { 
			int x;
			cin >> x;
			x--; 
			cout << b[dFind(x)] << endl;
		} else { 
			int x,y;
			cin >> x >> y;
			x--; y--; 
			if( dFind(x) != dFind(y) ) 
				dUnion( dFind(x) , dFind(y) ) ; 
		}
	}
}