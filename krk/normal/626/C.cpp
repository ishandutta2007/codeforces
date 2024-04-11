#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;

bool Check(int x)
{
	int myn = n, mym = m;
	int gotm = x < 3? 0: 1 + (x - 3) / 6;
	mym = max(0, mym - gotm);
	int gotnm = x < 2? 0: 1 + (x - 2) / 2;
	return x / 6 >= mym && gotnm >= myn + mym;
}

int main()
{
	scanf("%d %d", &n, &m);
	int l = 0, r = 1000000000;
	int res;
	while (l <= r) {
		int m = l + r >> 1;
		if (Check(m)) { res = m; r = m - 1; }
		else l = m + 1;
	}
	printf("%d\n", res);
	return 0;
}