/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000*100 + 10 ; 
typedef pair<pair<int,int> , pair<int,int> > edge;
#define F second.first
#define S second.second
#define I first.second
#define W first.first

int par[maxN];

vector<pair<int,int> > c[maxN];
edge e[maxN];
int ans[maxN];

int check[maxN];
	
int n,m;

int dFind( int u ) { 
	return ( par[u] == u ? u : par[u] = dFind( par[u] ) ) ; 
}

void dUnion( int u, int v ) { 
	par[v] = u;
}

int dfs( int node, int h, int p ) { 
	check[node] = h;
	int val = h; 

	vector<pair<int,int> >& tmp = c[node];
	for(int i = 0 ;  i <  tmp.size() ; i++ ) 
		if( !check[tmp[i].first] ) {
			int x = dfs( tmp[i].first , h + 1 , tmp[i].second ) ; 
			if( x <= h ) 
				ans[tmp[i].second] = 1;
			else
				ans[tmp[i].second] = 2;
//			cout << h << ' ' << node << ' ' << x << ' ' << tmp[i].first << ' ' << tmp[i].second << endl;
			val = min(val, x);
		} else if( tmp[i].second != p ) {
			val = min( val, check[tmp[i].first] ) ;
//			cout << "XXXXXX " << h << ' ' << node << ' ' << check[node] << ' ' << tmp[i].first << ' ' << tmp[i].second << endl;
			ans[ tmp[i].second ] = 1;
		}
	tmp.clear();

//	cerr << "HHHHH " << node << ' ' << val << endl;
	return val;
}


int proc( int i )  {
	vector<int> v;
	int weight = e[i].W;
	int f = i;
	for( ; i < m ; i++ ) { 
		if( e[i].W != weight ) 
			break;
		if( dFind(e[i].F) == dFind(e[i].S) ) 
			ans[ e[i].I ] = 0;
		else {
			c[ par[e[i].F] ].push_back( make_pair(par[e[i].S], e[i].I ) ) ;  
			c[ par[e[i].S] ].push_back( make_pair(par[e[i].F], e[i].I )  ) ;  
			v.push_back( par[e[i].F] ) ;
			v.push_back( par[e[i].S] ) ; 
		}
	}

	for(int j = 0 ; j < v.size() ; j++ ) 
		if( !check[v[j]] ) 
			dfs( v[j], 1, -1 ) ; 
	for(int j  = 0 ; j < v.size() ; j++ ) 
		check[v[j]] = 0;

	for(int j = f; j < i ; j++ ) 
		if( dFind(e[j].F) != dFind(e[j].S) ) 
			dUnion(  dFind(e[j].F) , dFind(e[j].S)  ) ;
	return i - 1;
}


int main() { 
	cin >> n >> m;

	for(int i = 0 ; i < n ; i++ )
		par[i] = i;

	for(int i = 0 ; i < m ; i++ ) { 
		int x,y,w;
		cin >> x >> y >> w;
		x--; y--;
		e[i] = make_pair( make_pair(w, i) , make_pair(x,y));
	}

	sort( e, e + m ) ; 

	for(int i = 0 ; i < m ; i++ )
		i = proc(i);

	for(int i =0 ; i < m ; i++ ) 
		if( ans[i] == 0 ) 
			cout << "none" << endl;
		else if( ans[i] == 1 ) 
			cout << "at least one" << endl;
		else
			cout << "any" << endl;
}