#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll read() {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 1000010;
int n;
ll u, ans, a[maxn], f[maxn], s1[maxn], s2[maxn];
#define sum(l,r,s) (s[r] - s[l - 1])

int main() {
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read(), s1[i] = s1[i - 1] + a[i], s2[i] = s2[i - 1] + (a[i] ^ 1);
	u = 0;
	for (int i = 1; i <= n; i++)
		if (a[i])
			u += sum(i + 1, n, s2);
	ans = u + 1 - 1;
	u = 0;
	for (int i = n; i >= 1; i--)
		if (a[i])
			u += sum(1, i - 1, s1) + sum(i + 1, n, s2);
	ans = min(u, ans);
//	cout << u << endl; 
	u = 0;
	for (int i = 1; i <= n; i++)
		if (!a[i])
			u += sum(1, i - 1, s1) + sum(i + 1, n, s2);
	ans = min(u, ans);
//	cout << u << endl; 
	u = 0;
	for (int i = n; i >= 1; i--)
		if (!a[i])
			u += sum(1, i - 1, s1);
	ans = min(u, ans);
//	cout << u << endl;
	u = 0;
	for (int i = 1; i <= n; i++)
		u += sum(i + 1, n, s2);
	ans = min(u, ans);
//	cout << u << endl;
	u = 0;
	for (int i = n; i > 0; i--)
		u += sum(1, i - 1, s1);
	ans = min(u, ans);
//	cout << u << endl;
	printf("%lld\n", ans);
	return 0;
}