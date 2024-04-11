//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 200*1000 + 10;
int a[maxN]; 
int main(){ 
	int n; 
	cin >> n;
	for( int i = 0 ;  i < n ;i++ ) {
		cin >> a[i]; 
		a[i] += i;
	}
	sort( a , a + n ) ; 
	for( int i = 0 ; i <n-1 ; i++ ) 
		if( a[i]==a[i+1] ) {
			cout << ":(" << endl;
			return 0;
		}
	for( int i =0 ;i  <n ; i++ ) 
		cout << a[i] - i <<  ' ' ; 
}