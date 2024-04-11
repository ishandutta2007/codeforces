#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=1000010,MOD=1000000007;
int n,l,k,ans,a[N],b[N],cnt[N],cntg[N];
vector<vector<int> >f,sf,g,sg;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>l>>k;
	for(int i=0;i<n;i++)
		cin>>a[i],b[i]=a[i];
	sort(b,b+n);
	for(int i=0;i<n;i++)
		a[i]=upper_bound(b,b+n,a[i])-b,cnt[a[i]]++;
	for(int i=0;i<l%n;i++)
		cntg[a[i]]++;
	f.resize(k+1),sf.resize(k+1),g.resize(k+1),sg.resize(k+1);
	for(int i=0;i<=k;i++)
		f[i].resize(n+1),sf[i].resize(n+1),
		g[i].resize(n+1),sg[i].resize(n+1);
	f[0][0]=sf[0][0]=g[0][0]=sg[0][0]=1;
	for(int i=0;i<=k;i++)
		for(int j=0;j<=n;j++){
			if(i)f[i][j]=sf[i-1][j]*cnt[j]%MOD;
			if(j)sf[i][j]=(sf[i][j-1]+f[i][j])%MOD;
			if(i)g[i][j]=sf[i-1][j]*cntg[j]%MOD;
			if(j)sg[i][j]=(sg[i][j-1]+g[i][j])%MOD;
		}
	for(int i=1;i<=min(k,(l+n-1)/n);i++)
		ans=(ans+((l-(l%n>0))/n-i+1)%MOD*sf[i][n]%MOD+sg[i][n])%MOD;
	cout<<ans<<"\n";
	return 0;
}