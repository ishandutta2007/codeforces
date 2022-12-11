#include<cstdio>
#include<map>
using namespace std;

map<int,int>a;
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	k=(1<<k)-1;
	long long ans=0;
	a[0]++;
	for(int i=1,x=0;i<=n;i++){
		int c;
		scanf("%d",&c);
		x^=c;
		if(a[x]<a[x^k])ans+=a[x],a[x]++;
		else ans+=a[x^k],a[x^k]++;
	}
	printf("%I64d\n",1ll*n*(n+1)/2-ans);
}