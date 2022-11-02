/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

int a[256];
int main() { 
	int n;
	cin >> n; 
	n--; 
	int ans =0;
	for( int i = 0 ; i < n ; i++ ) { 
		char ch; cin >> ch; 

		a[ch]++;
		cin >> ch; ch = tolower(ch) ; 
		if( a[ch] ) 
			a[ch]--;
		else
			ans++;
	}
	cout << ans << endl;
}