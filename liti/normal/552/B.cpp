//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

int main() { 
	int n; 
	cin >> n; 
	int cnt = 9; 
	ll ans =0 ;
	for( int i = 1 ; i <= 10 ; i++ ) { 
		ans += i *1ll* min( n , cnt ) ; 
		n -= min( n , cnt ) ; 
		cnt *= 10; 
	}
	cout << ans << endl;
}