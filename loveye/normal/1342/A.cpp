#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
signed main() {
	ios::sync_with_stdio(0);
	int t;cin >>t;
	while(t--) {
		int x,y,a,b;
		cin >>x >> y >> a >> b;
		if(a*2 <= b) cout << (x + y) * a << endl;
		else cout << min(x,y) * b + abs(x-y) * a << endl;
	}
	return 0;
}