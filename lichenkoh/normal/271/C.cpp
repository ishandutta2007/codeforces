#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

int calc(int n, int k) {
	int *g = new int[n+1];
	for (int i = 0; i < n+1; i++) {
		g[i] = -1;
	}
	for (int i = 1; i <= k-1; i++) {
		assert(g[2*i-1] == -1 && g[2*i] == -1 && g[n-i] == -1);
		g[2*i-1] = i;
		g[2*i] = i;
		g[n-i] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (g[i] == -1) {
			g[i] = k;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << g[i] << " ";
	}
	cout << endl;
}

int main() {
	int n,k;
	cin >> n;
	cin >> k;
	if (n < 3*k) {
		cout << -1 << endl;
		return 0;
	}
	else {
		calc(n,k);
	}
	return 0;
}