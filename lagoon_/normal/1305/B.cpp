#include<bits/stdc++.h>
#define re register
char ss[200100];
int main()
{
	re int n,ans=0,nn=0,nw=0;
	scanf("%s",ss+1);
	n=strlen(ss+1);
	for(re int i=1;i<=n;i++)
	{
		if(ss[i]=='(')nn=1;
		if(ss[i]==')'&&nn==1)ans=1<<30;
	}
	if(ans==0)puts("0"),exit(0);
	puts("1");
	for(re int i=1;i<=n;i++)nw+=(ss[i]==')');
	nn=0;
	for(re int i=1;i<=nw;i++)nn+=(ss[i]=='(');
	printf("%d\n",nn*2);
	for(re int i=1;i<=nw;i++)if(ss[i]=='(')printf("%d ",i);
	for(re int i=nw+1;i<=n;i++)if(ss[i]==')')printf("%d ",i);
}