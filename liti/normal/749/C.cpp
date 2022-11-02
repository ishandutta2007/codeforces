//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

int main() { 
	int n; cin >> n; 
	string s; cin >> s; 

	int dr = 0 , dd = 0; 
	while( s.size() > 1 ) { 
		int n = s.size(); 
		string t = "";
		for( int i = 0 ; i < n ; i++ ) 
			if( dr && s[i] == 'R' ) 
				dr--; 
			else if( dd && s[i] == 'D' ) 
				dd--; 
			else if( s[i] == 'R' ) { 
				t += 'R'; 
				dd++; 
			} else { 
				t += 'D'; 
				dr++; 
			}
		swap( t , s ); 
		if( s.size() == t.size() ) break;
	}
	cout << s[0] << endl;
}