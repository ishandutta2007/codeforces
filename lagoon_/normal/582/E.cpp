#include<bits/stdc++.h>
#define re register
char ss[1010];
const int mod=1e9+7;
int ll[1010],rr[1010],nv[1010],qw[150],f[310][(1<<16)+1],fk1[(1<<16)+1],fk2[(1<<16)+1],f1[(1<<16)+1],qc[10],qm,cnt,n;
int dfs(re int l,re int r)
{
	if(l==r){nv[++cnt]=qw[ss[l]];return cnt;}
	else
	{
		re int j=l+1,sv=1,k=++cnt;
		for(;sv;j++)if(ss[j]==')')sv--;else if(ss[j]=='(')sv++;
		ll[k]=dfs(l+1,j-2);sv=1;
		nv[k]=qw[ss[j]];
		rr[k]=dfs(j+2,r-1);
		return k;
	}
}
void OR(re int*a,re int*b)
{
	memcpy(fk1,a,sizeof(int)*(1<<n));
	memcpy(fk2,b,sizeof(int)*(1<<n));
	for(re int i=0;i<n;i++)
	{
		for(re int j=0;j<(1<<n);j+=1<<i+1)
		{
			for(re int k=j;k<j+(1<<i);k++)
			{
				fk1[k+(1<<i)]=(fk1[k+(1<<i)]+fk1[k])%mod;
				fk2[k+(1<<i)]=(fk2[k+(1<<i)]+fk2[k])%mod;
			}
		}
	}
	for(re int j=0;j<(1<<n);j++)f1[j]=(long long)fk1[j]*fk2[j]%mod;
	for(re int i=0;i<n;i++)
	{
		for(re int j=0;j<(1<<n);j+=1<<i+1)
		{
			for(re int k=j;k<j+(1<<i);k++)
			{
				f1[k+(1<<i)]=(f1[k+(1<<i)]-f1[k]+mod)%mod;
			}
		}
	}
}
void AND(re int*a,re int*b)
{
	memcpy(fk1,a,sizeof(int)*(1<<n));
	memcpy(fk2,b,sizeof(int)*(1<<n));
	for(re int i=0;i<n;i++)
	{
		for(re int j=0;j<(1<<n);j+=1<<i+1)
		{
			for(re int k=j;k<j+(1<<i);k++)
			{
				fk1[k]=(fk1[k+(1<<i)]+fk1[k])%mod;
				fk2[k]=(fk2[k+(1<<i)]+fk2[k])%mod;
			}
		}
	}
	for(re int j=0;j<(1<<n);j++)f1[j]=(long long)fk1[j]*fk2[j]%mod;
	for(re int i=0;i<n;i++)
	{
		for(re int j=0;j<(1<<n);j+=1<<i+1)
		{
			for(re int k=j;k<j+(1<<i);k++)
			{
				f1[k]=(f1[k]-f1[k+(1<<i)]+mod)%mod;
			}
		}
	}
}
void dfs1(re int a)
{
	if(ll[a])
	{
		dfs1(ll[a]),dfs1(rr[a]);
		if(nv[a]==1||nv[a]==-1)
		{
			AND(f[ll[a]],f[rr[a]]);
			for(re int i=0;i<(1<<n);i++)f[a][i]=f1[i];
		}
		if(nv[a]==2||nv[a]==-1)
		{
			OR(f[ll[a]],f[rr[a]]);
			for(re int i=0;i<(1<<n);i++)f[a][i]=(f[a][i]+f1[i])%mod;
		}
	}else
	{
		if(nv[a]==-1)for(re int i=1;i<=8;i++)f[a][qc[i]]++;
		else f[a][qc[nv[a]]]=1;
	}
}
int main()
{
	re int m,x;
	qw['A']=1;qw['B']=2;qw['C']=3;qw['D']=4;
	qw['a']=5;qw['b']=6;qw['c']=7;qw['d']=8;
	qw['&']=1;qw['|']=2;qw['?']=-1;
	scanf("%s%d",ss+1,&n);
	m=strlen(ss+1);
	dfs(1,m);
	for(re int i=1;i<=n;i++)
	{
		for(re int j=1;j<=4;j++)scanf("%d",&x),qc[j]|=x<<i-1,qc[j+4]|=(!x)<<i-1;
		scanf("%d",&x);qm|=x<<i-1;
	}
	dfs1(1);
	printf("%d\n",f[1][qm]);
}