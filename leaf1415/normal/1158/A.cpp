#include <iostream>
#include <algorithm>
#define llint long long

using namespace std;

llint n, m;
llint b[100005], g[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i = 0; i < m; i++) cin >> g[i];
	sort(b, b+n), sort(g, g+m);
	
	if(g[0] < b[n-1]){
		cout << -1 << endl;
		return 0;
	}
	
	llint ans = 0;
	for(int i = 0; i < n; i++) ans += b[i] * m;
	for(int i = m-1; i >= 0; i--){
		int p = upper_bound(b, b+n, g[i]) - b - 1;
		ans += g[i] - b[p];
	}
	if(g[0] > b[n-1]){
		ans -= g[0] - b[n-1];
		ans += g[0] - b[n-2];
	}
	cout << ans << endl;
	
	return 0;
}