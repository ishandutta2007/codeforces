#include<bits/stdc++.h>
using namespace std;

int read();
#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &
#define cl const LL &
#define I inline void
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 1005;
int n,a[N];
int dp[N][N],from[N][N];
int st[N],top;
void output(int l,int r) {
	if(l > r) return;
	st[++top] = a[l];
	fo(i,1,top) cout << st[i] << '.';
	cout << st[top] << endl;
	output(l+1,from[l][r]-1);
	--top;
	output(from[l][r],r);
}
int main() {
	ios::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		cin >> n;
		fr(i,1,n) cin >> a[i];
		fr(i,1,n) fr(j,i,n) dp[i][j] = 0;
		fr(i,1,n+1) {
			dp[i][i-1] = dp[i][i] = 1;
			from[i][i] = i+1;
		}
		fr(len,2,n) fr(l,1,n-len+1) {
			int r = l+len-1;
			if(dp[l+1][r] && a[l] == a[l+1]-1) {
				from[l][r] = l+1,dp[l][r] = 1;
				continue;
			}
			if(a[l+1] == 1) fr(k,l+1,r+1) if((k > r || a[k] == a[l]+1) && dp[l+1][k-1] && dp[k][r]) {
				from[l][r] = k; dp[l][r] = 1;
				break;
			}
		}
		output(1,n);
	}
	return 0;
}