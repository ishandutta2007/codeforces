#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e3 + 5;
const int mod = 998244353;

int dp[N][N];
int x,y,z;

void calc() {
	for(int i = 0;i < N;++i) {
		for(int j = 0;j < N;++j) {
			if(i == 0 || j == 0) dp[i][j] = 1;
			else dp[i][j] = (dp[i-1][j] + j * dp[i-1][j-1]) % mod;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	calc();
	cin >> x >> y >> z;
	int ans = 1;
	ans = (ans * dp[x][y]) % mod;
	ans = (ans * dp[x][z]) % mod;
	ans = (ans * dp[y][z]) % mod;
	cout << ans << endl;
}