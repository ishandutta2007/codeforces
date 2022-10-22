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
const int N = 2e5 + 10;
int n;
int a[N];
set<int> s[N];
void solve() {
	cin >> n;
	for(int i = 0; i <= n; i++) s[i].clear();
	for(int i = 1; i <= n; i++) cin >> a[i], s[a[i]].insert(i);
	vector<int> ans;
	int now;
	for(now = 1; now <= n;) {
		int mex = 0;
		while(sz(s[mex]) > 0) mex++;
		if(mex == 0) break;
		int pos = 0;
		for(int j = 0; j < mex; j++) pos = max(pos, *s[j].begin());
		for(int j = now; j <= pos; j++) s[a[j]].erase(j);
		now = pos + 1;
		ans.push_back(mex);
	}
	for(int i = now; i <= n; i++) ans.push_back(0);
	cout << sz(ans) << endl;
	for(int x : ans) cout << x <<" ";
	cout << endl;
	return;
}
int main() {
	int t;
	for(cin >> t; t--; solve());
	return 0;
}