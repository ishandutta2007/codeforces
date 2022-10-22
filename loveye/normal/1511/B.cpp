#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,a,b,c;
inline int pw(int x) {
	int res = 1;
	while(x--) res *= 10;
	return res;
}
signed main() {
	cin >> T;
	while(T--) {
		cin >> a >> b >> c;
		if(a <= b) cout << pw(a-1) << ' ' << (pw(b-1) + pw(c-1)) << endl;
		else cout << (pw(a-1) + pw(c-1)) << ' ' << pw(b-1) << endl;
	}
	return 0;
}