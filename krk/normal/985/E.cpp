#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;

int n, k, d;
int a[Maxn];
set <int> S;

int main()
{
	scanf("%d %d %d", &n, &k, &d);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	S.insert(n);
	for (int i = n - 1; i >= 0; i--)
		if (i + k - 1 < n && a[i + k - 1] - a[i] <= d) {
			set <int>::iterator it = S.lower_bound(i + k);
			if (it != S.end() && a[*it - 1] - a[i] <= d) S.insert(i);
		}
	printf("%s\n", S.find(0) != S.end()? "YES": "NO");
	return 0;
}