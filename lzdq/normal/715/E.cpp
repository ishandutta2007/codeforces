#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
typedef long long ll;
using namespace std;
const int MAXN=260,mod=998244353,G=3,invG=(mod+1)/3;
int n,p[MAXN],q[MAXN];
ll fac[MAXN],inv[MAXN];
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
void ntt(int *a,int n,int tp){
	int bit=0;
	while(1<<bit<n) bit++;
	static int rev[MAXN<<2];
	for(int i=1; i<n; i++){
		rev[i]=rev[i>>1]>>1|((i&1)<<bit-1);
		if(i<rev[i]) swap(a[i],a[rev[i]]);
	}
	for(int mid=1; mid<n; mid<<=1){
		ll w=1,w1=Fstpw(tp==1?G:invG,(mod-1)/mid/2);
		for(int j=0; j<mid; j++,w=w*w1%mod)
			for(int i=0; i<n; i+=mid*2){
				int x=a[i+j],y=w*a[i+j+mid]%mod;
				a[i+j]=(x+y)%mod;
				a[i+j+mid]=(x-y+mod)%mod;
			}
	}
	if(tp==-1){
		ll t=Fstpw(n,mod-2);
		for(int i=0; i<n; i++)
			a[i]=a[i]*t%mod;
	}
	return ;
}
int pre[MAXN],suf[MAXN];
bool hp[MAXN],hq[MAXN],vis[MAXN];
int lp,s[2][2],lk;
int f[MAXN>>1][MAXN][MAXN],ans[MAXN];
int DP(ll x){
	for(int i=0; i<=s[1][1]; i++)
		for(int j=0; j<=s[1][0]+s[1][1]; j++)
			for(int k=0; k<=s[0][1]+s[1][1]; k++)
				f[i][j][k]=0;
	f[s[1][1]][s[1][0]][s[0][1]]=Fstpw(x,lp);
	for(int a=s[1][1]; ~a; a--)
		for(int b=s[1][0]+s[1][1]-a; ~b; b--)
			for(int c=s[0][1]+s[1][1]-a; ~c; c--){
				int d=a+s[0][0]-s[1][1];
				ll t=f[a][b][c];
				assert(d>=a);
				if(c) (f[a][b][c-1]+=t*(a+d+(c-1)+x)%mod*c%mod)%=mod;
				if(b) (f[a][b-1][c]+=t*(a+d+(b-1)+x)%mod*b%mod)%=mod;
				if(a){
					(f[a-1][b+1][c]+=t*a*d%mod)%=mod;
					(f[a-1][b][c+1]+=t*a*d%mod)%=mod;
				}
			}
	ll res=f[0][0][0]*inv[s[1][1]*2+s[1][0]+s[0][1]]%mod;
	res=res*fac[s[0][0]-s[1][1]]%mod;
	assert(lk==s[0][0]-s[1][1]);
	for(int i=0; i<s[0][0]-s[1][1]; i++)
		res=res*(x+i)%mod;
	return res;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%d",&n);
	fac[0]=1;
	for(int i=1; i<=n; i++)
		fac[i]=fac[i-1]*i%mod;
	inv[n]=Fstpw(fac[n],mod-2);
	for(int i=n; i; i--)
		inv[i-1]=inv[i]*i%mod;
	for(int i=1; i<=n; i++)
		scanf("%d",p+i);
	for(int i=1; i<=n; i++)
		scanf("%d",q+i);
	for(int i=1; i<=n; i++){
		if(p[i]&&q[i]) pre[q[i]]=p[i],suf[p[i]]=q[i];
		else if(p[i]) hp[p[i]]=1;
		else if(q[i]) hq[q[i]]=1;
		else lk++;
	}
	for(int u=1; u<=n; u++)
		if(!pre[u]){
			int v=u;
			vis[u]=1;
			while(suf[v]) vis[v=suf[v]]=1;
			s[hq[u]][hp[v]]++;
		}
	for(int u=1; u<=n; u++)
		if(!vis[u]){
			int v=u;
			vis[u]=1;
			while(suf[v]!=u) vis[v=suf[v]]=1;
			lp++;
		}
	ll w1=Fstpw(G,(mod-1)/256),w=1;
	for(int i=0; i<256; i++,w=w*w1%mod)
		ans[i]=DP(w);
	ntt(ans,256,-1);
	for(int i=n; i; i--)
		printf("%d ",ans[i]);
	puts("");
	return 0;
}