#include <iostream>
#include <deque>
#define llint long long 
#define inf 1000000000000000000

using namespace std;

llint n, W, B, X;
llint c[1005];
llint cost[1005];
llint dp[1005][10005];
llint csum;
deque<llint> deq;
llint vals[10005];

int main(void)
{
	cin >> n >> W >> B >> X;
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n; i++) cin >> cost[i];
	for(int i = 1; i <= n; i++) csum += c[i];
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= csum; j++){
			dp[i][j] = -inf;
		}
	}
	dp[0][0] = W;
	
	for(int i = 1; i <= n; i++){
		deq.clear();
		for(int j = 0; j <= csum; j++){
			for(int k = 0; k <= c[i]; k++){
				llint val =  min(dp[i-1][j-k] + X, W+(j-k)*B) - k*cost[i];
				if(val < 0) val = -inf;
				dp[i][j] = max(dp[i][j], val);
			}
		}
	}
	
	/*for(int i = 0; i <= n; i++){
		for(int j = 0; j <= csum; j++){
			if(dp[i][j] < 0) cout << "-inf" << " ";
			else cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	
	for(int j = csum; j >= 0; j--){
		if(dp[n][j] >= 0){
			cout << j << endl;
			break;
		}
	}
	return 0;
}