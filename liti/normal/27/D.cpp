//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 100 * 1000 + 100; 
typedef pair<int,int> pii; 
pii a[maxN]; 

vector<int> c[2*maxN]; 
int scc[maxN]; 
int lo[maxN], st[maxN]; 
int que[maxN], en; 
int mark[maxN]; 

int cnt; 

int tmp[maxN]; 
int n,m;

int gg( pii a , pii b ) { 
	memset( tmp , 0 , sizeof tmp ); 
	int i = a.first-1; 
	if( a.first == b.first || a.first == b.second || 
			a.second == b.second || a.second == b.first ) 
		return false; 
	do { 
		i = ( i + 1 ) % n; 
		tmp[i] = 1; 
	} while( i != a.second ) ; 
	return tmp[b.first] != tmp[b.second]; 
}

vector<int> ans; 

int tarjan( int s ) { 
	static int ind = 0; 
	st[s] = lo[s] = ind++; 
	que[en++] = s; 
	mark[s] = 1; 
	for( auto x : c[s] ) 
		if( !mark[x] ) 
			lo[s] = min( lo[s] , tarjan( x ) ); 
		else if( mark[x] == 1 ) 
			lo[s] = min( lo[s] , st[x] ) ; 

	if( lo[s] == st[s] ) { 
		do { 
			int x = que[--en]; 
			mark[x] = 2; 
			scc[x] = cnt; 
			ans.push_back( x ); 
		} while( que[en] != s ); 
		cnt++; 
	}
	return lo[s]; 
}

int ret[maxN]; 
int main() { 
	cin >> n >> m;

	for( int i = 0 ; i < m ; i++ ) { 
		cin >> a[i].first >> a[i].second; 
		a[i].first--; a[i].second--; 

		for( int j = 0 ; j < i ; j++ ) 
			if( gg(a[i],a[j]) ) { 
				c[i*2].push_back( j * 2 + 1 ); 
				c[j*2+1].push_back( i * 2 ); 
				c[j*2].push_back( i * 2 + 1 ); 
				c[i*2+1].push_back( j * 2 ); 
			}
	}

	for( int i = 0 ; i < 2*m ; i++ ) 
		if( !mark[i] ) 
			tarjan(i); 

	for( int i = 0 ; i < 2 * m ; i += 2 ) 
		if( scc[i] == scc[i^1] ) { 
			cout << "Impossible" << endl;
			return 0; 
		}
	memset( mark , 0 , sizeof mark ); 
	for( auto x : ans ) 
		if( !mark[x/2] ) { 
			mark[x/2] = 1; 
			ret[x/2] = x % 2; 
		}

	for( int i = 0 ; i < m ; i++ ) 
		cout << (ret[i]?"i":"o") ; 
	cout << endl;
}