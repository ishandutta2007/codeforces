#include<cstdio>
const int N=406002,M=203000,P=1000000007;
typedef long long ll;
int a,b,k,t,o,u,v,i,j,p[N];
ll f[N],g[N],s[N],sum,ans;
int main(){
	scanf("%d%d%d%d",&a,&b,&k,&t);
	o=2*k;
	f[a-b+M]=1;
	while(t--){
		for(i=1;i<N;i++)
			s[i]=s[i-1]+f[i];
		sum=0;
		for(i=0;i<o;i++)
			sum+=(f[i]+f[2*o-i])*(i+1);
		sum+=f[o]*(o+1);
		for(i=o;i+o+1<N;i++){
			f[i]=sum%P;
			sum-=s[i]-(i>o?s[i-o-1]:0);
			sum+=s[i+o+1]-s[i];
		}
	}
	for(i=M+1;i<N;i++)
		ans+=f[i];
	printf("%lld",ans%P);
	//while(1);
}