#include<bits/stdc++.h>
using namespace std;
#define re register
int a[110],b[110];
char ss[110];
int main()
{
	re int n,mx=0,nw=0;
	scanf("%d",&n);
	scanf("%s",ss+1);
	for(re int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]),nw+=ss[i]=='1';
	mx=nw;
	for(re int i=1;i<=100000;i++)
	{
		for(re int i1=1;i1<=n;i1++)if(i>=b[i1]&&(!((i-b[i1])%a[i1])))
		{
			if(ss[i1]=='1')nw--,ss[i1]='0';
			else nw++,ss[i1]='1';
		}
		if(mx<nw)mx=nw;
	}
	printf("%d\n",mx);
}