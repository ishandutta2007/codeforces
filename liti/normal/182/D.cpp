/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 100*100*10 + 10;
string s1,s2;

int cnt[maxN];

bool calc( int i ) {
	string a =s1.substr( 0 , i ) ;
	string ra = "";
	for( int j = 0 ; j <  s1.size() / i ; j++ ) 
		ra += a;
	string rb = "";
	for( int j = 0 ; j <  s2.size() / i ; j++ ) 
		rb += a;
	if( ra == s1 && rb == s2 ) 
		return true;
	return false;
}

int main() { 
	for( int i = 1 ; i < maxN ; i++ ) 
		for( int j = i ; j < maxN ; j+= i ) 
			cnt[j]++;
	cin >> s1 >> s2;

	for( int i = 1 ; i <= (int) __gcd( s1.size() , s2.size() ) ; i++ ) 
		if(  __gcd( s1.size() , s2.size() )  % i == 0 && 
				calc(i) ) {
			cout << cnt[__gcd( s1.size() , s2.size() ) / i] << endl;
			return 0;
		}
	cout << 0 << endl;
}