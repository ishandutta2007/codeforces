//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

int main() { 
	int n; 
	cin >> n;
	int cnt = 0; 
	int last = 0, ans = 0;
	for( int i = 0 ; i < n ; i++ ) { 
		int x; cin >> x; 
		if( i && x < last ) cnt = 0;
		cnt++; 
		ans = max(ans,cnt);
		last = x;
	}
	cout << ans << endl;
}