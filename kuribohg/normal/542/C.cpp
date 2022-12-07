#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=210;
LL gcd(LL a,LL b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
LL lcm(LL a,LL b)
{
	return a/gcd(a,b)*b;
}
LL LCM=1,limit,X;
int n,a[MAXN];
bool inCir[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int x=i,Len=0;
		for(int j=1;j<=n;j++) x=a[x];
		while(!inCir[x]) inCir[x]=true,x=a[x],Len++;
		if(Len) LCM=lcm(LCM,Len);
	}
	for(int i=1;i<=n;i++)
	{
		int x=i,Len=0;
		while(!inCir[x]) x=a[x],Len++;
		limit=max(limit,(LL)Len);
	}
	X=LCM;
	while(X<limit) X+=LCM;
	printf("%I64d\n",X);
	return 0;
}