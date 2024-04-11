#include <iostream>
#include <algorithm>
#define llint long long

using namespace std;

llint n, Q;
llint s[100005], d[100005], dsum[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> s[i];
	sort(s+1, s+n+1);
	for(int i = 1; i < n; i++) d[i] = s[i+1] - s[i];
	sort(d+1, d+n);
	for(int i = 1; i < n; i++) dsum[i] = dsum[i-1] + d[i];
	
	cin >> Q;
	llint l, r;
	for(int q = 0; q < Q; q++){
		cin >> l >> r;
		if(n == 1){
			cout << r-l+1 << endl;
			continue;
		}
		llint len = r-l+1;
		llint ans = s[n]+r - (s[1]+l) + 1;
		//cout << ans << endl;
		llint p = lower_bound(d+1, d+n, len) - d;
		ans -= (dsum[n-1]-dsum[p-1]) - (n-p)*len;
		cout << ans << " ";
	}
	cout << endl;
	return 0;
}