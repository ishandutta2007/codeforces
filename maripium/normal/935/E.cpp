#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int K = 105;
const int INF = 4e9;

string s;
int dp[N][K][2];
int now = 1;
bool opp = true;
int child[N][2];
int p,m;

int findm(int l,int r) {
	int cur = 0;
	for(int i = l + 1;i < r;++i) {
		if(cur == 0 && s[i] == '?') return i;
		if(s[i] == '(') ++cur;
		else if(s[i] == ')') --cur; 
	}
}

void build(int n,int l,int r) {
	if(l == r) {
		child[n][0] = child[n][1] = -(s[l] - '0');
		return;
	}
	int m = findm(l,r);
	child[n][0] = ++now;	
	build(child[n][0],l + 1,m - 1);
	child[n][1] = ++now;	
	build(child[n][1],m + 1,r - 1);
}

void calc(int n,int l,int r) {
	if(l == r) {
		dp[n][0][0] = dp[n][0][1] = -child[n][0];
		return;
	}
	int m = findm(l,r);
	calc(child[n][0],l + 1,m - 1);
	calc(child[n][1],m + 1,r - 1);
	
	int n0 = child[n][0];
	int n1 = child[n][1];
	for (int i = 0;i <= p;++i) {
		for (int j = 0;j + i <= p;++j) {
			for (int k = 0;k < 2;++k) {
				for (int l = 0;l < 2;++l) {
					if(abs(dp[n0][i][k]) == INF || abs(dp[n1][j][l]) == INF) continue;
					int cur;
					if(opp) cur = dp[n0][i][k] - dp[n1][j][l];
					else cur = dp[n0][i][k] + dp[n1][j][l];
					dp[n][i + j][0] = min(dp[n][i + j][0],cur);
					dp[n][i + j][1] = max(dp[n][i + j][1],cur);
				}
			}
		} 
	}
	
	for (int i = 0;i < p;++i) {
		for (int j = 0;j + i < p;++j) {
			for (int k = 0;k < 2;++k) {
				for (int l = 0;l < 2;++l) {
					if(abs(dp[n0][i][k]) == INF || abs(dp[n1][j][l]) == INF) continue;
					int cur;
					if(opp) cur = dp[n0][i][k] + dp[n1][j][l];
					else cur = dp[n0][i][k] - dp[n1][j][l];
					dp[n][i + j + 1][0] = min(dp[n][i + j + 1][0],cur);
					dp[n][i + j + 1][1] = max(dp[n][i + j + 1][1],cur);
				}
			}
		} 
	}
}

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cin >> s >> p >> m;
	if(p > m) {
		swap(m,p);
		opp = false;
	}
	build(1,0,s.size() - 1);
	for (int i = 0;i < N;++i) for (int j = 0;j < K;++j) dp[i][j][0] = INF, dp[i][j][1] = -INF;
	calc(1,0,s.size() - 1);
	cout << dp[1][p][1] << endl;
}