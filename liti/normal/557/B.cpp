//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    
typedef long double ld; 

const int maxN = 2 * 100 * 1000 + 10;
int a[maxN]; 
int main() { 
	int n,m; 
	cin >> n >> m; 
	for( int i = 0 ; i < 2 * n ; i++ ) 
		cin >> a[i]; 
	sort( a ,a + 2 * n ) ; 
	ld mn = min( a[0] * 1.0 , a[n] / 2.0 ) ; 
	mn = min( mn , m / ld( n * 3 ) ) ; 
	cout << fixed << setprecision(9)  <<  n * mn * 3 << endl;
}