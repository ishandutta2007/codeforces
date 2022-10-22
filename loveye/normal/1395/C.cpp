#include<bits/stdc++.h>
using namespace std;
const int MOD = 0;

#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &

const int N = 205,S = 1 << 9;
int n,m,a[N],b[N],ans;
int dp[N][S];
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1;i <= n;++i)
		cin >> a[i];
	for(int i = 1;i <= m;++i)
		cin >> b[i];
	dp[0][0] = 1;
	for(int i = 1;i <= n;++i) {
		for(int j = 1;j <= m;++j)
			for(int s = 0;s < S;++s)
				dp[i][s | (a[i] & b[j])] |= dp[i-1][s];
	}
	for(int s = 0;s < S;++s) if(dp[n][s]) {
		cout << s << endl;
		break;
	}
	return 0;
}