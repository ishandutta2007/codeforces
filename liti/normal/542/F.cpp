//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxT = 100 + 10; 
vector<int> h[maxT];
int main() { 
    int n,t;
    cin >> n>> t;

    for( int i = 0 ; i < n ; i++ ) { 
	int x,y; cin >> x >> y; 
	h[t-x].push_back( y ) ; 
    }
    for( int i = t - 1 ; i >= 0 ; i-- ) { 
	int x = min( i , 30 ) ; 
	sort( h[i].begin() , h[i].end() , greater<int>() ) ; 
	while( sz(h[i]) > (1<<x) ) 
	    h[i].pop_back();
	if( h[i].size() % 2 == 1 ) h[i].push_back( 0 ) ; 
	if( i > 0 ) 
	    for( int j = 0 ; j < sz(h[i]) ; j+= 2 ) 
		h[i-1].push_back( h[i][j] + h[i][j+1] ) ; 
    }
    cout << h[0][0] << endl;
}