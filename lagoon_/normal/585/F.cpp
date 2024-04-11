#include<bits/stdc++.h>
#define re register
const int mod=1e9+7;
char ss[25010],s1[2010],s2[2010];
int fa[25010],nx[25010][10],la[25010],pp[25010],q[25010],ta,cnt=1,f[25010][2][2],g[25010][2][2];
int main()
{
	re int n,d;
	scanf("%s%s%s",ss+1,s1+1,s2+1);
	n=strlen(ss+1);d=strlen(s1+1);
	for(re int i=1;i+d/2-1<=n;i++)
	{
		re int j1=1;
		for(re int j=i;j<=i+d/2-1;j++)
		{
			if(!nx[j1][ss[j]-'0'])nx[j1][ss[j]-'0']=++cnt,fa[cnt]=j1;
			j1=nx[j1][ss[j]-'0'];
		}
		pp[j1]=1;
	}
	q[ta=1]=1;
	for(re int i=1;i<=ta;i++)
	{
		re int x=q[i];
		for(re int j=0;j<10;j++)if(nx[x][j])
		{
			re int y=nx[x][j];
			q[++ta]=y;
			if(x!=1)la[y]=nx[la[x]][j];
			else la[y]=1;
			if(!pp[y])pp[y]=pp[la[y]];
		}else if(x!=1)nx[x][j]=nx[la[x]][j];
		else nx[x][j]=1;
	}
	f[1][1][1]=1;
	for(re int i1=1;i1<=d;i1++)
	{
		memcpy(g,f,sizeof(f));
		memset(f,0,sizeof(f));
		re int x1=s1[i1]-'0',x2=s2[i1]-'0';
		for(re int i=0;i<=cnt;i++)
		{
			for(re int j=0;j<=1;j++)
				for(re int k=0;k<=1;k++)
				if(g[i][j][k]){
					for(re int ii=(j?x1:0);ii<=(k?x2:9);ii++)
					{
						re int jj=j&(ii==x1),kk=k&(ii==x2);
						if(pp[nx[i][ii]])f[0][jj][kk]=(f[0][jj][kk]+g[i][j][k])%mod;
						else f[nx[i][ii]][jj][kk]=(f[nx[i][ii]][jj][kk]+g[i][j][k])%mod;
					}
				}
		}
	}
	printf("%lld\n",((long long)f[0][0][0]+f[0][0][1]+f[0][1][0]+f[0][1][1])%mod);
}