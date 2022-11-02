//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 1000*100 + 10; 
vector<int> c[maxN];
vector<int> que;
int a[maxN];

int main() { 
	int n,m; 
	cin >> n >> m; 
	for( int i =0 ; i < m ; i++ ) { 
		int a,b; cin >> a >> b; a--; b--;
		c[a].push_back( b ) ; 
		c[b].push_back( a ) ; 
	}
	for( int i = 0 ; i < n ; i++ ) {
		cin >> a[i];
		if( a[i] == 0 ) 
			que.push_back( i ) ; 
	}
	for( int i = 0 ; i < __sz(que) ; i++ ) { 
		int s = que[i];
		for( auto x : c[s] ) { 
			a[x]--; 
			if( a[x] == 0 ) 
				que.push_back( x ) ; 
		}
	}
	cout << __sz(que) << endl;
	for( int i = 0 ; i < __sz(que) ; i++ ) 
		cout << que[i] + 1 << ' ';
	cout << endl;
}