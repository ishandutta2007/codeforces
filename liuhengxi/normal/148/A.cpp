#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	
	int a, b, c, d, e, ans = 0;
	cin >> a >> b >> c >> d >> e;
	for(int i = 1; i<= e; i ++) {
		if(i % a == 0 || i % b == 0 || i % c == 0 || i % d == 0) ans ++;
	}
	cout << ans << endl;

	return 0;

}