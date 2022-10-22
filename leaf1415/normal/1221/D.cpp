#include <iostream>
#define llint long long

using namespace std;

llint Q;
llint n;
llint a[300005], c[300005];
llint dp[300005][3];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i] >> c[i];
		for(int i = 0; i <= n; i++){
			for(int j = 0; j < 3; j++){
				dp[i][j] = 1e18;
			}
		}
		dp[0][0] = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 3; j++){
				for(int k = 0; k < 3; k++){
					if(a[i]+j == a[i+1]+k) continue;
					dp[i+1][k] = min(dp[i+1][k], dp[i][j] + k * c[i+1]);
				}
			}
		}
		/*for(int i = 0; i <= n; i++){
			for(int j = 0; j < 3; j++){
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}*/
		cout << min(dp[n][0], dp[n][1]) << "\n";
	}
	flush(cout);
	
	return 0;
}