#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <string>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

#define FAST ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr)
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define all(v) begin(v), end(v)
#define FIXED cout << fixed << setprecision(10)

typedef long long ll;
typedef long double ld;

using namespace std;

string s;

bool f(int k) {
	if (s.size() - 1 > 2 * k) return true;
	if (s.size() - 1 < 2 * k) return false;
	for (int i = 1; i < (int)s.size(); i++)
		if (s[i] == '1') return true;
	return false;
}

signed main() {
	FAST;
	FIXED;
	getline(cin, s);
	int ans = 0;
	for (int i = 0; i <= 50; i++) {
		if (f(i)) ans++;
	}
	cout << ans;
}