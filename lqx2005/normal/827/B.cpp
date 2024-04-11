#include <bits/stdc++.h>

using namespace std;
int n, k, tot = 1;
int main() {
	cin >> n >> k;
	int t = (n - 1) / k, d = (n - 1) % k;
	cout << t * 2 + (!!d) + (d > 1) << endl;
	for(int i = 1; i <= k; i++) {
		cout << 1 << " " << tot + 1 << endl, tot++;
		for(int j = 1; j <= t - 1; j++) {
			cout << tot <<" " << tot + 1 << endl, tot++;
		}
		if(i <= (n - 1) % k) cout << tot <<" " << tot + 1 << endl, tot++;
	}
	return 0;
}