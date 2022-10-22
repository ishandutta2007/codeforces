#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)
typedef pair<int,int> pii;
#define fi first
#define se second

const int N=1005;
const ll INF=1e18;
int n,m,tot;
ll k;
char s[N];
pii a[N*N];
int lcp[N][N];
int lim[N];
ll dp[N][N];
int chk(int x) {
	fr(i,1,n) lim[i]=n+1;
	rf(i,tot,x) lim[a[i].fi]=min(lim[a[i].fi],a[i].se);
	dp[0][1]=1; dp[0][2]=-1;
	fo(i,0,m) {
		fr(j,1,n+1) dp[i+1][j]=0;
		fr(j,1,n) {
			dp[i][j]+=dp[i][j-1];
			dp[i][j]=min(dp[i][j],INF);
			dp[i+1][lim[j]+1]+=dp[i][j];
			dp[i+1][lim[j]+1]=min(dp[i+1][lim[j]+1],INF);
		}
	}
	fr(j,1,n+1) dp[m][j]+=dp[m][j-1],dp[m][j]=min(dp[m][j],INF);
	return dp[m][n+1]>=k;
}
int main() {
	cin>>n>>m>>k;
	cin>>s+1;
	fr(i,1,n) fr(j,i,n) a[++tot]=make_pair(i,j);
	rf(i,n,1) rf(j,n,1) lcp[i][j]=s[i]==s[j]?1+lcp[i+1][j+1]:0;
	sort(a+1,a+tot+1,[](const pii &a,const pii &b) {
		int k=lcp[a.fi][b.fi];
		if(k>=min(a.se-a.fi+1,b.se-b.fi+1)) return a.se-a.fi+1<b.se-b.fi+1;
		return s[a.fi+k]<s[b.fi+k];
	});
	int l=1,r=tot;
	//fr(i,1,tot) cout<<chk(i)<<endl;
	while(l<r) {
		int mid=l+r+1>>1;
		if(chk(mid)) l=mid;
		else r=mid-1;
	}
	//cout<<l<<endl;
	fr(i,a[l].fi,a[l].se) putchar(s[i]);
	puts("");
	return 0;
}