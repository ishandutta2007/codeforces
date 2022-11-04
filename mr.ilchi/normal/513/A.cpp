#include <bits/stdc++.h>
using namespace std;

int n[2],k[2];
int dp[55][55][2];

int go (int n, int m, int turn){
	int &ret = dp[n][m][turn];
	if (ret != -1)
		return ret;
	int k = ::k[turn];
	for (int i=1; i<=n; i++) if (go(m,n-i,1-turn) == false)
		return ret = 1;
	return ret = 0;
}

int main(){
	cin >> n[0] >> n[1] >> k[0] >> k[1];
	memset(dp, -1, sizeof dp);
	cout << (go(n[0],n[1],0) ? "First" : "Second") << endl;
	return 0;
}