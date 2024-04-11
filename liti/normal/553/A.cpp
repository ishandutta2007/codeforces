//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 1000 + 10;
const int mod = 1e9 + 7; 

int a[maxN];
int ch[maxN][maxN];
int main() { 
	int n; cin >> n;
	int rem = 0;
	for( int i = 0 ; i < n ; i++ ){
		cin >> a[i];
		rem += a[i]; 
	}
	ch[0][0] = 1; 
	for( int i = 1 ; i < maxN ; i++ ) 
		for( int j = 0 ; j < maxN ; j++ ) 
			ch[i][j] = ( ( j ? ch[i-1][j-1] : 0 ) + ch[i-1][j] ) % mod; 
	int ret = 1; 
	for( int i = n - 1 ;i >= 0 ; i-- ) { 
		ret = ret * 1ll * ch[rem-1][a[i]-1] % mod; 
		rem -= a[i]; 
	}
	cout << ret << endl;
}