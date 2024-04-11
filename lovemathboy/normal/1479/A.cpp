#include <bits/stdc++.h>
using namespace std;

int query(int x) {
	printf("? %d\n", x);
	fflush(stdout);
	int in;
	scanf("%d", &in);
	return in;
}

int main() {
	int l, r, n;
	scanf("%d", &n);
	l = 1, r = n;
	while (l <= r - 5) {
		int dif = (r - l)/3;
		int v1 = query(l + dif), v2 = query(r - dif);
		if (v1 > v2) {
			l = l + dif;
		}
		else {
			r = r - dif;
		}
	}
	vector<int> a;
	a.push_back(1e9);
	for (int i = l; i <= r; i++) {
		a.push_back(query(i));
	}
	a.push_back(1e9);
	int ans = 0;
	for (int i = 1; i < a.size() - 1; i++) {
		if (a[i] < a[i-1] && a[i] < a[i+1]) {
			ans = l+i-1; 
			break;
		}
	}
	printf("! %d\n", ans);
	fflush(stdout);
	return 0;
}