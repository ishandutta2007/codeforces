//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	string s; cin >> s; 
	int n = s.size(); 
	bool st = false; 
	for( int i = 0 ; i < n ; i++ ) 
		if( s[i] == 'a' ) {
			if( st ) break; 
		} else { 
			st = true; 
			s[i]-=1; 
		} 
	if( !st ) s[n-1] = 'z';  
	cout << s << endl;

}