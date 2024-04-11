#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
char str[510];
int K,A[20],B[20],C[20],D[20],E[20];
struct ParseTree
{
	int l,r;
	int sub;
}T[100010];
int o,tot;
int parse(int l,int r)
{
	if(l+1==r)
	{
		int o=++tot;
		T[o].sub=l;
		return o;
	}
	int o=++tot,cnt=0;
	for(int i=l;i<=r;i++)
	{
		if(i!=l&&cnt==0) {T[o].sub=i;break;}
		if(str[i]=='(') cnt++;
		else if(str[i]==')') cnt--;
	}
	T[o].l=parse(l+1,T[o].sub-1);
	T[o].r=parse(T[o].sub+2,r-1);
	return o;
}
LL f[300][65536];
LL t1[65536],t2[65536],t3[65536];
void Mul_OR(LL a[],LL b[],LL c[],int k)
{
	for(int i=0;i<(1<<k);i++) t1[i]=a[i],t2[i]=b[i];
	for(int i=0;i<k;i++)
		for(int j=0;j<(1<<k);j++)
			if(j&(1<<i))
			{
				t1[j]=(t1[j]+t1[j^(1<<i)])%MOD;
				t2[j]=(t2[j]+t2[j^(1<<i)])%MOD;
			}
	for(int i=0;i<(1<<k);i++) c[i]=(t1[i]*t2[i])%MOD;
	for(int i=0;i<k;i++)
		for(int j=0;j<(1<<k);j++)
			if(j&(1<<i)) c[j]=(c[j]-c[j^(1<<i)]+MOD)%MOD;
}
void Mul_AND(LL a[],LL b[],LL c[],int k)
{
	for(int i=0;i<(1<<k);i++) t1[i]=a[i],t2[i]=b[i];
	reverse(t1,t1+(1<<k));
	reverse(t2,t2+(1<<k));
	for(int i=0;i<k;i++)
		for(int j=0;j<(1<<k);j++)
			if(j&(1<<i))
			{
				t1[j]=(t1[j]+t1[j^(1<<i)])%MOD;
				t2[j]=(t2[j]+t2[j^(1<<i)])%MOD;
			}
	for(int i=0;i<(1<<k);i++) c[i]=(t1[i]*t2[i])%MOD;
	for(int i=0;i<k;i++)
		for(int j=0;j<(1<<k);j++)
			if(j&(1<<i)) c[j]=(c[j]-c[j^(1<<i)]+MOD)%MOD;
	reverse(c,c+(1<<k));
}
void DFS(int x)
{
	if(T[x].l&&T[x].r)
	{
		DFS(T[x].l);
		DFS(T[x].r);
	}
	else
	{
		if(str[T[x].sub]=='A'||str[T[x].sub]=='?')
		{
			int S=0;
			for(int i=0;i<16;i++)
				if(i&(1<<0)) S|=(1<<i);
			f[x][S]++;
		}
		if(str[T[x].sub]=='B'||str[T[x].sub]=='?')
		{
			int S=0;
			for(int i=0;i<16;i++)
				if(i&(1<<1)) S|=(1<<i);
			f[x][S]++;
		}
		if(str[T[x].sub]=='C'||str[T[x].sub]=='?')
		{
			int S=0;
			for(int i=0;i<16;i++)
				if(i&(1<<2)) S|=(1<<i);
			f[x][S]++;
		}
		if(str[T[x].sub]=='D'||str[T[x].sub]=='?')
		{
			int S=0;
			for(int i=0;i<16;i++)
				if(i&(1<<3)) S|=(1<<i);
			f[x][S]++;
		}
		if(str[T[x].sub]=='a'||str[T[x].sub]=='?')
		{
			int S=0;
			for(int i=0;i<16;i++)
				if(!(i&(1<<0))) S|=(1<<i);
			f[x][S]++;
		}
		if(str[T[x].sub]=='b'||str[T[x].sub]=='?')
		{
			int S=0;
			for(int i=0;i<16;i++)
				if(!(i&(1<<1))) S|=(1<<i);
			f[x][S]++;
		}
		if(str[T[x].sub]=='c'||str[T[x].sub]=='?')
		{
			int S=0;
			for(int i=0;i<16;i++)
				if(!(i&(1<<2))) S|=(1<<i);
			f[x][S]++;
		}
		if(str[T[x].sub]=='d'||str[T[x].sub]=='?')
		{
			int S=0;
			for(int i=0;i<16;i++)
				if(!(i&(1<<3))) S|=(1<<i);
			f[x][S]++;
		}
		return;
	}
	if(str[T[x].sub]=='&') Mul_AND(f[T[x].l],f[T[x].r],f[x],16);
	else if(str[T[x].sub]=='|') Mul_OR(f[T[x].l],f[T[x].r],f[x],16);
	else
	{
		Mul_AND(f[T[x].l],f[T[x].r],f[x],16);
		Mul_OR(f[T[x].l],f[T[x].r],t3,16);
		for(int i=0;i<(1<<16);i++) f[x][i]=(f[x][i]+t3[i])%MOD;
	}
}
LL ans;
int main()
{
	scanf("%s",str);
	scanf("%d",&K);
	for(int i=1;i<=K;i++) scanf("%d%d%d%d%d",&A[i],&B[i],&C[i],&D[i],&E[i]);
	parse(0,strlen(str));
	DFS(1);
	for(int S=0;S<65536;S++)
	{
		bool ok=true;
		for(int i=1;i<=K;i++)
		{
			int x=A[i]+(B[i]<<1)+(C[i]<<2)+(D[i]<<3),res=0;
			if(S&(1<<x)) res=1;
			if(res!=E[i]) {ok=false;break;}
		}
		if(ok) ans=(ans+f[1][S])%MOD;
	}
	printf("%I64d\n",ans);
	return 0;
}