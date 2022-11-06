#include<bits/stdc++.h>
#define re register
char A[100100],B[100100];
int ff[30],fa[30],fc[(1<<20)+11][21],fo[(1<<20)+11],lg[(1<<20)+11],ppc[(1<<20)+11];
int find(re int a){return fa[a]==a?a:fa[a]=find(fa[a]);}
int calc(re int S)
{
	re int ans=0;
	for(re int i1=(S-1)&S;;i1=(i1-1)&S)
	{
		re int i=S-i1;
		if(fo[i-(i&-i)])
		{
			fo[i]=1;
			re int x=lg[i&-i],s1=1<<x;
			for(re int ii=0;ii<20;ii++)
			{
				fc[i][ii]=fc[i-(i&-i)][ii];
				if(fc[i][ii]&(1<<x))s1|=1<<ii;
			}
			for(re int ii=0;ii<20;ii++)
			{
				if(ff[ii]&(1<<x))
				{
					fc[i][x]|=(1<<ii)|fc[i][ii];
				}
			}
			for(re int ii=0;ii<20;ii++)
			{
				if((fc[i][x]&(1<<ii))&&(fc[i][ii]&s1))
				{
					fo[i]=0;break;
				}
			}
			if(fo[i])
			{
				ans=std::max(ans,ppc[i]);
				for(re int ii=0;ii<20;ii++)
				{
					if(fc[i][ii]&(1<<x))fc[i][ii]|=fc[i][x];
				}
			}
		}
		else fo[i]=0;
		if(!i1)break;
	}
	return 2*ppc[S]-1-ans;
}
int main()
{
	re int n,t;
	scanf("%d",&t);
	lg[0]=-1;
	fo[0]=1;
	for(re int i=1;i<(1<<20);i++)lg[i]=lg[i/2]+1,ppc[i]=ppc[i/2]+(i&1);
	for(;t--;)
	{
		re int ans=0;
		scanf("%d",&n);
		scanf("%s%s",A+1,B+1);
		for(re int i=0;i<=20;i++)ff[i]=0,fa[i]=i;
		for(re int i=1;i<=n;i++)
		{
			if(A[i]!=B[i])ff[A[i]-'a']|=(1<<(B[i]-'a')),find(A[i]-'a'),find(B[i]-'a'),fa[fa[A[i]-'a']]=fa[B[i]-'a'];
		}
		for(re int i=0;i<20;i++)if(fa[i]==i)
		{
			re int S=0;
			for(re int j=0;j<20;j++)if(find(j)==i)S|=1<<j;
			ans+=calc(S);
		}
		printf("%d\n",ans);
	}
}