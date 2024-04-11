#include<bits/stdc++.h>
using namespace std;
#define re register
char ss[1001000],ss1[1001000];
int main()
{
	re int t,n;
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%d",&n);
		scanf("%s",ss+1);
		re int x1,y1;
		for(re int i=0;i<=9;i++)
		{
			x1=0,y1=i;
			for(re int i1=1;i1<=n;i1++)
			{
				if(ss[i1]-'0'>=y1)y1=ss[i1]-'0',ss1[i1]='2';
				else if(ss[i1]-'0'<=i&&ss[i1]-'0'>=x1)x1=ss[i1]-'0',ss1[i1]='1';
				else {y1=-1;break;}
			}
			if(y1!=-1)
			{
				ss1[n+1]='\0';
				printf("%s\n",ss1+1);
				break;
			}
		}
		if(y1==-1)puts("-");
	}
}