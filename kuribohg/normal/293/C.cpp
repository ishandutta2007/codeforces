#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=10000010;
int tot;
LL n,d[MAXN],ans;
int main()
{
	scanf("%I64d",&n);
	if(n%3!=0) {puts("0");return 0;}
	n/=3;
	for(int i=2;i<=10000000;i++)
		if(n%i==0) d[++tot]=i;
	for(int i=1;i<=tot;i++)
	{
		LL x=d[i];
		if(x*x*x>n) continue;
		for(int j=i;j<=tot;j++)
		{
			LL y=d[j];
			if(x*y*y>n) continue;
			if(n%(x*y)!=0) continue;
			LL z=n/x/y;
			if((x+y+z)%2!=0) continue;
			LL sum=(x+y+z)>>1;
			LL a[3];
			a[0]=sum-x,a[1]=sum-y,a[2]=sum-z;
			if(a[0]<=0||a[1]<=0||a[2]<=0) continue;
			sort(a,a+3);
			int tot=unique(a,a+3)-a;
			if(tot==3) ans+=6;
			else if(tot==2) ans+=3;
			else ans++;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}