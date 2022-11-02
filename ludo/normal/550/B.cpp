#include <iostream>

using namespace std;

#define MAXN 15

int n, l, r, x, c[MAXN], nums[MAXN];

int main()
{
    cin >> n >> l >> r >> x;

	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	int ret = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
		int cursize = 0, tmp = mask, curval = 0, curmin = 2147483647, curmax = -2147483647, total = 0;
		while (tmp) {
			if (tmp & 1) {
				cursize++;
				curmin = min(curmin, c[curval]);
				curmax = max(curmax, c[curval]);
				total += c[curval];
			}
			tmp >>= 1;
			curval++;
		}
//		cout << mask << ": " << cursize << " " << curmin << " " << curmax << endl;
		if (cursize >= 2 && total >= l && total <= r && (curmax - curmin) >= x) {
			ret++;
		}
    }
	cout << ret << endl;
    return 0;
}