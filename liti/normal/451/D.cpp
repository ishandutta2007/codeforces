#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() { 
	string s;
	cin >> s;


	ll a , b; a = b = 0;

	for(int t =  0 ; t < 2 ; t++ ) {
		ll c1 =0, c2 = 0;

		for(int i = 0 ; i < s.size() ; i++) {
			if( s[i] == 'a' ) {
				c1++;
				a += c1 , b += c2;
			}
			swap( c1, c2 ) ; 
		}
		for(int i = 0 ; i < s.size() ; i++) 
			s[i] = ( 'b' - s[i] ) + 'a';
	}

	cout << b << ' ' << a << endl;
}