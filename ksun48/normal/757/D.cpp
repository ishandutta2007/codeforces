#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;

int n;
string a;
int ans = 0;
int dp[77][1<<20];
int num[100][100];
int main(){
	cin >> n >> a;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			num[i][j] = 0;
			for(int k = i; k <= j; k++){
				num[i][j] *= 2;
				num[i][j] += (a[k]-'0');
				if(num[i][j] > 100) num[i][j] = 100;
			}
		}
	}
	for(int i = 1; i <= 20; i++){
		//cout << "i " << i << endl;
		for(int c = 0; c <= n; c++){
			for(int d = 0; d < (1<<i); d++) dp[c][d] = 0;
		}
		for(int c = 0; c <= n; c++){
			dp[c][0]++;
			for(int f = c-1; f >= 0; f--){
				if(num[f][c-1] > i) break;
				if(num[f][c-1] == 0) continue;
				for(int d = 0; d < (1<<i); d++){
					if(dp[f][d] == 0) continue;
					//cout << f << " " << d << endl;
					dp[c][d | (1 << (num[f][c-1]-1))] += dp[f][d];
					dp[c][d | (1 << (num[f][c-1]-1))] %= MOD;
				}
			}
		}
		for(int c = 0; c <= n; c++){
			ans += dp[c][(1<<i)-1];
			ans %= MOD;
		}
	}
	cout << ans << endl;
}