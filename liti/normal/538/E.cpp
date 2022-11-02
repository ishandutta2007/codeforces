//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define SZ(x) ((int)(x).size())    
typedef long long ll;

const int maxN = 2000*100 + 100; 
vector<int> c[maxN];
int sz[maxN];
int dsz( int s , int p = -1  ) { 
    sz[s] = 1;
    for( auto x : c[s] ) if( x != p ) 
	sz[s] += dsz( x , s ) ; 
    return sz[s];
}
int n ; 

int dfs1( int s , int p = -1 , int h = 0 ) { 
 //   cout << s << ' ' << p << ' ' << h << endl;
    if( n == 1 || ( s != 0 && c[s].size() <= 1 )  ) 
	return 1;
    if( h == 0 ) { 
	int mn = maxN;
	for( auto x : c[s] ) if( x != p ) mn = min(mn,dfs1(x,s,h^1)) ; 
	return mn;
    } else { 
	int ret = 0;
	for( auto x : c[s] ) if( x != p )
	    ret += dfs1( x , s , h ^ 1 ) ; 
//	cout << s + 1 << ' ' << ret << endl;
	return ret;
    }
}
int dfs2( int s , int p = -1 , int h = 0 ) { 
    if(  n == 1 || ( s != 0 && c[s].size() <= 1 ) ) 
	return 1;
    if( h == 1 ) { 
	int mn = maxN;
	for( auto x : c[s] ) if( x != p ) mn = min( mn , dfs2(x,s,h^1) ) ; 
	return mn;
    } else { 
	int ret = 0;
	for( auto x : c[s] ) if( x != p )
	    ret += dfs2( x , s , h ^ 1 ) ; 
//	cout << s + 1 << ' ' << ret << endl;
	return ret;
    }

}

int main() { 
    cin >> n;
    for( int i = 0 ; i < n  - 1 ; i++ ) {
	int a,b;
	cin>> a >> b;
	a--; b--; 
	c[a].push_back( b ) ; 
	c[b].push_back( a ) ; 
    }
    int m = 0;
    for( int i = 1 ; i < n ; i++ ) 
	if( c[i].size() <= 1 ) 
	    m++; 
    if( n == 1 ) 
	m++;

    dsz( 0 ) ;

    cout << m - dfs1(0) + 1 << ' ' << dfs2(0) << endl;
}