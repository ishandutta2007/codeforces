#include<cstdio>
const int M=1000000007;
typedef long long ll;
ll n,m,l,r,ans,x;
int main(){
	scanf("%lld%lld",&n,&m);
	ans=n%M*(m%M);
	x=M-M/2;
	for(l=1;l<=m&&l<=n;l=r+1){
		r=n/(n/l);
		if(r>m)r=m;
		ans=((ans-((l+r)%M)*((r-l+1)%M)%M*x%M*(n/l%M)%M)%M+M)%M;
	}
	printf("%lld",ans);
}