#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=4e5+5;
typedef long long ll;
int n,a[MAXN];
ll k,b[MAXN],s[MAXN],ans,sum;
ll calc(ll x){
	return x*(x+1)>>1;
}
int main(){
	scanf("%d%lld",&n,&k);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i),a[n+i]=a[i];
	n<<=1;
	for(int i=1,j=1; i<=n; i++){
		b[i]=calc(a[i]);
		s[i]=s[i-1]+a[i];
		sum+=b[i];
		while(s[i]-s[j]>=k) sum-=b[j++];
		if(s[i]-s[j-1]-k>=0) ans=max(ans,sum-calc(s[i]-s[j-1]-k));
		//printf("j %d sum %lld\n",j,sum);
	}
	printf("%lld\n",ans);
	return 0;
}