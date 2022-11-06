#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
#define re register
#define cmin(a,b) (a>(b)?a=(b):0)
#define cmax(a,b) (a<(b)?a=(b):0)
#define dmax(a,b) ((a)>(b)?(a):(b))
#define dmin(a,b) ((a)<(b)?(a):(b))
int ff[100100];
long long A,B;
long long cc(int*a,re int n,re int len,re int l)
{
	if(!n)return A;
	if(len==1)return (long long)B*n;
	re int len1=len>>1,n1=0,n2;
	for(re int i=0;i<n;i++)if(a[i]<=l+len1)n1++;
	int fa[n1],fb[n-n1];n1=n2=0;
	for(re int i=0;i<n;i++)if(a[i]<=l+len1)fa[n1++]=a[i];else fb[n2++]=a[i];
	re long long aa=cc(fa,n1,len1,l),bb=cc(fb,n2,len1,l+len1),ca;
	ca=(long long)B*n*len;aa+=bb;
	return dmin(ca,aa);
}
int main()
{
	re int n,k;
	scanf("%d%d%d%d",&n,&k,&A,&B);
	for(re int i=1;i<=k;i++)scanf("%d",&ff[i]);
	printf("%lld",cc(ff+1,k,1<<n,0));
}