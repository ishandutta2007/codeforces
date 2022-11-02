/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 2000*100 + 100;

int cnt[maxN];
int main() { 
	string s;
	cin >> s;

	int m; cin >> m; 
	for( int i = 0 ; i < m ; i++ ) { 
		int num;
		cin >> num;
		cnt[num-1]++; 
	}
	int n = sz(s);
	for( int i = 0 ; i + i < n ; i++ ) {
		if( i ) cnt[i] += cnt[i-1]; 
		if( cnt[i] & 1 ) 
			swap( s[i] , s[n-i-1] ) ; 
	}
	cout << s << endl;
}