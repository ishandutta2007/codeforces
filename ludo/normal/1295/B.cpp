#include<bits/stdc++.h>
using namespace std;

int calc(int n, int x, const string &s) {
	vector<int> c(n+1, 0);
	c[0] = 0;
	for (int i=0; i < n; i++) {
		c[i+1] = c[i] + (s[i] == '0' ? 1 : -1);
	}

	if (c[n] == 0) {
		for (int i=0; i <= n; i++)
			if (c[i] == x) return -1;
		return 0;
	}

	int ans = 0;
	for (int i=0; i < n; i++) {
		int diff = x - c[i];
		if (diff % c[n] != 0) continue;
		int q = diff / c[n];
		if (q >= 0)
			ans++;
	}
	return ans;
}

int main() {
	int ntc;
	cin >> ntc;
	while (ntc--) {
		int n, x;
		cin >> n >> x;
		string S;
		cin >> S;

		cout << calc(n,x,S) << endl;
	}
	return 0;
}