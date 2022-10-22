#include <bits/stdc++.h>
using namespace std;

int n;
char s[200005], rev[200005];
queue<int> occ[30];
int arr[200005];
long long ans;

int fw[200005];
void update(int p, int v) {
	for (; p <= n; p += p&-p) fw[p] += v;
}
int query(int p) {
	int res = 0;
	for (; p > 0; p -= p&-p) res += fw[p];
	return res;
}
int query(int a, int b) {
	return query(b) - query(a - 1);
}

int main() {
	scanf("%d", &n);
	scanf(" %s", s);
	strcpy(rev, s);
	reverse(rev, rev + n);
	for (int i = 0; i < n; i++) {
		occ[rev[i] - 'a'].push(i + 1);
	}
	for (int i = 0; i < n; i++) {
		arr[i] = occ[s[i] - 'a'].front();
		occ[s[i] - 'a'].pop();
	}
	for (int i = 0; i < n; i++) {
		ans += query(arr[i], n);
		update(arr[i], 1);
	}
	printf("%lld\n", ans);
	return 0;
}