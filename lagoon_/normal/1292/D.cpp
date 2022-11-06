#include<bits/stdc++.h>
#define re register
int c[5010],c1[5010];
int R()
{
	re int x,c;
	for(c=getchar();!isdigit(c);c=getchar());x=c-'0';
	for(c=getchar();isdigit(c);c=getchar())x=x*10+c-'0';
	return x;
}
int pri[5010],vs[5010],nm[5010],qw[5010],vv[5010],vk[5010],cs[10010],cnt;
int main()
{
	re int n=R(),x;
	for(re int i=1;i<=n;i++)
	{
		x=R();c[x]++;c1[x]++;
	}
	for(re int i=2;i<=5000;i++)
	{
		if(!vs[i])pri[++cnt]=i;
		for(re int j=1;j<=cnt&&i*pri[j]<=5000;j++)
		{
			vs[i*pri[j]]=1;
			if(!(i%pri[j]))break;
		}
	}
	re long long ans=0;
	for(re int i=cnt;i;i--)
	{
		for(re int j=1;j<=5000;j++)
		if(c[j]){
			re int k=0;
			for(re int k1=j;k1>=pri[i];k1/=pri[i])k+=k1/pri[i];
			vv[j]=k;
			cs[k]+=c1[j];
		}
		cs[0]+=c1[0];
		re int nn=0,j1;
		for(j1=0;j1<=5000;j1++)
		{
			nn+=cs[j1];
			if(nn*2>=n)break;
		}
		for(re int j=0;j<=5000;j++)cs[j]=0;
		for(re int j=0;j<=5000;j++)if(c[j])
		{
			if(!vk[j])ans+=1ll*abs(vv[j]-j1)*c[j];
			else ans+=1ll*(vv[j]+j1)*c[j];
		}
		for(re int j=1;j<=5000;j++)
		if(c1[j]){
			if(vv[j]!=j1)c1[0]+=c1[j],c1[j]=0,vk[j]=1;
		}
	}
	printf("%lld\n",ans);
}