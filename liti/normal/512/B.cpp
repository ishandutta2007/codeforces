/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

map<int,int> ans;

const int maxN = 300 + 10;
int a[maxN],c[maxN];
void smax( int& a , int b ) { 
	if( a == 0 ) a = b;
	else if( a > b ) a = b;
}

int main() { 
	int n;
	cin >> n;
	for( int i = 0 ; i < n ; i++ )
		cin >> a[i];
	for( int i= 0 ;i < n ; i++ ) 
		cin >> c[i];
	for( int i = 0 ;i  < n ; i++ ) { 
		smax( ans[a[i]] , c[i] ) ; 
		for( auto& it : ans ) 
			smax( ans[__gcd(it.first,a[i])] , it.second + c[i] ) ;
	}
	cout << (ans[1] == 0 ? -1 : ans[1] ) << endl;
}