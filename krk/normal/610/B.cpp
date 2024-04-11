#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int a[Maxn];
int mn = 2000000000;
ll res;
int mx;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		mn = min(mn, a[i]);
	}
	res = ll(mn) * n;
	int i = 0;
	while (i < n)
		if (a[i] == mn) i++;
		else {
			int j = i;
			while (a[j % n] > mn) j++;
			mx = max(mx, j - i);
			i = j;
		}
	res += mx;
	printf("%I64d\n", res);
	return 0;
}