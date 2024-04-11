#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002,M=1000000007,M0=1000000006;
typedef long long ll;
ll n,m,i,j,p[N],s1[N],s2[N],ans;
struct pr{
	ll val,cnt;
}a[N];
void init(){
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",p+i);
	sort(p+1,p+n+1);
}
ll ksm(ll x,ll p){
	ll s=1;
	while(p){
		if(p%2)
			s=s*x%M;
		p/=2;
		x=x*x%M;
	}
	return s;
}
void work(){
	for(i=1;i<=n;i=j+1){
		for(j=i;p[i]==p[j+1];j++);
		a[++m]=(pr){p[i],j-i+1};
	}
	s1[0]=1;
	for(i=1;i<=m;i++)
		s1[i]=s1[i-1]*(a[i].cnt+1)%M0;
	s2[m+1]=1;
	for(i=m;i;i--)
		s2[i]=s2[i+1]*(a[i].cnt+1)%M0;
	ans=1;
	for(i=1;i<=m;i++)
		ans=ans*ksm(a[i].val,a[i].cnt*(a[i].cnt+1)/2%M0*s1[i-1]%M0*s2[i+1]%M0)%M;
	printf("%lld",ans);
}
int main(){
	init();
	work();
}