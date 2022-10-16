/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=1e18;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
int n,m,k;
int a[51][20005],sum[51][20005];
vector<pair<int,int> >v[51];
int dp[51][20005],pre[51][20005],suf[51][20005];
bool cross(int x,int y){
	if(y>x){if(x+k-1>=y)return true;}
	else{if(y+k-1>=x)return true;}
	return false;
}
inline void trans_dp(int i,int pre,int now){
	int l=now,r=now+k-1;
	int val=sum[i+2][r]-sum[i+2][l-1];
	if(pre>now)r=min(r,pre-1);
	else l=max(l,pre+k);
	if(r>=l)val+=sum[i+1][r]-sum[i+1][l-1];
	dp[i+1][now]=max(dp[i+1][now],dp[i][pre]+val);
}
struct SGT{
	#define SIZE 131072
	int f[SIZE<<1],l,r;
	SGT(){
		for(int i=0;i<SIZE*2;i++)f[i]=-inf;
	}
	void set(int x,int v){
		x+=SIZE;f[x]=v;
		while(x!=1){
			x>>=1;
			f[x]=max(f[x<<1],f[x<<1|1]);
		}
	}
	int _query(int L,int R,int k){
		if(R<l||r<L)return -inf;
		if(l<=L&&R<=r)return f[k];
		return max(_query(L,(L+R)/2,k<<1),_query((L+R)/2+1,R,k<<1|1));
	}
	int query(int _l,int _r){
		l=_l;r=_r;return _query(0,SIZE-1,1);
	}
}S[51],P[51];
signed main(){
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	memset(dp,-1,sizeof dp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%I64d",&a[i][j]);
			sum[i][j]=sum[i][j-1]+a[i][j];
		}
		for(int j=k;j<=m;j++){
			v[i].push_back(make_pair(sum[i][j]-sum[i][j-k],j-k+1));
		}
		sort(v[i].begin(),v[i].end());
		reverse(v[i].begin(),v[i].end());
	}
	for(int i=1;i<=m-k+1;i++)dp[1][i]=sum[1][i+k-1]-sum[1][i-1]+sum[2][i+k-1]-sum[2][i-1];
	for(int i=1;i<=n;i++){
		if(i!=1)
		for(int j=1;j<=m-k+1;j++){
			const int add=sum[i][j+k-1]-sum[i][j-1]+sum[i+1][j+k-1]-sum[i+1][j-1];
			if(j-k>0)dp[i][j]=max(dp[i][j],pre[i-1][j-k]+add);
			if(j+k<=m)dp[i][j]=max(dp[i][j],suf[i-1][j+k]+add);
			int l=max(1ll,j-k+1),r=j;
			dp[i][j]=max(dp[i][j],P[i-1].query(l,r)+add+sum[i][j-1]);
			l=j;r=min(m,j+k-1);
			dp[i][j]=max(dp[i][j],S[i-1].query(l,r)+add+sum[i][m]-sum[i][r]);
			/*
			for(int p=max(1,j-k+1);p<=min(m-k+1,j+k-1);p++){
				trans_dp(i,j,p);
			}
			*/
//			cerr<<i<<" "<<j<<" "<<dp[i][j]<<endl; 
		}
		for(int j=1;j<=m-k+1;j++){
			pre[i][j]=max(pre[i][j-1],dp[i][j]);
		}
		for(int j=m-k+1;j>=1;j--){
			suf[i][j]=max(suf[i][j+1],dp[i][j]);
		}
		int sub=0;
		for(int j=m;j>=m-k+2;j--)sub+=a[i+1][j];
		for(int j=m-k+1;j>=1;j--){
			sub+=a[i+1][j];S[i].set(j,dp[i][j]-sub);
		}
		sub=0;
		for(int j=1;j<=k-1;j++)sub+=a[i+1][j];
		for(int j=1;j<=m-k+1;j++){
			sub+=a[i+1][j+k-1];P[i].set(j,dp[i][j]-sub);
		}
	}
	cout<<*max_element(dp[n],dp[n]+m+1)<<endl;
	return 0;
}