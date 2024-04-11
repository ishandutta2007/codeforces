/* In the name of Allah */
#include <iostream>
#include <cstdlib> 
using namespace std;

const int maxN = 200*100*10 + 10;

int st[maxN] , en[maxN];
int cnt[26];

void die() { 
	cout << "No" << endl;
	exit(0);
}

int main() {
	string s;
	string t;

	cin >> s >> t;

	int n = s.size() , m = t.size() ;

	int cnt = 0;
	for( int i = 0 ; i < n ; i++ ) {
		if( cnt == m )
			break;
		if( t[cnt] == s[i] ) 
			st[cnt++] = i;
	}
	if( cnt != m )
		die();

	cnt = m - 1;
	for( int i  = n - 1 ; i >= 0 ; i-- ) {
		if( cnt == -1 ) 
			break;
		if( t[cnt] == s[i] ) 
			en[cnt--] = i + 1;
	}

	for( int i = 0 ; i < m ; i++ ) {
		int id = t[i] - 'a';
		for( int j = ::cnt[id] ; j < st[i] ; j++ )  
			if( t[i] == s[j] ) 
				die();
		::cnt[id] = en[i];
	}
	for( int i = 0 ; i < n ; i++ ) 
		if( ::cnt[ s[i] - 'a' ] < i )
			die();
	cout << "Yes" << endl;
}