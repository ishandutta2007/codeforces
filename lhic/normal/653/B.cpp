#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;
int n, q;
string a[100];
string b[100];
int ans;

void run(int x, string now) {
	if (x == n) {
		if (now == "a")
			++ans;
		return;
	}
	if (x == 0) {
		for (int i = 0; i < 6; ++i) {
			string go = "a";
			go[0] = 'a' + i;
			run(1, go);
		}
		return;
	}
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < q; ++j) {
			if (a[j][0] == now[0] && a[j][1] == (char)('a' + i)) {
				run(x + 1, b[j]);
				break;
			}
		}
	}
}


int main() {
	cin >> n;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> a[i] >> b[i];
	}
	run(0, "");
	cout << ans << "\n";
	return 0;
}