/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int mod = 1e9 + 7;

map<char,int> cnt;
int tav( int a , int b ) { 
	int res = 1; 
	while( b ) { 
		if( b % 2 == 1 ) 
			res = res*1ll*a % mod;
		b /= 2;
		a = a * 1ll * a % mod;
	}
	return res;
}
int main() { 
	int n;
	string s;
	cin >> n >> s;

	for( int i = 0 ; i < n ; i++ ) 
		cnt[s[i]]++;

	int best = 0 , bestCnt = 0;
	for( auto it : cnt ) {
		if( it.second > best ) 
			best = it.second, bestCnt = 0;
		if( it.second >= best ) 
			bestCnt++;
	}
	cout << tav( bestCnt , n ) << endl;
}