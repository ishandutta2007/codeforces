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
const int N=20000000,MaxN=20000000+5,MaxPrime=5000000+5;
int fac[MaxN],pri[MaxPrime],mem[MaxN];
inline int LinearSieve(const register int len)
{
	register int cnt=0;
	rep(i,2,len)
	{
		if(fac[i]==0)
			pri[++cnt]=fac[i]=i;
		rep(j,1,cnt)
		{
			if(pri[j]>min(fac[i],len/i))
				break;
			fac[i*pri[j]]=pri[j];
		}
	}
	return cnt;
}
inline void memget(const register int len,const register int cnt)
{
	register int x;
	rep(i,1,cnt)
	{
		x=pri[i];
		rep(j,1,len/x)
			++mem[x*j];
	}
	rep(i,1,len)
		mem[i]=(1<<mem[i]);
}
inline int gcd(const register int a,const register int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	register int C=LinearSieve(N);
	memget(N,C);
	register int t;
	scanf("%d",&t);
	while(t--)
	{
		register int c,d,x,y,G;
		scanf("%d%d%d",&c,&d,&x);
		register long long Sum=0;
		for(register int g=1;g*g<=x;++g)
		{
			if(x%g!=0)
				continue;
			y=(x/g)+d;
			if(y%c==0)
				Sum+=mem[y/c];
			G=(x/g);
			if(g==G)
				continue;
			y=(x/G)+d;
			if(y%c==0)
				Sum+=mem[y/c];
		}
		printf("%lld\n",Sum);
	}
	return 0;
}