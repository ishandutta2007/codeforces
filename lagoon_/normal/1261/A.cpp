#include<bits/stdc++.h>
using namespace std;
#define re register
char ss[1001000];
int main()
{
	re int t,n,k;
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",ss+1);
		printf("%d\n",n);k--;
		for(re int i=1;i<=2*k;i++)
		{
			re int j=i;
			for(;j<=n;j++)if((ss[j]=='(')==(i&1))break;
			if(j>n)puts("1 1");
			else printf("%d %d\n",i,j),reverse(ss+i,ss+j+1);
		}
		re int bk=2*k+1,ed=n/2+k;
		for(re int i=bk;i<=ed;i++)
		{
			re int j=i;
			for(;j<=n;j++)if((ss[j]=='('))break;
			if(j>n)puts("1 1");
			else printf("%d %d\n",i,j),reverse(ss+i,ss+j+1);
		}
		for(re int i=ed+1;i<=n;i++)
		{
			re int j=i;
			for(;j<=n;j++)if((ss[j]==')'))break;
			if(j>n)puts("1 1");
			else printf("%d %d\n",i,j),reverse(ss+i,ss+j+1);
		}
	}
}