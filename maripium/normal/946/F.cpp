#include<bits/stdc++.h>
using namespace std;

const int N = 105;
const int mod = 1e9 + 7;

int n,x;
string s;
int dp[N][N][N];
int pw[N];

void add(int &x,int y) {
	x += y; while(x >= mod) x -= mod; while(x < 0) x += mod;
}

int calc(int k,int l,int r) {
	if(l > r) return 1;
	if(k <= 1) return l == r && s[l] == '0' + k;
	
	int &ans = dp[k][l][r];
	if(ans != -1) return ans;
	ans = 0;
	for (int mid = l - 1;mid <= r;++mid) {
		int cur = 1LL * calc(k - 1,l,mid) * calc(k - 2,mid + 1,r) % mod;
		if (mid + 1 == l && l == 0) cur = 1LL * cur * pw[k - 1] % mod;
		if (mid == r && r == n - 1) cur = 1LL * cur * pw[k - 2] % mod;
		add(ans,cur);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	cin >> n >> x >> s;
	memset(dp,-1,sizeof dp);
	
	pw[0] = pw[1] = 2;
	for (int i = 2;i <= x;++i) pw[i] = 1LL * pw[i - 1] * pw[i - 2] % mod;
	cout << calc(x,0,n - 1) << endl;
}