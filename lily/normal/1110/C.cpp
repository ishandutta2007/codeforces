#include <bits/stdc++.h>
using namespace std;



int main() {
/*	
	for (int i = 2; i <= 200; i++) {
		cout << i << " :  ";
		int ma = 1;
		for (int j = 1; j < i; j++) {
			if (__gcd(i ^ j, i & j) >= __gcd(i ^ ma, i & ma)) ma = j;
		}
		cout << ma << "(" << __gcd(i ^ ma, i & ma) << ")"<< endl;
	}
*/	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		int y = x, z = 0;
		while (y) {y>>= 1, z++;}
		if (x == (1 << z) - 1) {
			int ans = 1;
			for (int i = 2; i * i <= x; i++) {
				if (x % i == 0) {
					ans = max(ans, i);
					ans = max(ans, x / i);
				}
			}
			cout << ans << endl;
		}
		else cout << (1 << z) - 1 << endl;
	}

}