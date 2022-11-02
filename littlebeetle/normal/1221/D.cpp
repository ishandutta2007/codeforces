#include<cstdio>
const int N=300002;
const long long Inf=1ll<<60;
typedef long long ll;
ll T,n,a[N],b[N],i,f[N][3],j,k;
ll min(ll x,ll y){
	return x<y?x:y;
}
int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(i=0;i<=n;i++)
			for(j=0;j<3;j++)
				f[i][j]=Inf;
		for(i=1;i<=n;i++)
			scanf("%lld%lld",a+i,b+i);
		f[0][0]=0;
		for(i=1;i<=n;i++)
			for(j=0;j<3;j++)
				for(k=0;k<3;k++)
					if(a[i]+j!=a[i-1]+k)
						f[i][j]=min(f[i][j],f[i-1][k]+j*b[i]);
		printf("%lld\n",min(min(f[n][0],f[n][1]),f[n][2]));
	}
}