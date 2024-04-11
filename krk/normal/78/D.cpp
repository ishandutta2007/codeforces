#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int k;
ll res;

bool Check(ll x, ll y) { return x * x + 3ll * y * y <= 4 * ll(k) * ll(k); }

int main()
{
	scanf("%d", &k);
	for (int delt = -k; delt <= k; delt++) {
		int x = delt * 3;
		if (delt % 2 == 0) {
			int up = -1;
			int lef = 0, rig = k;
			while (lef <= rig) {
				int mid = lef + rig >> 1;
				int y = 2 * mid;
				if (Check(x - 2, y) && Check(x - 1, y + 1) && Check(x + 1, y + 1) && Check(x + 2, y)) {
					up = mid; lef = mid + 1;
				} else rig = mid - 1;
			}
			res += up == -1? 0: 2 * up + 1;
		} else {
			int up = -1;
			int lef = 0, rig = k;
			while (lef <= rig) {
				int mid = lef + rig >> 1;
				int y = 2 * mid + 1;
				if (Check(x - 2, y) && Check(x - 1, y + 1) && Check(x + 1, y + 1) && Check(x + 2, y)) {
					up = mid; lef = mid + 1;
				} else rig = mid - 1;
			}
			res += up == -1? 0: 2 * (up + 1);
		}
	}
	printf("%I64d\n", res);
	return 0;
}