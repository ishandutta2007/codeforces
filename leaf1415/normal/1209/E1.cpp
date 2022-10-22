#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint Q;
llint h, w;
llint a[4][105];
llint dp[105][1<<4];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int t = 0; t < Q; t++){
		cin >> h >> w;
		for(int i = 0; i < h; i++){
			for(int j = 1; j <= w; j++){
				cin >> a[i][j];
			}
		}
		
		int N = 1<<h;
		for(int i = 0; i <= w; i++){
			for(int j = 0; j < N; j++){
				dp[i][j] = -1e18;
			}
		}
		dp[0][0] = 0;
		for(int i = 0; i < w; i++){
			for(int j = 0; j < N; j++){
				for(int k = 0; k < N; k++){
					llint mask = k, sum = 0;
					for(int l = 0; l < h; l++){
						if(k & (1<<l)) sum += a[l][i+1];
					}
					for(int l = 0; l < h; l++){
						if((j & mask) == 0){
							dp[i+1][j|mask] = max(dp[i+1][j|mask], dp[i][j] + sum);
						}
						mask |= ((mask & 1) << h);
						mask >>= 1;
					}
				}
			}
		}
		cout << dp[w][N-1] << endl;
	}
	
	return 0;
}