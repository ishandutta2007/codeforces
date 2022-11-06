#include<bits/stdc++.h>
using namespace std;
#define re register
const int B=5;
int mod[B+1],ex[3010][B+1];
int rad()
{
	return (((unsigned int)rand()*(RAND_MAX+1))+rand())%2147483648u;
}
char ss[1010][1010];
int has[1010][B+1],a[1010];
int main()
{
	re int n;
	srand(time(0));
	for(re int i=1;i<=B;i++)
	{
		mod[i]=1e8+rad()%((int)9e8);
		for(re bool bo=1;;mod[i]++)
		{
			bo=0;
			for(re int j=2;(long long)j*j<=mod[i];j++)if(!(mod[i]%j)){bo=1;break;}
			if(!bo)break;
		}
	}
	scanf("%d",&n);
	for(re int I=1;I<=B;I++)
	{
		ex[1][I]=1;
		for(re int i=2;i<=n;i++)ex[i][I]=ex[i-1][I]*2%mod[I];
	}
	for(re int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(re int i=1;i<=n+1;i++)for(re int j=1;j<=n;j++)
	{
		if(i!=j)
		{
			ss[i][j]='1';
			for(re int I=1;I<=B;I++)has[i][I]=(has[i][I]+ex[j][I])%mod[I];
		}
		else ss[i][j]='0';
	}
	printf("%d\n",n+1);
	for(re int i=1;i<=n;i++)
	{
		re int nw=0;
		for(re int j=1;j<=n+1;j++)
		if(i!=j){
			for(re int I=1;I<=B;I++)
			{
				re int xx=(has[j][I]-ex[i][I]+mod[I])%mod[I];
				if(xx!=has[i][I])break;
				if(I==B)nw=j;
			}
		}
		for(re int j=1;j<=n+1;j++)
		{
			if(a[i]==n)break;
			if(i!=j&&j!=nw)
			{
				a[i]++;
				ss[j][i]='0';
				for(re int I=1;I<=B;I++)has[j][I]=(has[j][I]-ex[i][I]+mod[I])%mod[I];
			}
		}
	}
	for(re int i=1;i<=n+1;i++)puts(ss[i]+1);
}