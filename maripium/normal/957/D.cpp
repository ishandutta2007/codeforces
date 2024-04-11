#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;

int n;
int a[N], st[N], p;

signed main(){
	ios_base::sync_with_stdio(0);   cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];

	int cur = 1;
	int ans = 0;

	for(int i = 1; i <= n; ++ i) {
		if(cur > a[i]) {
			st[++p] = i;
			ans += cur - a[i] - 1LL;
			continue;
		}
		while(cur < a[i]) ++cur, ans += (i - st[p--]);
		++cur;
	}
	cout << ans << endl;
}