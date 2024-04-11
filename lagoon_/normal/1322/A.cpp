#include<bits/stdc++.h>
#define re register
char ss[1001000];
int main()
{
	re int n,nw=0,nk=0,ans=0;
	scanf("%d%s",&n,ss+1);
	for(re int i=1;i<=n;i++)
	{
		if(ss[i]==')')
		{
			if(nw==0)nk=i;
			nw--;
		}if(ss[i]=='(')
		{
			if(nw==-1)ans+=i-nk+1;
			nw++;
		}
	}
	if(nw!=0)puts("-1");
	else printf("%d\n",ans);
}