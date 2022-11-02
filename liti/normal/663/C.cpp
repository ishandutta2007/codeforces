//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    
typedef pair<int,int> pii; 
const int maxN = 100 * 1000 + 100; 

pii edge[maxN]; 
char t[maxN];
int par[maxN];

int dfind(int u ) { 
	return par[u] < 0 ? u : par[u] = dfind(par[u]); 
}
void merge( int u , int v ) { 
	u = dfind(u); v = dfind(v);
	if( u == v ) return; 
	if( (-par[u]<-par[v]) ) swap( u , v ); 
	par[u] += par[v];
	par[v] = u;
}

int n,m;
vector<int> c[maxN];
int mark[maxN];

int cnt1 , cnt2;
void dfs( int s , int co = 0 ) { 
	mark[s] = 1 + co; 
	if( co ) cnt2 += -par[s];
	else cnt1 += -par[s];
	for( auto x : c[s] ) if( !mark[x] ) 
		dfs( x , 1 - co ); 
}

int gg[maxN];
void dpr( int s , int good , int co = 0 ) { 
	mark[s] = 3 + co; 
	if( good == co ) gg[s] = true; 
	for( auto x : c[s] ) if( mark[x] < 3 ) 
		dpr( x , good , 1 - co ); 
}

int solve( char ch , bool pr = 0 ) { 
	memset( par , -1 , sizeof par ); 
	for( int i = 0 ; i < m ; i++ ) 
		if( t[i] == ch ) 
			merge( edge[i].first , edge[i].second );
	for( int i = 0 ; i < n ; i++ ) c[i].clear();
	for( int i = 0 ; i < m ; i++ ) 
		if( t[i] != ch ) { 
			int u = dfind(edge[i].first) , v = dfind(edge[i].second);
			if( u == v ) return maxN;
			c[u].push_back(v);
			c[v].push_back(u); 
		}
	memset( mark , 0 , sizeof mark );
	int ans = 0; 
	for( int i = 0 ; i < n ; i++ ) 
		if( !mark[i] && par[i] < 0 ) { 
			cnt1 = cnt2 = 0;
			dfs( i ); 
			ans += min(cnt1,cnt2); 
			if( pr ) {
				if( cnt1 < cnt2 ) 
					dpr( i , 0 );
				else
					dpr( i , 1 ); 
			}
		}
	for( int i = 0 ; i < n ; i++ ) 
		for( auto x : c[i] ) 
			if( mark[i] == mark[x] ) return maxN;

	if( pr ) { 
		cout << ans << endl;
		for( int i = 0 ; i < n ; i++ ) 
			if( gg[dfind(i)] ) cout << i + 1 << ' ' ; 
		cout << endl;
	}
	return ans;
}

int main() { 
	 cin >> n >> m;
	for( int i = 0 ; i < m ; i++ ) { 
		cin >> edge[i].first >> edge[i].second >> t[i]; 
		edge[i].first--;
		edge[i].second--;
	}
	char B = 'B', R = 'R';
	int a = solve(B);
	int b = solve(R);
	if( a == b && b == maxN ) cout << -1 << endl;
	else if( a < b ) solve( B , 1 ); 
	else solve( R , 1 ); 
}