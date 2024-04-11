//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

#define __sz(x) ((int)(x).size())
typedef long long ll; 

const int maxN = 200 + 10;

int dx[maxN],dy[maxN];
int main() { 
	int n; cin >> n; 
	string s; cin >> s;
	int x = 0, y = 0;	
	for( int i = 0 ; i < n ; i++ ) { 
		if( s[i] == 'L' ) 
			x--; 
		if( s[i] == 'R' ) 
			x++; 
		if( s[i] == 'U' ) 
			y++; 
		if( s[i] == 'D' ) 
			y--; 
		dx[i+1] = x; 
		dy[i+1] = y; 
	}
	int ans = 0; 
	for( int i = 0 ; i < n ; i++ ) 
		for( int j = i + 1 ; j <= n ; j++ ) 
			if( dx[i] == dx[j] && dy[i] == dy[j] ) 
				ans++; 
	cout << ans << endl;
}