//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

string s[2] = { "Stannis" , "Daenerys" } ; 
int main() { 
	int a[2] = {0,0}; 
	int n,k; cin >> n >> k; 
	for( int i = 0 ;i < n ; i ++ ) { 
		int num ; cin >> num; 
		a[num&1]++; 
	}
	// Dean Win if a[1] & 1 else Stan
	k = n - k; 

	bool ans = 1; 
	if( k == 0 ) 
		ans = 1^(a[1]&1); 
	else if( (k+1)/2 >= a[0] && ((n-k) & 1) ) 
		ans = 0;
	else if( k/2 >= a[1] || ( k/2 >= a[0] && ((n-k)&1) == 0 ) ) 
		ans = 1; 
	else if( k & 1 ) 
		ans = 0;
	else
		ans = 1;
	cout << s[ans] << endl;
}