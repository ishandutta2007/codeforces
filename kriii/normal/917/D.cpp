#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const long long mod = 1000000007;
vector<int> G[101];

vector<vector<int> > go(int x, int l)
{
	vector<vector<int> > res(1,vector<int>(1,1));

	for (auto &y : G[x]) if (y != l){
		auto nxt = go(y,x);
		int sz = res.size() + nxt.size();
		vector<vector<int> > sum(sz);
		for (int i=0;i<sz;i++) sum[i].resize(i+1);
		for (int i=0;i<res.size();i++) for (int j=0;j<=i;j++) if (res[i][j]){
			for (int k=0;k<nxt.size();k++) for (int l=0;l<=k;l++) if (nxt[k][l]){
				sum[i+k][j] = (sum[i+k][j] + (long long)res[i][j] * nxt[k][l] % mod * (l+1)) % mod;
				sum[i+k+1][j+l+1] = (sum[i+k+1][j+l+1] + (long long)res[i][j] * nxt[k][l]) % mod;
			}
		}
		res = move(sum);
	}

	return move(res);
}

long long fpow(long long a, long long p)
{
	long long r = 1;
	while (p){
		if (p & 1) r = r * a % mod;
		a = a * a % mod;
		p /= 2;
	}
	return r;
}

int main()
{
	int n; scanf ("%d",&n);
	for (int i=1,x,y;i<n;i++){
		scanf ("%d %d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}

	auto v = go(1,0);
	long long invn = fpow(n,mod-2);
	long long st = fpow(n,n-2);
	vector<long long> ans(n);
	for (int i=0;i<v.size();i++){
		for (int j=0;j<=i;j++) v[i][j] = (long long) v[i][j] * (j + 1) % mod;
		for (int j=0;j<=i;j++) ans[i] = (ans[i] + v[i][j] * st) % mod;
		st = st * invn % mod;
	}

	long long comb[101][101] = {0,};
	for (int i=0;i<=n;i++){
		comb[i][0] = comb[i][i] = 1;
		for (int j=1;j<i;j++) comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % mod;
	}

	for (int i=n-1;i>=0;i--){
		for (int j=0;j<i;j++){
			ans[j] = (ans[j] + mod - ans[i] * comb[i][j] % mod) % mod;
		}
	}

	for (int i=0;i<n;i++) printf("%lld ",ans[i]);

	return 0;
}