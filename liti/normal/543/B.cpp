//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 3000 + 10;
vector<int> c[maxN];

int n,m;
void bfs( int* d , int s ) { 
    vector<int> que; 
    que.push_back( s ) ; 
    d[s] = 1;
    for( int i = 0 ; i < sz(que) ; i++ ) { 
	s = que[i];
	for( auto x : c[s] ) if( d[x] == 0 ) { 
	    d[x] = d[s] + 1; 
	    que.push_back( x ) ; 
	}
    }
    for( int i = 0 ; i < n ; i++ ) 
	d[i]--;
}
int d[maxN][maxN];
int s1,t1,l1,s2,t2,l2;

int x[maxN];

int calc() { 
    int ans = m; 
    for( int i = 0 ; i < n ; i++ ) 
	for( int j = 0 ; j < n ; j++ ) 
	    if( d[s1][i] + d[i][j] + d[j][t1] <= l1 && 
		    d[s2][i] + d[i][j] + d[j][t2] <= l2 ) 
		ans = min( ans , d[s1][i] + d[s2][i] + d[i][j] + d[j][t1] + d[j][t2] );
    return m - ans;
}

int main() { 
    cin >> n >> m;
    for( int i = 0 ; i < m ; i++ ) { 
	int a , b; cin >> a >> b; 
	a--; b--; 
	c[a].push_back( b ) ; 
	c[b].push_back( a ) ; 
    }
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
    s1--; t1--; s2--; t2--;

    for( int i = 0 ; i < n ; i++ ) 
	bfs( d[i] , i ) ; 

    if( d[s1][t1] == -1 || d[s1][t1] > l1 || d[s2][t2] == -1 || d[s2][t2] > l2 ) { 
	cout<< -1 << endl;
	return 0;
    }

    int ret = max( m - ( d[s1][t1] + d[s2][t2] ) ,  calc() ) ;
    swap( t2 , s2 )  ;
    ret = max( ret , calc() ) ; 
    cout << ret << endl;
}