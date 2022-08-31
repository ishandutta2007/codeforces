#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	int x, y, res = 0;
	cin >> x >> y;
	for (;;) {
		if (x < y)
			swap(x, y);
		if (x < 2 || y < 1)
			break;
		x -= 2;
		y++;
		res++;

	}
	cout << res << endl;

	return 0;
}