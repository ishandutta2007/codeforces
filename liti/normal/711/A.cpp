//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxN = 1000 + 10; 
string s[maxN]; 

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n; 
	bool done = false; 
	for( int i = 0 ; i < n ; i++ ) { 
		string s; 
		cin >> s; 
		if( !done ) { 
			if( s[0] == 'O' && s[1] == 'O' ) 
				s[0] = '+' , s[1] = '+' , done = true; 
			else if( s[3] == 'O' && s[4] == 'O' ) 
				s[3] = '+' , s[4] = '+' , done = true; 
		}
		::s[i] = s;
	}
	if( done ) { 
		cout << "YES" << endl;
		for( int i = 0 ; i < n ; i++ ) 
			cout << s[i] << endl;
	} else
		cout << "NO" << endl;
	
}