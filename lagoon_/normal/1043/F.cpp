#include<bits/stdc++.h>
using namespace std;
#define re register
int a[300100],pri[30010],cnt,miu[300100],num[300100],mod[3],fac[300100][3],ifac[300100][3];
bool tnm[300010];
int ex(re int a,re int b,re int md)
{
	re int ans=1;
	for(;b;b>>=1,a=(long long)a*a%md)if(b&1)ans=(long long)ans*a%md;
	return ans;
}
int main()
{
	srand(time(0));
	re int n;
	scanf("%d",&n);tnm[1]=1;
	for(re int i=0;i<=0;i++)
	{
		mod[i]=rand()%1000000000+499999999;
		re bool bo=1;
		while(bo)
		{
			mod[i]++;bo=0;
			for(re int i1=2;(long long)i1*i1<=mod[i];i1++)if(!(mod[i]%i1)){bo=1;break;}
		}
		fac[0][i]=1;
		for(re int i1=1;i1<=n;i1++)fac[i1][i]=(long long)fac[i1-1][i]*i1%mod[i];
		ifac[n][i]=ex(fac[n][i],mod[i]-2,mod[i]);
		for(re int i1=n;i1;i1--)ifac[i1-1][i]=(long long)ifac[i1][i]*i1%mod[i];
	}
	for(re int i=2;i<=300000;i++)
	{
		if(!tnm[i])tnm[i]=1,pri[++cnt]=i,miu[i]=1;
		for(re int j=1;j<=cnt&&i*pri[j]<=300000;j++)
		{
			if(!(i%pri[j])){tnm[i*pri[j]]=1;break;}
			else tnm[i*pri[j]]=1,miu[i*pri[j]]=-miu[i];
		}
	}
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);if(a[i]==1){puts("1");return 0;}
		num[a[i]]++;
	}for(re int i=2;i<=300000;i++)for(re int j=2*i;j<=300000;j+=i)num[i]+=num[j];
	for(re int i=1;i<=n&&i<=8;i++)
	{
		for(re int ii=0;ii<=0;ii++)
		{
			re int tot=0;
			for(re int i1=2;i1<=300000;i1++)
			if(num[i1]>=i){
				tot=(tot+(long long)fac[num[i1]][ii]*ifac[i][ii]%mod[ii]*ifac[num[i1]-i][ii]%mod[ii]*(mod[ii]+miu[i1]))%mod[ii];
			}if(tot!=(long long)fac[n][ii]*ifac[n-i][ii]%mod[ii]*ifac[i][ii]%mod[ii]){printf("%d\n",i);return 0;}
		}
	}puts("-1");
}