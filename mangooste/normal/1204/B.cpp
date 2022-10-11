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

signed main() {
	FAST;
	FIXED;
	ll n, l, r;
	cin >> n >> l >> r;
	ll max_sum = 0, p_now = 1, tmp_r = r;
	for (int i = 1; i <= r, n; i++) {
		if (tmp_r == 1) {
			max_sum += p_now * (n - i + 1);
			break;
		} 
		max_sum += p_now;
		tmp_r--;
		p_now *= 2;
	}
	ll min_sum = n - l;
	p_now = 1;
	for (int i = 0; i < l; i++) {
		min_sum += p_now;
		p_now *= 2;
	}
	cout << min_sum << ' ' << max_sum << '\n';
}