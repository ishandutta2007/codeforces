#include<cstdio>
#include<algorithm>
using namespace std;

int n,r1,r2,r3,r4;
int a[1000001];
long long f[1000001];
long long cc(int i,int w){
	return w==0?1ll*a[i]*r1+r3:min(1ll*a[i]*r1+r3,min(1ll*(a[i]+2)*r1,1ll*r2+r1));
}
int main(){
	scanf("%d%d%d%d%d",&n,&r1,&r2,&r3,&r4);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+cc(i,0);
		if(i==n)f[i]=min(f[i],f[i-2]+cc(i,0)+cc(i-1,1)+r4);
		if(i!=1)f[i]=min(f[i],f[i-2]+cc(i,1)+cc(i-1,1)+2*r4);
	}
	long long ans=~0ull>>1;
	long long cur=0;
	for(int i=n;i>=0;i--){
		ans=min(ans,cur+f[i]);
		if(i==n)cur+=min(cc(i,0),2*r4+cc(i,1));
		else cur+=cc(i,1)+r4;
	}
	printf("%lld\n",ans+1ll*(n-1)*r4);
}