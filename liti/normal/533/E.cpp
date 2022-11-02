/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

int main() {
	int n;
	cin >> n;
	string s,t;
	cin >> s >> t; 

	if( s == t ) { 
		return 1;
	} else { 
		int prefLen = 0;
		int sufLen = 0;
		while( s[sufLen] == t[sufLen] ) 
			sufLen++; 
		while( s[n-prefLen-1] == t[n-prefLen-1] ) 
			prefLen++;
		if( sufLen + prefLen + 1 == n )  
			cout << 2 << endl;
		else { 
			int cnt = 0; 
			int len = n - (sufLen + prefLen + 1);
		//	cerr << sufLen << ' ' << prefLen << ' ' << len << endl;
			if( s.substr( sufLen , len ) 
					== t.substr( sufLen + 1 , len ) )
				cnt++;
			if( t.substr( sufLen , len ) 
					== s.substr( sufLen + 1 , len) )
				cnt++;
			cout << cnt << endl;
		}
	}
}