#include <cstdio>
#include <cstring>
#include <algorithm>
#include<iostream>

using namespace std;

const int M=1000000,mo=998244353;

typedef long long LL;

int n,tot,pr[M+5],cnt[M+5],ans,Fac[M],Inv[M],Fac_Inv[M],P[M+5],mu[M+5];

bool bz[M+5];

char c;

int read()
{
    for (c=getchar();c<'0' || c>'9';c=getchar());
    int x=c-48;
    for (c=getchar();c>='0' && c<='9';c=getchar()) x=x*10+c-48;
    return x;
}

void init()
{
    mu[1]=1;
    for (int i=2;i<=M;i++)
    {
        if (!bz[i])
        {
            pr[tot++]=i; mu[i]=-1;
        }
        for (int j=0;j<tot;j++)
        {
            int I=i*pr[j];
            if (I>M) break;
            bz[I]=1;
            if (i%pr[j]==0)
            {
                mu[I]=0; break;
            }
            mu[I]=-mu[i];
        }
    }
}

int C(int n,int m)
{
    return (LL)Fac[n]*Fac_Inv[m]%mo*Fac_Inv[n-m]%mo;
}

int chk(int k)
{
    Fac[0]=Fac[1]=Fac_Inv[0]=Fac_Inv[1]=Inv[1]=1;ans=0;
    for (int i=2;i<=n;i++)
    {
        Fac[i]=(LL)Fac[i-1]*i%mo;
        Inv[i]=(LL)Inv[mo%i]*(mo-mo/i)%mo;
        Fac_Inv[i]=(LL)Fac_Inv[i-1]*Inv[i]%mo;
    }
    for (int i=1;i<=M;i++) if (cnt[i]>=k)
    {
        ans=(ans+mu[i]*C(cnt[i],k))%mo;
    }
    ans=(ans+mo)%mo;
    if (ans) return 1;return 0;
}
int main()
{
	init();scanf("%d",&n);int l=1,r=n,ans=0;
	for (int i=1;i<=n;i++)
    {
        int x=read(),j;
        for (j=1;j*j<x;j++) if (x%j==0)
        {
            cnt[j]++; cnt[x/j]++;
        }
        if (j*j==x) cnt[j]++;
    }
    while (l<=r)
    {
    	int mid=(l+r)>>1;if (chk(mid)) ans=mid,r=mid-1;else l=mid+1;
	}
	if (ans==0) printf("-1");else printf("%d",ans);
}