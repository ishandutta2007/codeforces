#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

const int N = 2 * (int)1e5;
pair<int, int> dif[N];
pair<int, int> pref[N+1];
pair<int, int> suff[N+1];

pair<int, int> add(pair<int, int> a, pair<int, int> b) {
	return {a.first + b.first, a.second + b.second};
}
pair<int, int> sub(pair<int, int> a, pair<int, int> b) {
	return {a.first - b.first, a.second - b.second};
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	string str;
	cin >> str;

	pair<int, int> tar;
	cin >> tar.first >> tar.second;

	for (int i = 0; i < n; ++i) {
		if (str[i] == 'U') dif[i] = {0, 1};
		if (str[i] == 'D') dif[i] = {0, -1};
		if (str[i] == 'L') dif[i] = {-1, 0};
		if (str[i] == 'R') dif[i] = {1, 0};
	}

	pref[0] = {0, 0};
	for (int i = 0; i < n; ++i) {
		pref[i+1] = add(pref[i], dif[i]);
	}
	suff[n] = {0, 0};
	for (int i = n-1; i >= 0; --i) {
		suff[i] = add(suff[i+1], dif[i]);
	}
	
	int low = 0;
	int high = n+1;
	while(low != high) {
		int mid = (low + high) >> 1;
		
		bool can = false;
		for (int i = 0; i + mid <= n; ++i) {
			pair<int, int> cur = add(pref[i], suff[i + mid]);
			pair<int, int> len = sub(tar, cur);
			int dx = abs(len.first);
			int dy = abs(len.second);
			if (((dx + dy) % 2) != (mid % 2)) continue;
			if (dx + dy > mid) continue;
			can = true;
		}
		if (can) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	if (low <= n) {
		cout << low << '\n';
	} else {
		cout << "-1\n";
	}
}