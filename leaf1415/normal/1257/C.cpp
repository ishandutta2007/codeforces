#include <iostream>
#include <stdlib.h>
#include <map>
#define llint long long
#define inf 1e18

using namespace std;

llint T, n;
llint a[200005];
map<llint, llint> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		llint r = 0, ans = inf, num = 0;
		mp.clear();
		for(int l = 1; l <= n; l++){
			//cout << l << " " << r << " " << num << endl;
			while(num == 0 && r < n){
				r++;
				mp[a[r]]++;
				if(mp[a[r]] == 2) num++;
			}
			if(num) ans = min(ans, r-l+1);
			if(mp[a[l]] == 2) num--;
			mp[a[l]]--;
		}
		if(ans >= inf-1) cout << -1 << endl;
		else cout << ans << endl;
	}
	return 0;
}