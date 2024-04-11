//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 100;
string a[maxN];
int main() { 
	int n,m; 
	cin >> n >> m; 
	for( int i = 0 ; i < n ;i++ ) 
		cin >> a[i];
	string x = "face" ; sort( x.begin() , x.end() ) ; 
	int ans = 0;
	for( int i = 0 ; i < n - 1 ; i++ ) 
		for( int j= 0 ; j < m -1 ; j++ ) { 
			string s = ""; 
			s += a[i][j]; s += a[i+1][j]; 
			s += a[i][j+1] ; s += a[i+1][j+1]; 
			sort(s.begin(),s.end());
			if( s == x ) 
				ans++;
		}
	cout<< ans << endl;
}