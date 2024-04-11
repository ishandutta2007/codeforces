#include <iostream>
#include <string>
#define llint long long

using namespace std;

llint T;
llint dp[35][2][2];

llint calc(llint u, llint v)
{
	if(u < 0 || v < 0) return 0;
	
	for(int i = 32; i >= 0; i--){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				dp[i][j][k] = 0;
			}
		}
	}
	dp[32][0][0] = 1;
	
	for(llint i = 32; i > 0; i--){
		llint U = (u>>(i-1))&1, V = (v>>(i-1))&1;
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				for(int l = 0; l < 2; l++){
					for(int m = 0; m < 2; m++){
						if(l == 1 && m == 1) continue;
						if(U == 0 && l == 1 && j == 0) continue;
						if(V == 0 && m == 1 && k == 0) continue;
						int nj = j, nk = k;
						if(U == 1 && l == 0) nj = 1;
						if(V == 1 && m == 0) nk = 1;
						dp[i-1][nj][nk] += dp[i][j][k];
					}
				}
			}
		}
	}
	llint ret = 0;
	for(int j = 0; j < 2; j++){
		for(int k = 0; k < 2; k++){
			ret += dp[0][j][k];
		}
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	llint l, r;
	for(int q = 0; q < T; q++){
		cin >> l >> r;
		llint ans = 0;
		ans += calc(r, r);
		ans -= calc(l-1, r) + calc(r, l-1);
		ans += calc(l-1, l-1);
		cout << ans << endl;
	}
	
	return 0;
}