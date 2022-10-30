#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000006
#define sz(v) ((int)(v).size())

const int MOD = 998244353;

vector <int> z_function(string s)
{
	int n = sz(s);
	vector <int> z(n, 0);
	for (int i=1,l=0,r=0;i<n;i++){
		if (i <= r)
			z[i] = min(r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
		if (r < i+z[i]-1)
			l = i, r = i+z[i]-1;
	}
	return z;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string S, L, R; int N;
	cin >> S >> L >> R; N = sz(S);
	auto z_l = z_function(L+'#'+S);
	auto z_r = z_function(R+'#'+S);
	vector <int> dp(N+1, 0), sum(N+2, 0);
	dp[N] = sum[N] = 1;
	for (int i=N;i--;){
		if (S[i] == '0'){
			if (L == "0") dp[i] = dp[i+1];
		}else if (i+sz(L) <= N){
			int s = i+sz(L), e = i+sz(R);
			{
				int len = z_l[sz(L)+i+1];
				if (len < sz(L) && L[len] > S[i+len]) s++;
			}
			if (i+sz(R) <= N){
				int len = z_r[sz(R)+i+1];
				if (len < sz(R) && R[len] < S[i+len]) e--;
			}
			e = min(e, N);
			if (s <= e)
				dp[i] = (sum[s]-sum[e+1]+MOD)%MOD;
		}
		sum[i] = (dp[i]+sum[i+1])%MOD;
	}
	printf("%d\n", dp[0]);
}