#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define llint long long

using namespace std;

llint n, m;
llint a[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	
	if(n >= 1001){
		cout << 0 << endl;
		return 0;
	}
	
	llint ans = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i >= j) continue;
			ans *= (a[j]-a[i]) % m;
			ans %= m;
		}
	}
	cout << ans << endl;

	return 0;
}