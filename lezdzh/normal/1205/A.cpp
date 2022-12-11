#include<cstdio>
#include<algorithm>
using namespace std;

int a[200001];
long long s[200001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		if(i&1)a[i]=i*2-1,a[i+n]=i*2;
		else a[i]=i*2,a[i+n]=i*2-1;
	for(int i=1;i<=2*n;i++)
		s[i]=s[i-1]+a[i];
	long long mx=-1,mn=~0ull>>1;
	for(int i=0;i<=n;i++){
		long long o1=s[i+n]-s[i],o2=1ll*n*(2*n+1)-o1;
//		printf("%lld %lld\n",o1,o2);
		mx=max(mx,max(o1,o2));
		mn=min(mn,min(o1,o2));
	}
	if(mx-mn>1)printf("NO\n");
	else{
		printf("YES\n");
		for(int i=1;i<=2*n;i++)
			printf("%d%c",a[i],i==2*n?'\n':' ');
	}
}