#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=5e5+5,mod=1e9+7;
int n;
struct Point{
	ll x,y;
}p[MAXN];
Point operator -(Point a,Point b){
	return Point{a.x-b.x,a.y-b.y};
}
ll operator *(Point a,Point b){
	return a.x*b.y-a.y*b.x;
}
ll ar;
int ans;
struct {
	int a[MAXN*2],s1[MAXN*2],s2[MAXN*2],s3[MAXN*2];
	int& operator [](int x){
		return a[x];
	}
	void Init(){
		for(int i=1; i<=n; i++)
			a[i+n]=a[i];
		for(int i=1; i<=n*2; i++){
			s1[i]=(s1[i-1]+a[i])%mod;
			s2[i]=(s2[i-1]+s1[i])%mod;
		}
		for(int i=n*2; i; i--)
			s3[i]=(1ll*s3[i+1]+s1[n*2]-s1[i-1]+mod)%mod;
		return ;
	}
	ll Query1(int l,int r){
		if(l>r) r+=n;
		ll res=s3[l]-s3[r+1]-(r-l+1ll)*(s1[n*2]-s1[r]);
		return (res%mod+mod)%mod;
		/*
		ll res=0;
		for(int i=l; i<=r; i++)
			res+=a[i]*(i-l+1ll)%mod;
		return res%mod;
		*/
	}
	ll Query2(int l,int r){
		if(l>r) r+=n;
		ll res=s2[r]-s2[l-1]-(r-l+1ll)*s1[l-1];
		return (res%mod+mod)%mod;
		/*
		ll res=0;
		for(int i=l; i<=r; i++)
			res+=a[i]*(r-i+1ll)%mod;
		return res%mod;
		*/
	}
}a,b,c;
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%lld%lld",&p[i].x,&p[i].y);
	reverse(p+1,p+n+1);
	p[n+1]=p[1];
	for(int i=1; i<=n; i++){
		ar+=p[i]*p[i+1];
		a[i]=(p[i].y-p[i+1].y+mod*2)%mod;
		b[i]=(p[i+1].x-p[i].x+mod*2)%mod;
		c[i]=(p[i]*p[i+1]%mod+mod)%mod;
	}
	a.Init();
	b.Init();
	c.Init();
	ll s=0;
	for(int i=1,j=1; i<=n; i++){
		while(s+(p[j]-p[i])*(p[j+1]-p[i])<=ar/2){
			s+=(p[j]-p[i])*(p[j+1]-p[i]);
			j=j%n+1;
		}
		ans=(ans+p[i].x*a.Query2(i,j-1)%mod+mod)%mod;
		ans=(ans+p[i].y*b.Query2(i,j-1)%mod+mod)%mod;
		ans=(ans+c.Query2(i,j-1))%mod;
		ans=(ans+p[i].x*a.Query1(j+1,i-1)%mod+mod)%mod;
		ans=(ans+p[i].y*b.Query1(j+1,i-1)%mod+mod)%mod;
		ans=(ans+c.Query1(j+1,i-1))%mod;
		s-=(p[i]-p[j])*(p[i+1]-p[j]);
	}
	ans=(ar%mod*n%mod*(n-3)%mod*(mod+1)/2%mod-ans+mod)%mod;
	printf("%d\n",ans);
	return 0;
}