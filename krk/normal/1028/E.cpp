#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int b[Maxn];
ll res[Maxn];

int main()
{
	scanf("%d", &n);
	int mx = -1, cnt = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		if (b[i] > mx) { mx = b[i]; cnt = 0; }
		if (b[i] == mx) cnt++;
	}
	if (mx == 0) {
		printf("YES\n");
		for (int i = 0; i < n; i++)
			printf("1%c", i + 1 < n? ' ': '\n');
		return 0;
	}
	if (cnt == n) { printf("NO\n"); return 0; }
	int ind = 0;
	while (b[ind] != mx) ind++;
	while (b[ind] == mx) ind = (ind - 1 + n) % n;
	ind = (ind + 1) % n;
	ll cur = b[ind];
	res[ind] = cur;
	ind = (ind - 1 + n) % n;
	cur += b[ind];
	if (b[ind] == 0) cur += mx;
	res[ind] = cur;
	ind = (ind - 1 + n) % n;
	for (int i = 2; i < n; i++) {
		cur += b[ind];
		res[ind] = cur;
		ind = (ind - 1 + n) % n;
	}
	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%I64d%c", res[i], i + 1 < n? ' ': '\n');
	return 0;
}