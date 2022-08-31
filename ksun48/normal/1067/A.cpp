#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 998244353;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	// last number, whether it still needs something
	vector<LL> dp0(201, 0); // no
	vector<LL> dp1(201, 0); // still needs something >= x
	dp0[0] = 1;
	for(int i = 0; i < n; i++){
		vector<LL> newdp0(201, 0);
		vector<LL> newdp1(201, 0);
		LL psum = 0;
		for(int b = 1; b <= 200; b++){
			psum += dp0[b-1];
			psum += dp1[b-1];
			psum %= MOD;
			newdp1[b] += psum;
			newdp1[b] %= MOD;
		}
		for(int b = 1; b <= 200; b++){
			newdp0[b] += dp0[b];
			newdp0[b] += dp1[b];
			newdp0[b] %= MOD;
		}
		psum = 0;
		for(int b = 200; b >= 1; b--){
			newdp0[b] += psum;
			newdp0[b] %= MOD;
			psum += dp0[b];
			psum %= MOD;
		}

		for(int a = 0; a <= 200; a++){
			newdp0[a] %= MOD;
			newdp1[a] %= MOD;
		}
		int v;
		cin >> v;
		if(v != -1){
			for(int x = 0; x <= 200; x++){
				if(x != v) newdp0[x] = newdp1[x] = 0;
			}
		}
		dp0 = newdp0;
		dp1 = newdp1;
	}
	LL ans = 0;
	for(int i = 0; i <= 200; i++){
		ans += dp0[i];
		ans %= MOD;
	}
	cout << ans << '\n';
}