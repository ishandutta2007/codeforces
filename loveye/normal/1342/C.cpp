#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,q,x,y,_;
int gcd(int x,int y) {
	return !y ? x : gcd(y,x % y);
}
inline int solve(int n) {
	if(n == 0) return 0;
	return n / _ * (_ - b) + max(n % _ - b + 1,0ll);
}
signed main() {
	ios::sync_with_stdio(0);
	int t;cin >> t;
	while(t--) {
		cin >> a >> b >> q;
		if(a > b) swap(a,b);
		_ = a / gcd(a,b) * b;
		while(q--) {
			cin >> x >> y;
			cout <<solve(y) - solve(x-1) << ' ';
		}
		cout << endl;
	}
	return 0;
}