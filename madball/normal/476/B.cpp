#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int n = 0;
	char cur;
	int need = 0, min = 0, max = 0;

	while (true) {
		scanf("%c", &cur);
		if (cur == '\n')
			break;
		if (cur == '+')
			need++;
		if (cur == '-')
			need--;
		n++;
	}
	
	for (int i = 0; i < n; i++) {
		cin >> cur;
		if (cur == '?') {
			max++;
			min--;
		}
		if (cur == '+') {
			max++;
			min++;
		}
		if (cur == '-') {
			max--;
			min--;
		}
	}

	cout.precision(20);
	if (((need - min) % 2) || (need < min) || (need > max)) {
		cout << 0.0;
	}
	else {
		need -= min;
		max -= min;
		min -= min;
		need /= 2;
		max /= 2;
		min /= 2;
		double res = 1;
		for (int i = 0; i < max; i++) {
			if (i < need)
				res *= 0.5;
			else
				res *= 0.5 * (i + 1) / (i + 1 - need);
		}
		cout << res;
	}

	return 0;
}