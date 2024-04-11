#include <iostream>
#include <string>
#define inf 1000000000

using namespace std;

int n, m, k;
int a[505][505];
int dp[505][505];
int cost[505][505];

int main(void)
{
	cin >> n >> m >> k;
	char c;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> c;
			a[i][j] = c - '0';
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= k; j++){
			int cnt = 0;
			for(int x = 1; x <= m; x++) if(a[i][x]) cnt++;
			cnt -= j;
			if(cnt <= 0) break;
			
			cnt--;
			int left = 0, right = 0, ret = inf;
			while(cnt){
				right++;
				if(a[i][right]) cnt--;
			}
			for(left = 0; left <= m; left++){
				if(a[i][left]){
					while(1){
						right++;
						if(right > m) goto end;
						if(a[i][right]) break;
					}
					ret = min(ret, right - left + 1);
				}
			}
			end:;
			cost[i][j] = ret;
		}
	}
	
	/*for(int i = 1; i <= n; i++){
		for(int j = 0; j <= k; j++){
			cout << cost[i][j] << " ";
		}
		cout << endl;
	}*/
	
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= k; j++){
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= k; j++){
			for(int x = 0; x <= j; x++){
				dp[i][j] = min(dp[i][j], dp[i-1][j-x] + cost[i][x]);
			}
		}
	}
	
	int ans = inf;
	for(int i = 0; i <= k; i++) ans = min(ans, dp[n][i]);
	cout << ans << endl << endl;
	
	return 0;
	
}