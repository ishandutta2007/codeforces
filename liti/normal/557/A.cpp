//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

int main() { 
	int n; 
	cin >> n; 
	int mn[3] , mx[3], ans[3]; 
	for( int i = 0 ; i < 3 ; i++ ) 
		cin >> mn[i] >> mx[i]; 
	int sum = mn[1] + mn[2]; 
	int k = ( n - sum ) ; 
	cout << min( k , mx[0] ) << ' '; 
	n -= min( k , mx[0] ) ; 

	sum = mn[2];
	k = ( n - sum ); 
	cout << min( k , mx[1] ) << ' ' ;
	n -= min( k , mx[1] ) ; 
	cout << n << endl;


}