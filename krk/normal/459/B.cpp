#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Inf = 2000000000;

int n;

int main()
{
	scanf("%d", &n);
	int mn = Inf, mnc = 0;
	int mx = 0, mxc = 0;
	for (int i = 0; i < n; i++) {
		int b; scanf("%d", &b);
		if (b < mn) { mn = b; mnc = 0; }
		if (b == mn) mnc++;
		if (b > mx) { mx = b; mxc = 0; }
		if (b == mx) mxc++;
	}
	printf("%d ", mx - mn);
	if (mn == mx) printf("%I64d\n", ll(n) * (n - 1) / 2);
	else printf("%I64d\n", ll(mnc) * mxc);
	return 0;
}