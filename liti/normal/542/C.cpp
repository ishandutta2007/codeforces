//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 200 + 10;
int a[maxN];
int b[maxN];
ll check[maxN];
int main() { 
    int n; 
    cin >> n; 
    for( int i = 1 ; i <= n ; i++ ) 
	cin >> a[i]; 
    ll ans = 1; 
    ll mx = 1 ; 

    for( int i = 1 ; i <= n ; i++ ) { 
	memset( check , 0 , sizeof check ) ; 
	check[i] = 1; 
	int x = i;
	int cnt = 1;
	while( !check[a[x]] ) { 
	    x = a[x];
	    check[x] = ++cnt;
	}
	if( a[x] == i ) {
//	    cout << "D " << i << ' ' << check[x] << endl;
	    ans = ans * check[x] / __gcd( ans, check[x] ) ;
	}
	else { 
//	    cout << i << ' ' << check[a[x]] << endl;
	    mx = max( mx , check[a[x]] - 1 ) ; 
	}
    }

    cout << ( mx + ans - 1 ) / ans * ans << endl;
}