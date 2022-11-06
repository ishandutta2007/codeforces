#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define infll 1000000000000000000ll
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 109
#define mod 1000000007
using namespace std;

int cnt,m,ans,inv[N],q[N],g[N][N]; ll n,p[N];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
ll readll(){
	ll x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
void calc(int *f,int t){
	f[t]=1;
	int i,j;
	for (i=1; i<=m; i++){
		for (j=0; j<=t; j++) f[j]=(ll)f[j]*inv[j+1]%mod;
		for (j=t-1; j>=0; j--) ad(f[j],f[j+1]);
	}
}
void dfs(int k,ll now,int tmp){
	if (k>cnt){
		ad(ans,now%mod*tmp); return;
	}
	int i;
	for (i=0; i<=q[k]; i++,now*=p[k]) dfs(k+1,now,(ll)tmp*g[k][i]%mod);
}
int main(){
	scanf("%lld%d",&n,&m);
	int i; inv[0]=inv[1]=1;
	for (i=2; i<N; i++) inv[i]=mod-(ll)mod/i*inv[mod%i]%mod;
	for (i=2; (ll)i*i<=n; i++) if (!(n%i)){
		int tmp=0;
		for (; !(n%i); n/=i) tmp++;
		q[++cnt]=tmp; p[cnt]=i;
		calc(g[cnt],tmp);
	}
	if (n>1){ q[++cnt]=1; p[cnt]=n; calc(g[cnt],1); }
	dfs(1,1,1);
	printf("%d\n",ans);
	return 0;
}