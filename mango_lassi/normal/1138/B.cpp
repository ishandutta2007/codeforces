#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> cou(4, 0);

	string as, cs;
	cin >> as >> cs;
	for (int i = 0; i < n; ++i) {
		int v = (as[i] == '1') + 2*(cs[i] == '1');
		++cou[v];
	}
	
	// Find a, b, c, d such that a+b+c+d = n/2, and a <= cou[0], ..., d <= cou[3], and
	// b + d = cou[2] - c + cou[3]-d	->	b + c + 2d = cou[2] + cou[3]
	int t = cou[2] + cou[3];
	int d = min(n/2, cou[3]);
	int c = min(n/2 - d, cou[2]);
	int b = min(n/2 - d - c, cou[1]);
	int a = min(n/2 - d - c - b, cou[0]);

	while(b + c + 2*d > t) {
		if (d > 0 && c < cou[2]) {
			--d;
			++c;
		} else if (d > 0 && b < cou[1]) {
			--d;
			++b;
		} else if (c > 0 && a < cou[0]) {
			--c;
			++a;
		} else if (b > 0 && a < cou[0]) {
			--b;
			++a;
		} else if (d > 0 && a < cou[0]) {
			--d;
			++a;
		} else {
			break; // Can't do anything QAQ
		}
	}
	if (b + c + 2*d != t) {
		cout << "-1\n";
	} else {
		for (int i = 0; i < n; ++i) {
			int v = (as[i] == '1') + 2*(cs[i] == '1');
			if (v == 0 && a > 0) {
				--a;
			} else if (v == 1 && b > 0) {
				--b;
			} else if (v == 2 && c > 0) {
				--c;
			} else if (v == 3 && d > 0) {
				--d;
			} else {
				continue;
			}
			cout << i+1 << ' ';
		}
		cout << '\n';
	}
}