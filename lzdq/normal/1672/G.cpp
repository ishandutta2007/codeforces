#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
const int MAXN=2005,mod=998244353;
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
int n,m,k;
char s[MAXN][MAXN];
struct LB{
	ll a[MAXN];
	int cnt;
	void Ins(ll x){
		for(int i=n*m; i; i--)
			if(x>>i&1){
				if(a[i]) x^=a[i];
				else{
					a[i]=x;
					cnt++;
					return ;
				}
			}
	}
};
int ans;
int pre[MAXN*2];
int fnd(int x){
	if(x!=pre[x]) pre[x]=fnd(pre[x]);
	return pre[x];
}
int tot,sum[MAXN*2];
void  Odd(){
	for(int i=1; i<=n+m; i++)
		pre[i]=i;
	tot=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(s[i][j]==2){
				int x=fnd(i),y=fnd(j+n);
				if(x==y) tot++;
				else pre[x]=y;
			}
	for(int x=0; x<2; x++){
		for(int i=1; i<=n+m; i++)
			sum[i]=0;
		for(int i=1; i<=n; i++){
			int v=x;
			for(int j=1; j<=m; j++)
				if(s[i][j]<2) v^=s[i][j];
			sum[fnd(i)]^=v;
		}
		for(int j=1; j<=m; j++){
			int v=x;
			for(int i=1; i<=n; i++)
				if(s[i][j]<2) v^=s[i][j];
			sum[fnd(j+n)]^=v;
		}
		bool ok=1;
		for(int i=1; i<=n+m; i++)
			if(sum[i]) ok=0;
		if(ok) ans=(ans+Fstpw(2,tot))%mod;
	}
	return ;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%s",s[i]+1);
		for(int j=1; j<=m; j++)
			if(s[i][j]=='?') s[i][j]=2,k++;
			else s[i][j]-='0';
	}
	int N=n&1,M=m&1;
	if(!N&&!M) ans=Fstpw(2,k);
	if(!N&&M){
		int f[2]={1,1};
		for(int i=1; i<=n; i++){
			int s1=0,s2=0;
			for(int j=1; j<=m; j++)
				if(s[i][j]==2) s2++;
				else s1^=s[i][j];
			if(s2) f[0]=f[0]*Fstpw(2,s2-1)%mod,f[1]=f[1]*Fstpw(2,s2-1)%mod;
			else f[s1^1]=0;
		}
		ans=(f[0]+f[1])%mod;
	}
	if(N&&!M){
		int f[2]={1,1};
		for(int j=1; j<=m; j++){
			int s1=0,s2=0;
			for(int i=1; i<=n; i++)
				if(s[i][j]==2) s2++;
				else s1^=s[i][j];
			if(s2) f[0]=f[0]*Fstpw(2,s2-1)%mod,f[1]=f[1]*Fstpw(2,s2-1)%mod;
			else f[s1^1]=0;
		}
		ans=(f[0]+f[1])%mod;
	}
	if(N&&M) Odd();
	printf("%d\n",ans);
	return 0;
}