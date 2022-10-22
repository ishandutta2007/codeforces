#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxnk = 100005;

int n, k, l;
int a[Maxnk];
ll res;

int main()
{
	scanf("%d %d %d", &n, &k, &l);
	for (int i = 0; i < n * k; i++)
		scanf("%d", &a[i]);
	sort(a, a + n * k);
	int p = (n - 1) * k;
	while (p > 0 && a[p] - a[0] > l) p--;
	int got = n * k - 1 - p, obt = 0;
	for (int i = p; i >= 0; i--)
		if (got >= k - 1) { got -= (k - 1); obt++; res += a[i]; }
		else got++;
	if (obt == n && got == 0)
		cout << res << endl;
	else printf("0\n");
	return 0;
}