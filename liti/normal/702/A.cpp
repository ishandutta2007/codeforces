//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

int main() { 
	ios::sync_with_stdio(false); 
	int n; cin >> n;
	int cnt = 0; 
	int mx = 1;
	int last ;
	for( int i = 0 ; i < n ; i++ ) { 
		int x; cin >> x; 
		if( !i || last >= x ) 
			cnt = 1; 
		else
			cnt++; 
		mx = max( mx , cnt ) ; 
		last = x; 
	}
	cout << mx <<endl;

}