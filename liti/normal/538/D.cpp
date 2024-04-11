//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define SZ(x) ((int)(x).size())    
typedef long long ll    ;

const int maxN = 50 + 10; 

string ans[maxN*2];
string a[maxN];
int main() { 
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ) 
	cin >> a[i]; 

    for( int i = 0 ; i < 2*n - 1 ; i++ ) 
	for( int j = 0 ; j < 2*n - 1 ; j++ ) 
	    ans[i] += '.';
    ans[n-1][n-1] = 'o';
    for( int i = -(n-1) ; i <= n - 1 ; i++ ) 
	for( int j = -(n-1) ; j <= n - 1 ; j++ ) { 
	    if( i == 0 && j == 0 ) continue;
	    bool ch = true;
	    for( int x = 0 ; x < n ; x++ ) 
		for( int y = 0 ; y < n ; y++ ) 
		    if( a[x][y] == 'o' ) 
			if(!( x + i < 0 || x + i >= n || y + j < 0 || y + j >= n 
				|| a[x+i][y+j] != '.' ) )
			    ch = false;
	    if( ch ) { 
		ans[n-1 + i][n-1+j] = 'x';
		for( int x = 0 ; x < n ; x++ ) 
		    for( int y = 0 ; y < n ; y++ ) 
			if( a[x][y] == 'o' ) 
			    if(!( x + i < 0 || x + i >= n || y + j < 0 || y + j >= n 
					) && a[x+i][y+j] == 'x' )
				a[x+i][y+j] = 'y';
	    }
	}
    for( int i = 0 ; i <n ; i++ ) 
	for( int j =0 ; j < n ; j++ ) 
	    if( a[i][j] == 'x' ) {
		cout << "NO" << endl;
		return 0;
	    }
    cout << "YES" << endl;
    for( int i = 0 ; i < 2*n - 1 ; i++ ) 
	cout << ans[i] << endl;
}