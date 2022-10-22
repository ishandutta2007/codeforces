#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define mid ((l + r) >> 1)
#define ls (p + 1)
#define rs (p + ((mid - l + 1) << 1))
using namespace std;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;
typedef double db;
const int N = 1e5 + 10;
int n;
string s[N];
map<string, int> vis[3];
void solve() {
	for(int i = 0; i <= 2; i++) vis[i].clear();
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for(int i = 1; i <= n; i++) {
		string t = s[i];
		reverse(t.begin(), t.end());
		if(s[i] == t) {
			puts("YES");
			return;
		}
	}
	for(int i = 1; i <= n; i++) {
		string t = s[i];
		reverse(t.begin(), t.end());
		if(sz(t) >= 3) {
			if(vis[0][t]) return puts("YES"), void();
			t.pop_back();
			if(vis[1][t]) return puts("YES"), void();
		} else {
			if(vis[1][t]) return puts("YES"), void();
			if(vis[2][t]) return puts("YES"), void();
		}
		t = s[i];
		if(sz(t) >= 3) {
			vis[0][t] = 1;
			t.pop_back();
			vis[2][t] = 1;
		} else {
			vis[1][t] = 1;
		}
	}
	puts("NO");
	return;
}
int main() {
	int t;
	for(cin >> t; t--; solve());
	return 0;
}