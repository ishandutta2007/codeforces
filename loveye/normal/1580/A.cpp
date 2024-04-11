#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

#define int long long
int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 405;
int n,m;
char s[N][N];
int dp[N][N],sum[N][N];
int gsum(int x1,int y1,int x2,int y2) {
	return sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
}
int calc2(int i,int l,int r) {
	return (s[i][l] == '0') + (s[i][r] == '0') + gsum(i,l+1,i,r-1);
}
int calc3(int i,int l,int r) {
	return (r-l-1) - gsum(i,l+1,i,r-1);
}
int calc1(int i,int l,int r) {
	return calc2(i+1,l,r) + calc2(i+2,l,r) + calc2(i+3,l,r) + calc3(i+4,l,r);
}
signed main() {
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		fr(i,1,n) cin >> &s[i][1];
		fr(i,1,m) fr(j,1,m) dp[i][j] = n * m,sum[i][j] = 0;
		fr(i,1,n) fr(j,1,m) sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + (s[i][j] == '1');
		int ans = n * m;
		rf(i,n-4,1) {
			fr(l,1,m) {
				fr(r,l+3,m) {
					dp[l][r] = min(dp[l][r] + calc2(i+1,l,r),calc1(i,l,r));
					ans = min(dp[l][r] + calc3(i,l,r),ans);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}