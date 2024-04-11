//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 1000 + 20;
vector<int> c[maxN]; 
int h[maxN];
int ans[maxN];
int col[maxN];
int cnt;

int main() { 
    int n,m; 
    cin >> n >> m; 
    for( int i = 0 ; i < m ; i++ ) { 
	int a,b; cin >> a >> b; 
	a--; b--; 
	c[a].push_back( b ) ; 
	c[b].push_back( a ) ; 
    }

    vector<int> que;
    for( int i = 0 ; i < n ; i++ ) if( h[i] == 0 ) { 
	h[i] = 1; 
	col[i] = cnt; 
	que.clear();
	que.push_back( i ) ; 
	for( int j = 0 ; j < sz(que) ; j++ ) { 
	    int s = que[j];
	    for( auto x : c[s] ) if( h[x] == 0 ) { 
		h[x] = h[s] + 1; 
		col[x] = cnt;
		que.push_back( x ) ; 
	    }
	}
	cnt++; 
    }
    for( int s = 0 ; s <n ; s++ ) 
	for( auto x : c[s] ) 
	    if( h[s] == h[x] ) { 
		cout << -1 << endl;
		return 0; 
	    }
    memset( h , 0 , sizeof h ) ; 
    for( int i = 0 ; i < n ; i++ ) {
	int mx = 1;
	h[i] = 1; 
	que.clear();
	que.push_back(i) ; 
	for( int j = 0 ; j < sz(que) ; j++ ) { 
	    int s = que[j];
	    for( auto x : c[s] ) if( h[x] == 0 ) { 
		h[x] = h[s] + 1; 
		mx = max( mx , h[x] ) ; 
		que.push_back( x ) ; 
	    }
	}
	for( int j = 0 ; j < sz(que) ; j++ ) 
	    h[que[j]] = 0 ;
	ans[col[i]] = max( ans[col[i]] , mx - 1 ) ; 
    }
    int ret=0; for( int i = 0 ; i < cnt ; i++ ) ret += ans[i];
    cout << ret << endl;
}