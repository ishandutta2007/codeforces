#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(a) (int)a.size()
const int N = 2e5;
const int mod = 998244353;

void solver(int turn, int &ans, int a, int b, int c, vector <int> blocks, int other0, int single0, int p, int turns) {
	int cur = 0;
	while (1) {
		if (turn == 1) {
			if (turns > 0) {
				turns--;
				cur += b;
				ans = max(ans, cur);
			}
			else {
				return;
			}
		}
		else {
			if (turns == 0) {
				if (other0 > 0 || blocks.size() > 0) 
				{
					ans = max(ans, cur + a);
				}
				if (single0 > 0) {
					cur -= c;
					ans = max(ans, cur);
					single0--;
					turns++;
				}
			}
			else {
				if (blocks.size() > 0) {
					blocks[blocks.size() - 1]--;
					if (blocks.back() == 1) {
						blocks.pop_back();
						single0++;
					}
					cur += a;
					ans = max(ans, cur);
				}
				else if (other0 > 0) {
					cur += a;
					other0--;
					ans = max(ans, cur);
				}
				else if (single0 > 0) {
					single0--;
					turns++;
					cur -= c;
					ans = max(ans, cur);
				}
				else if (p > 0) {
					p--;
					cur -= c;
					ans = max(ans, cur);
				}
				else {
					return;
				}
			}
		}
		turn ^= 1;
	}
}

int solve(int n, string s, int a, int b, int c) {
	if (n == 1) {
		return 0;
	}
	int ans = 0;
	int first = 1e9, lst = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			lst = i;
		}
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			first = i;
			break;
		}
	}
	if (first == 1e9L) {
		return a;
	}
	vector <int> blocks;
	int p = 0;
	if (s[0] == '0') {
		p++;
	}
	if (s.back() == '0') {
		p++;
	}
	int other = max(first - 1, 0LL) + max(n - lst - 2, 0LL);
	int turns = 0;
	for (int i = 0; i + 1 < n; i++) {
		if (s[i] == s[i + 1] && s[i] == '1') {
			turns++;
		}
	}
	int single0 = 0;
	for (int i = first; i < lst;) {
		int j = i + 1;
		while (s[j] != '1') {
			j++;
		}
		int len = j - i - 1;
		if (len == 1) {
			single0++;
		}
		else if (len > 1) {
			blocks.push_back(len);
		}
		i = j;
	}
	sort(blocks.rbegin(), blocks.rend());
	solver(0, ans, a, b, c, blocks, other, single0, p, turns);
	solver(1, ans, a, b, c, blocks, other, single0, p, turns);
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, a, b, c;
		cin >> n >> a >> b >> c;
		string s;
		cin >> s;
		cout << solve(n, s, a, b, c) << "\n";
	}
	return 0;
}