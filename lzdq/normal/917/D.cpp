#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=105,mod=1e9+7;
int n,w[MAXN][MAXN];
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int Gauss(int x){
	x%=mod;
	static int a[MAXN][MAXN];
	for(int i=1; i<=n; i++){
		a[i][i]=0;
		for(int j=1; j<=n; j++)
			if(i!=j) a[i][j]=mod-(w[i][j]?x:1),a[i][i]=(a[i][i]-a[i][j]+mod)%mod;
		//for(int j=1; j<=n; j++) printf("%d ",a[i][j]);puts("");
	}
	ll res=1;
	for(int i=2; i<=n; i++){
		int p=0;
		for(int j=i; j<=n; j++)
			if(!p&&a[j][i]) p=j;
		if(p!=i) swap(a[i],a[p]),res=mod-res;
		else if(!p) return puts("ff"),0;
		ll inv=Fstpw(a[i][i],mod-2);
		for(int j=i+1; j<=n; j++){
			ll t=inv*a[j][i]%mod;
			for(int k=i; k<=n; k++)
				a[j][k]=(a[j][k]-t*a[i][k]%mod+mod)%mod;
		}
		res=res*a[i][i]%mod;
	}
	return res;
}
struct Equal{
	int a[MAXN],b;
	void Print(){
		puts("Equation");
		for(int i=1; i<=n; i++) printf("%d ",a[i]);
		printf("= %d\n",b);
	}
}eq[MAXN];
Equal operator *(Equal a,ll b){
	for(int i=1; i<=n; i++)
		a.a[i]=a.a[i]*b%mod;
	a.b=a.b*b%mod;
	return a;
}
Equal operator -=(Equal &a,Equal b){
	for(int i=1; i<=n; i++)
		a.a[i]=(a.a[i]-b.a[i]+mod)%mod;
	a.b=(a.b-b.b+mod)%mod;
	return a;
}
int ans[MAXN];
int main(){
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		w[u][v]=w[v][u]=1;
	}
	for(int i=1; i<=n; i++){
		int x=rand();
		for(int j=1,y=1; j<=n; j++,y=1ll*y*x%mod)
			eq[i].a[j]=y;
		eq[i].b=Gauss(x);
		//eq[i].Print();
	}
	for(int i=1; i<=n; i++){
		int p=0;
		for(int j=i; j<=n; j++)
			if(!p&&eq[j].a[i]) p=j;
		if(p!=i) swap(eq[i],eq[p]);
		ll inv=Fstpw(eq[i].a[i],mod-2);
		eq[i]=eq[i]*inv;
		for(int j=i+1; j<=n; j++)
			eq[j]-=eq[i]*eq[j].a[i];
	}
	for(int i=n;i;i--){
		ans[i]=eq[i].b;
		for(int j=i+1; j<=n; j++)
			ans[i]=(ans[i]-1ll*ans[j]*eq[i].a[j]%mod+mod)%mod;
	}
	for(int i=1; i<=n; i++)
		printf("%d ",ans[i]);
	return 0;
}