/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

int main() { 
	int h;
	cin >> h;
	ll n;
	cin >> n;
	n--;
	ll ret =0;
	ret = h;
	int x = 0;
	for( int i = 0 ; i < h ; i++ ) { 
//		cout << i << ' ' << ret << endl;
		if( x != ((n>>(h-i-1)) & 1) ) 
			ret += (1ll<<(h-i)) - 1 ;
		x = 1 - ((n>>(h-i-1)) & 1);
	}
	cout << ret << endl;
}