/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 100000 + 10 ;

int cnt1[256] , cnt2[256];

int main() { 
	string s,t;
	cin >> s  >> t;
	for( int i = 0 ; i < sz(s) ; i++ ) 
		cnt1[s[i]]++;
	for( int i = 0 ; i < sz(t) ; i++ ) 
		cnt2[t[i]]++; 

	int a = 0 ; 
	for( int i = 0 ; i < 256 ; i++ ) { 
		int x = min(cnt1[i] , cnt2[i] ) ; 
		a += x; 
		cnt1[i] -= x;
		cnt2[i] -= x;
	}

	cout << a << ' ' ;

	a = 0;
	for( int i = 0 ; i < 256 ; i++ ) { 
		if( isalpha( i ) ) { 
			int j = tolower(i);
			int k = toupper(i); 
			if( j == i ) 
				swap( k , j ) ; 
			int x = min( cnt1[j] , cnt2[k] ) ; 
			a += x;
		}
	}
	cout << a << endl;
}