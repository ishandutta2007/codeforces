#include<cstdio>
const int N=200002,M=998244353;
int n,i,x,a[N],b[N],c[N],s1[N],s2[N],s3[N],s4[N],cnt,inv[N];
long long  ans;
int main(){
	scanf("%d",&n);
	for(inv[1]=1,i=2;i<=n||i<=4;i++)
		inv[i]=1ll*(M-M/i)*inv[M%i]%M;
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]!=-1){
			for(x=a[i]+1;x<=n;x+=x&-x)
				ans=(ans+c[x])%M;
			for(x=a[i];x;x-=x&-x)
				c[x]++;
			b[a[i]]=1;
		}
		else
			cnt++;
		s1[i]=s1[i-1]+(a[i]==-1);
	}
	ans=(ans+1ll*cnt*(-1+cnt)%M*inv[4])%M;
	for(i=n;i;i--)
		s2[i]=s2[i+1]+(a[i]==-1);
	for(i=1;i<=n;i++)
		s3[i]=s3[i-1]+(b[i]==0);
	for(i=n;i;i--)
		s4[i]=s4[i+1]+(b[i]==0);
	for(i=1;i<=n;i++)
		if(a[i]>0){
			ans=(ans+1ll*s1[i]*s4[a[i]]%M*inv[cnt])%M;
			ans=(ans+1ll*s2[i]*s3[a[i]]%M*inv[cnt])%M;
		}
	printf("%lld",ans);
}