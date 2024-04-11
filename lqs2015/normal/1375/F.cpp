#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
long long a,b,c,d;
int x;
bool dc()
{
	long long aa,bb,cc;
	aa=a;bb=b;cc=c;
	if (aa>bb) swap(aa,bb);
	if (aa>cc) swap(aa,cc);
	if (bb>cc) swap(bb,cc);
	return (2ll*bb==aa+cc);
}
int main()
{
	scanf("%lld%lld%lld",&a,&b,&c);
	printf("First\n");
	fflush(stdout);
	d=3ll*max(a,max(b,c))-a-b-c;
	printf("%lld\n",d);
	fflush(stdout);
	scanf("%d",&x);
	if (x==1) a+=d;
	else if (x==2) b+=d;
	else c+=d;
	if (dc()) 
	{
		d=max(a,max(b,c));
		if ((a==d && x==1) || (b==d && x==2) || (c==d && x==3))
		{
			printf("%lld\n",(d-min(a,min(b,c)))/2);
			fflush(stdout);
			scanf("%d",&x);
			return 0;
		}
	}
	d=3ll*max(a,max(b,c))-a-b-c;
	printf("%lld\n",d);
	fflush(stdout);
	scanf("%d",&x);
	if (x==1) a+=d;
	else if (x==2) b+=d;
	else c+=d;
	printf("%lld\n",(max(a,max(b,c))-min(a,min(b,c)))/2);
	fflush(stdout);
	scanf("%d",&x);
	return 0;
	return Accepted;
}