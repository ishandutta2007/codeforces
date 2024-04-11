#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define re register
int num[1000100];
int main()
{
	re int n,m,k,a,a1,a2,ans;
	scanf("%d%d%d",&n,&m,&k);k--;
	if(n==1){puts("1");return 0;}
	scanf("%d",&a1);a2=a1;
	for(re int i=1;i<n;i++)
	{
		scanf("%d",&a);
		num[i]=a-a1-1;
		a1=a;
	}
	ans=a-a2+1;
	sort(num+1,num+n);
	for(re int i=1;i<=k;i++)
	{
		ans-=num[n-i];
	}printf("%d",ans);
}