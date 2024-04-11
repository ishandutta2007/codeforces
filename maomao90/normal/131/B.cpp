#include <bits/stdc++.h>
using namespace std;

int n;
int t[100005];
map <int, int> mp;
int zero;
long long ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t[i]);
		if (t[i] < 0) mp[-t[i]]++;
		if (t[i] == 0) zero++;
	}
	for (int i = 0; i < n; i++) {
		if (t[i] == 0) ans += --zero;
	}
	for (int i = 0; i < n; i++) {
		if (t[i] > 0) ans += mp[t[i]];
	}
	printf("%lld\n", ans);
	return 0;
}