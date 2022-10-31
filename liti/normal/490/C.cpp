/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 1000*1000 + 10;
string s;

int a[maxN], b[maxN];
int tav[maxN];
int main() { 
	cin >> s;
	int x,y;
	cin >> x  >> y;

	tav[0] = ( 1 ) % y;
	for( int i = 1 ; i < maxN ; i++ ) 
		tav[i] = ( 10 * tav[i-1] ) % y;

	s = 'x' + s; 
	for( int i = 1 ; i < sz( s ) ; i++ ) { 
		int d = s[i] - '0';
		a[i] = ( a[i-1]*10 + d ) % x ; 
	}
	for( int i = sz(s) - 1 ; i > 1 ; i-- ) { 
		int d = s[i] - '0';
		b[i] = ( b[i+1] + tav[sz(s) - 1 - i] * d ) % y;

//		cout << a[i-1] << ' ' << b[i] << endl;
		if( b[i] == 0 && d != 0 && a[i-1] == 0 ) { 
			cout << "YES" << endl;
//			cout << i << endl;
			cout << s.substr( 1 , i - 1 ) << endl << s.substr( i , sz(s) - i ) << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}