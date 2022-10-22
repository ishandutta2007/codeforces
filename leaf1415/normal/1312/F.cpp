#include <iostream>
#include <algorithm>
#include <set>
#define llint long long
#define mod 998244353
#define inf 1e18
#define rep(i, s, t) for(llint (i) = (s); (i) <= (t); (i)++)

using namespace std;

llint T;
llint n;
llint a[3], b[300005];
llint dp[205][3];
llint g[300005][4];
llint period;
llint cnt[205];

llint per()
{
	for(int i = 1; i <= 200; i++) cnt[i] = 0;
	for(int i = 1; i <= 200; i++){
		for(int j = 1; j <= 200; j++){
			if(i >= j) continue;
			if(dp[i][0] == dp[j][0] && dp[i][1] == dp[j][1] && dp[i][2] == dp[j][2]){
				cnt[j-i]++;
			}
		}
	}
	llint mx = -1;
	for(int i = 1; i <= 200; i++){
		if(mx < cnt[i]){
			mx = cnt[i];
			period = i;
		}
	}
}

llint get(llint x, llint y)
{
	if(x >= 200){
		x -= (x-200+period-1)/period*period;
	}
	return dp[x][y];
}

void calc(llint i)
{
	rep(k, 0, 2){
		llint x = max(0LL, b[i]-a[k]);
		llint y = k;
		g[i][k] = get(x, y);
	}
	g[i][3] = get(b[i], 0);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	rep(t, 1, T){
		cin >> n >> a[0] >> a[1] >> a[2];
		
		rep(i, 0, 200){
			rep(j, 0, 2){
				dp[i][j] = 0;
			}
		}
		rep(i, 1, 200){
			rep(j, 0, 2){
				set<llint> S;
				rep(k, 0, 2){
					if(k > 0 && j == k) continue;
					llint x = max(0LL, i-a[k]);
					llint y = k;
					S.insert(dp[x][y]);
				}
				while(S.count(dp[i][j])) dp[i][j]++;
			}
		}
		per();
		
		/*rep(i, 0, 50){
		cout << i << " ";
			rep(j, 0, 2){
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		cout << period << endl;*/
		
		rep(i, 1, n){
			cin >> b[i];
			calc(i);
		}
		
		/*rep(i, 0, 50){
			cout << i << " ";
			rep(j, 0, 3){
				cout << g[i][j] << " ";
			}
			cout << endl;
		}*/
		
		llint ans = 0, sum = 0;
		rep(i, 1, n) sum ^= g[i][3];
		rep(i, 1, n){
			rep(j, 0, 2){
				if((sum ^ g[i][3] ^ g[i][j]) == 0) ans++;
			}
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}