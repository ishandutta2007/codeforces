//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

int a[5000] ;
int main() { 
	int n; 
	cin >> n; 
	for( int i = 0 ; i < n ;i++ ) 
		cin >> a[i]; 
	for( int i = 0 ; i < n ; i++ ) { 
		int cnt = 1; 
		for( int j = 0 ; j < n ; j++ ) if( a[j] > a[i] ) cnt++; 
		cout <<cnt << ' ' ; 
	}
	cout << endl;
}