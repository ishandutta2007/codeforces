#include<bits/stdc++.h>
using namespace std;
double a,b,m,c;
double f(int x) {
	return a / (2*x-1);
}
int main() {
	ios::sync_with_stdio(0);
	int t;cin >> t;
	while(t--) {
		cin >> a >> b >> c;
		if(a == c) {
			cout << 1 << endl;
			continue;
		}
		m = (a + b) / 2.;
		if(m >= c) {
			cout << 2 <<endl;
			continue;
		}
		c -= m;a -= m;
		int l = 2,r = 1e6;
		while(l < r) {
			int mid = l + r >> 1;
			if(f(mid) > c) l = mid+1;
			else r = mid;
		}
		if(fabs(f(l-1) - c) <= fabs(f(l) - c) && fabs(f(l-1) - c) <= fabs(f(l+1) - c)) cout << (l-1)*2-1 << endl;
		else if(fabs(f(l) - c) <= fabs(f(l-1) - c) && fabs(f(l) - c) <= fabs(f(l+1) - c)) cout << l*2-1 << endl;
		else cout << (l+1)*2-1 << endl;
	}
	return 0;
}
//(a-c)*x + (b-c)*y == 0