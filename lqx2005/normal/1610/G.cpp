#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define sz(a) int((a).size())
#define pii pair<int, int>
#define eb emplace_back
#define hsh pair<int, int>
using namespace std;
typedef double db;
typedef long long ll;
const int N = 3e5 + 10, P1 = 1e9 + 7, P2 = 1e9 + 9;
hsh operator + (const hsh a, const hsh b) {
	return {(a.x + b.x) % P1, (a.y + b.y) % P2}; 
}
hsh operator - (const hsh a, const hsh b) {
	return {(a.x - b.x + P1) % P1, (a.y - b.y + P2) % P2};
}
hsh operator * (const hsh a, const hsh b) {
	return {1ll * a.x * b.x % P1, 1ll * a.y * b.y % P2};
}
const hsh B(101, 97);
hsh pw[N], h[N];
char ans[N];
int n;
int sum[N], tot = 0;
vector<int> pos[N * 2];
hsh query(int l, int r) {return h[r] - h[l - 1] * pw[r - l + 1]; }
int compare(int x, int y) {
	int l = -1, r = min(x, y) - 1, lcp = -1;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(query(x - mid, x) == query(y - mid, y)) lcp = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans[x - lcp - 1] < ans[y - lcp - 1];
}
int main() {
	string s;
	cin >> s;
	n = s.length();
	pw[0] = {1, 1};
	for(int i = 1; i <= n; i++) pw[i] = pw[i - 1] * B;
	reverse(s.begin(), s.end());
	pos[n].push_back(0);
	for(int i = 1; i <= n; i++) {
		char c = s[i - 1];
		tot++;
		sum[tot] = sum[tot - 1] + (c == '(' ? 1 : -1);
		ans[tot] = c;
		h[tot] = h[tot - 1] * B + hsh{c, c};
		if(sum[tot - 1] < sum[tot] && !pos[sum[tot] + n].empty()) {
			int pre = pos[sum[tot] + n].back();
			if(compare(pre, tot)) {
				tot--;
				while(tot > pre) pos[sum[tot] + n].pop_back(), tot--;
				continue;
			}
		}
		pos[sum[tot] + n].push_back(tot);
	}
	for(int i = tot; i >= 1	; i--) cout << ans[i];
	cout << endl;
	return 0;
}