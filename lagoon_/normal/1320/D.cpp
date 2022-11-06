#include<bits/stdc++.h>
#define re register
const int MI=5e8,MX=1e9,tot=4;
bool pr(re int a)
{
	for(re int i=2;i*i<=a;i++)if(!(a%i))return 0;
	return 1;
}
int rad()
{
	return RAND_MAX<=32767?(rand()<<15)+rand():rand(); 
}
int mod[tot],ex[tot][200100];
int f[tot][200100][2],cn[200100];
char ss[200100];
int main()
{
	re int n,q;
	scanf("%d",&n);
	for(re int i=0;i<tot;i++)
	{
		mod[i]=(rad()%(MX-MI)+MI)|1;
		for(;!pr(mod[i]);mod[i]+=2);
	}
	for(re int i=0;i<tot;i++)
	{
		ex[i][0]=1;
		for(re int i1=1;i1<=n;i1++)ex[i][i1]=1ll*ex[i][i1-1]*31%mod[i];
	}
	scanf("%s",ss+1);
	for(re int i=0;i<tot;i++)
	{
		for(re int ii=0;ii<=1;ii++)
		{
			for(re int i1=1;i1<=n;i1++){
			if(ss[i1]=='0'){
				f[i][i1][ii]=(1ll*f[i][i1-1][ii]*31+(((i1&1)^ii)+1))%mod[i];
				cn[i1]=cn[i1-1]+1;
			}else
			{
				f[i][i1][ii]=f[i][i1-1][ii];
				cn[i1]=cn[i1-1];
			}
			}
		}
	}
	scanf("%d",&q);
	for(;q--;)
	{
		re int l1,l2,len,r1,r2,bo=1;
		scanf("%d%d%d",&l1,&l2,&len);
		r1=l1+len-1;r2=l2+len-1;
		if(cn[l1+len-1]-cn[l1-1]!=cn[l2+len-1]-cn[l2-1])bo=0,puts("No");
		else
		{
			re int tt=cn[l1+len-1]-cn[l1-1];
			for(re int i=0;i<tot;i++)
			{
				if(((f[i][r1][l1&1]-1ll*f[i][l1-1][l1&1]*ex[i][tt]%mod[i]+mod[i])%mod[i])
				!=((f[i][r2][l2&1]-1ll*f[i][l2-1][l2&1]*ex[i][tt]%mod[i]+mod[i])%mod[i]))
				{
					bo=0;puts("No");break;
				}
			}
		}
		if(bo)puts("Yes");
	}
}