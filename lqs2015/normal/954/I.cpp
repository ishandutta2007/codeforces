#include<bits/stdc++.h>
using namespace std;
const int MAXN=1<<18,mod=998244353;
int w[2][333333],S[333333],T[333333],n,m,sz,cnt,rev[333333],cur,gg[333333],G[333333],pa[11],lst;
long long c[333333];
bool f[222222][6][6];
char ss[222222],tt[222222];
const int maxn=1000;
char buffer[maxn],*s,*t;
inline char Get_Char()
{
    if(s==t)
    {
        t=(s=buffer)+fread(buffer,1,maxn,stdin);
        if(s==t) return EOF;
    }
    return *s++;
}
int read()
{
    char c;
    int re=0;
    for(c=Get_Char();c<'0'||c>'9';c=Get_Char());
    while(c>='0'&&c<='9')
           re=(re<<1)+(re<<3)+(c-'0'),c=Get_Char();
    return re;
}
int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=(long long)res*p%mod;
		p=(long long)p*p%mod;
	}
	return res;
}
void Init()
{
	w[0][0]=1;cur=binpow(3,(mod-1)/MAXN);
	for (int i=1;i<=MAXN;i++) w[0][i]=(long long)w[0][i-1]*cur%mod;
	w[1][0]=1;cur=binpow(3,mod-1-(mod-1)/MAXN);
	for (int i=1;i<=MAXN;i++) w[1][i]=(long long)w[1][i-1]*cur%mod;
}
void ntt(int d[],int flag)
{
	for (int i=0;i<sz;i++) c[i]=(long long)d[i];
	for (int i=0;i<sz;i++)
	{
		if (rev[i]>i) swap(c[i],c[rev[i]]);
	}
	for (int i=2;i<=sz;i<<=1)
	{
		int p=i>>1,fu=MAXN/i;
		for (int j=0;j<p;j++)
		{
			gg[j]=w[flag][j*fu];
		}
		for (int j=0;j<sz;j+=i)
		{
			for (int k=j;k<j+p;k++)
			{
				long long tmp1=c[k];
				long long tmp2=c[k+p]%mod*gg[k-j];
				c[k]=tmp1+tmp2;
				c[k+p]=tmp1-tmp2;
			}
		}
	}
	for (int j=0;j<sz;j++) c[j]%=mod;
	if (flag)
	{
		int wn=binpow(sz,mod-2);
		for (int i=0;i<sz;i++)
		{
			c[i]=c[i]*wn%mod;
		}
	}
	for (int i=0;i<sz;i++) d[i]=c[i];
}
void doit()
{
	ntt(S,0);
	ntt(T,0);
	for (int i=0;i<sz;i++) S[i]=(long long)S[i]*T[i]%mod;
	ntt(S,1);
} 
int root(int x)
{
	if (pa[x]!=x) pa[x]=root(pa[x]);
	return pa[x];
}
void Union(int x,int y)
{
	int rx=root(x),ry=root(y);
	if (rx==ry) return;
	pa[rx]=ry;
	lst++; 
}
int main()
{
	Init();
	scanf("%s%s",ss,tt);
	n=strlen(ss);m=strlen(tt);
	sz=1;
	while(sz<n+m)
	{
		sz<<=1;
		cnt++;
	}
	rev[0]=0;
	for (int i=1;i<sz;i++)
	{
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(cnt-1));
	}
	for (int i=0;i<6;i++)
	{
		for (int j=0;j<6;j++)
		{
			if (i==j) continue;
			memset(S,0,sizeof(S));
			memset(T,0,sizeof(T));
			for (int k=0;k<n;k++)
			{
				if (ss[k]=='a'+i) S[k]=1;
			}
			for (int k=0;k<m;k++)
			{
				if (tt[k]=='a'+j) T[m-k]=1;
			}
			doit();
			for (int k=0;k<=n-m;k++)
			{
				f[k][i][j]=S[k+m];
			}
		}
	}
	for (int i=0;i<=n-m;i++)
	{
		lst=0;
		for (int j=0;j<6;j++) pa[j]=j;
		for (int j=0;j<6;j++)
		{
			for (int k=0;k<6;k++)
			{
				if (f[i][j][k])
				{
					Union(j,k);
				}
			}
		}
		printf("%d ",lst);
	}
	printf("\n");
	return 0;
}