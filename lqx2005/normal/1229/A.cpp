#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define i64 long long
#define db double
using namespace std;
const int N = 7000 + 10;
int n, id[N], vis[N];
i64 a[N], b[N];
map<i64, int> c, v;
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i], c[a[i]]++, v[a[i]] += b[i];
	i64 ans = 0;
	for(auto pi : c) {
		if(pi.second == 1) continue;
		for(int i = 1; i <= n; i++) if((a[i] & pi.first) == a[i]) vis[i] = 1;
	}
	for(int i = 1; i <= n; i++) ans += vis[i] * b[i];
	cout << ans << endl;
	return 0;
}