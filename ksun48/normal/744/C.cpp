#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL dp[65536][150]; // max possible saved;
int main(){
	LL n;
	cin >> n;
	LL c[n];
	LL r[n], b[n];
	for(LL i = 0; i < n; i++){
		string a;
		cin >> a;
		if(a[0] == 'R'){
			c[i] = 0;
		} else {
			c[i] = 1;
		}
		cin >> r[i] >> b[i];
	}
	LL z = (1<<n);
	for(LL i = 0; i < z; i++){
		for(LL j = 0; j < 150; j++){
			dp[i][j] = -1e15;
		}
	}
	dp[0][0] = 0;
	for(LL i = 1; i < z; i++){
		LL nr = 0;
		LL nb = 0;
		for(LL j = 0; j < n; j++){
			if((i>>j) & 1){
				if(c[j]) nb++;
				if(!c[j]) nr++;
			}
		}
		for(LL j = 0; j < n; j++){
			if((i>>j) & 1){
				if(c[j]) nb--;
				if(!c[j]) nr--;
				//cout << i << " " << j << " " << nr << endl;
				for(LL num = 149; num >= 0; num--){
					LL cost = num - min(r[j],nr);
					if(cost < 0) continue;
					dp[i][num] = max(dp[i][num], dp[i ^ (1<<j)][cost] + min(nb,b[j]));
				}
				if(c[j]) nb++;
				if(!c[j]) nr++;
			}
		}
	}
	LL ans = 2e15;
	LL rsum = 0;
	LL bsum = 0;
	for(LL i = 0; i < n; i++) rsum += r[i];
	for(LL i = 0; i < n; i++) bsum += b[i];
	for(LL num = 0; num < 150; num++){
		ans = min(ans, max(rsum-num, bsum-dp[z-1][num]));
		//if(dp[z-1][num] > 0) cout << num << " " << dp[z-1][num] << endl;
	}
	ans += n;
	cout << ans << endl;
}