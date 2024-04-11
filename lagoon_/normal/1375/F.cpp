#include<bits/stdc++.h>
#define re register
long long a[1010];
long long abss(re long long x){return x>0?x:-x;}
int main()
{
	scanf("%lld%lld%lld",&a[1],&a[2],&a[3]);
	puts("First");
	re long long x,x1=1<<30,x2=0;
	printf("%lld\n",x1);
	fflush(stdout);
	scanf("%lld",&x);
	if(x==0)return 0;
	a[x]+=x1;
	for(re int i=1;i<=3;i++)if(i!=x)x2+=a[x]-a[i];
	printf("%lld\n",x2);
	fflush(stdout);
	scanf("%lld",&x);
	if(x==0)return 0;
	a[x]+=x2;
	x2=std::min(abss(a[1]-a[2]),abss(a[2]-a[3]));
	printf("%lld\n",x2);
}