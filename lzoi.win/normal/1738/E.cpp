#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5,mod=998244353;
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
int n,a[MAXN];
ll s1[MAXN],s2[MAXN];
ll fac[MAXN],inv[MAXN];
inline ll C(int n,int m){
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int f[MAXN],ans;
int main(){
	//freopen("in","r",stdin);
	n=1e5;
	fac[0]=1;
	for(int i=1; i<=n; i++)
		fac[i]=fac[i-1]*i%mod;
	inv[n]=Fstpw(fac[n],mod-2);
	for(int i=n; i; i--)
		inv[i-1]=inv[i]*i%mod;
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i),s1[i]=s1[i-1]+a[i];
		s2[n+1]=0;
		for(int i=n; i; i--)
			s2[i]=s2[i+1]+a[i];
		ans=1;
		for(int i=1,j=n; i<j; i++){
			while(j&&s1[i]>s2[j]) j--;
			if(i>=j) break;
			if(s1[i]!=s2[j]) continue;
			int x=1,y=1;
			while(i+x<=n&&s1[i+x]==s1[i]) x++;
			while(j-y>0&&s2[j-y]==s2[j]) y++;
			i+=x-1;
			j-=y-1;
			if(i>=j){
				assert(x==y);
				//printf("x=y %d\n",x);
				ans=ans*Fstpw(2,min(x,n-1))%mod;
				break;
			}
			ll sum=0;
			for(int k=0; k<=min(x,y); k++)
				sum+=C(x,k)*C(y,k)%mod;
			ans=sum%mod*ans%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}