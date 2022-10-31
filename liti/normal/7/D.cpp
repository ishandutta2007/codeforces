/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;
const ll base = 701;
const int maxN = 500*100*100 + 10;

int val[maxN];
int main() { 
	string s;
	cin >> s;

	ll c1 = 0 , c2 = 0 , z = 1;

	ll sum = 0 ;
	for( int i = 0 ; i < s.size() ; i++ ) { 
		c1 = c1*base + s[i] - 'a';
		c2 += z*(s[i]-'a');
		z*= base;

		if( c1 == c2 ) { 
			val[i] = val[(i-1)/2] + 1;
			sum += val[i];
		}
	}
	cout << sum << endl;
}