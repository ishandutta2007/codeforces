#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int t, n, m, p;
	cin >> t;
	while(t--) {
		int minimum = 1000, sum = 0, n_count = 0;
		cin >> n >> m;
		for(int i = 0; i < n*m; i++) {
			cin >> p;
			if(p < 0) {
				p = -p;
				n_count++;
			}
			minimum = min(p, minimum);
			sum += p;
		}
		if(n_count % 2)sum -= 2*minimum;
		cout << sum << '\n';
	}
	return 0;
}