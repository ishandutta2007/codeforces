#include <iostream>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;

llint n, m, d;
llint c[1005];
llint ans[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> d;
	for(int i = 1; i <= m; i++) cin >> c[i];
	
	llint p = 0;
	for(int i = 1; i <= m; i++){
		llint sum = 0;
		for(int j = i; j <= m; j++) sum += c[j];
		llint l = min(p+d, (n+1)-sum);
		for(int j = l; j < l+c[i]; j++) ans[j] = i;
		p = l+c[i]-1;
	}
	if(n+1 - p > d) cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
	}
	
	return 0;
}