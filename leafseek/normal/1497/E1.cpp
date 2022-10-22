#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=1000000+5,MaxV=10000000+5;
int a[MaxN];
bool cnt[MaxV];
long double TimeT;
int pri[MaxN];
bool isp[MaxN];
inline void Erato(const register int len)
{
	rep(i,2,len)
		isp[i]=true;
	register int cnt=0;
	rep(i,2,len)
	{
		if(!isp[i])
			continue;
		pri[++cnt]=i;
		rep(j,i,len/i)
			isp[i*j]=false;
	}
}
inline int Reverse(const register int val)
{
	long double TimeA=clock();
	register int mem=val,cnt=0;
	register int Rev=1;
	rep(i,1,447)
	{
		cnt=0;
		while(mem%pri[i]==0)
			mem/=pri[i],++cnt;
		if(cnt&1)
			Rev*=pri[i];
		if(mem==1)
			break;
	}
	Rev*=mem;
	long double TimeB=clock();
	TimeT+=(TimeB-TimeA);
	return Rev;
}
int main()
{
	Erato(3163);
	register int T;
	scanf("%d",&T);
	register int n,k;
	while(T--)
	{
		scanf("%d%d",&n,&k);
		rep(i,1,n)
			scanf("%d",&a[i]),cnt[a[i]]=false;
		register int Sum=1,Last=0,pit=0,Rev;
		while(!(pit==n))
		{
			register bool flag=true;
			Rev=Reverse(a[pit+1]);
			assert(Rev!=0);
			for(register int x=1;x<=3163&&((x*x)*Rev<=10000000);++x)
				if(cnt[(x*x)*Rev])
					{flag=false;break;}
			if(flag)
				++pit,cnt[a[pit]]=true;
			else
			{
				rep(i,Last,pit)
					cnt[a[i]]=false;
				++Sum,Last=pit;
			}
		}
		rep(i,1,n)
			cnt[a[i]]=false;
		printf("%d\n",Sum);
	}
	return 0;
}