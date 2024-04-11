/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;
typedef long double ld;

const int maxN = 5*1000*100;
ld sum[maxN];

ld gg( int i, int j ) { 
	return sum[j] - (i?sum[i-1]:0);
}
bool isGood( char ch ) { 
	if( ch == 'I' || ch == 'E' || ch == 'A' || ch == 'O' 
			|| ch == 'U' || ch == 'Y' ) 
		return true;
	return false;
}

int main() { 
	string s; cin >> s;
	int n = sz(s);
	for( int i = 1 ; i <= n ; i++ ) 
		sum[i] = sum[i-1] + 1/ld(i);

	ld curr = gg(1,n);
	ld ret = 0;
//	cerr << curr << endl;
	if( isGood( s[0] ) ) ret += curr;
	for( int i = 1 ; i < n ; i++ ) {
		int x = n - i + 1;
		int y = i;
		curr -= gg(x,x+y-1);
//		cerr << 'X' << curr << endl;
		curr += gg(y+1,x+y-1);
//		cerr << curr << endl;
		if( isGood(s[i]) ) ret += curr;
	}

	cout << fixed << setprecision(9);
	cout << ret << endl;
}