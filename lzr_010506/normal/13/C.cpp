#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, a[5010], b[5010], f[5010];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i], b[i] = a[i];
	sort(b + 1, b + n + 1);
	f[0] = 1LL << 62;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			f[j] = min(f[j - 1], f[j] + abs(a[i] - b[j]));
	cout << f[n];
	return 0;
}