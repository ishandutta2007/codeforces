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
constexpr int MaxN=50+5,MaxM=100000+5,Mod=998244353;
int lef[MaxN],rig[MaxN],Lef[MaxN],Rig[MaxN],arr[MaxN];
long long Answer[MaxM],dp[MaxN][MaxM],Sum[MaxN][MaxM];
int main()
{
	ios::sync_with_stdio(false),cin.tie(NULL);
	register int n,m,k,Limit;
	cin>>n>>m,k=(m/n);
	rep(i,1,n) cin>>lef[i]>>rig[i];
	rep(I,1,k)
	{
		Limit=(m/I);
		register bool Flag=false;
		rep(i,1,n)
		{
			Lef[i]=(lef[i]-1)/I+1,Rig[i]=rig[i]/I;
			if(Lef[i]>Rig[i])
				{Flag=true;break;}
			arr[i]=(Rig[i]-Lef[i]),Limit-=Lef[i];
		}
		if(Flag) continue;
		dp[0][0]=1;
		rep(j,0,Limit) Sum[0][j]=1;
		rep(i,1,n)
		{
			rep(j,0,arr[i])
				dp[i][j]=Sum[i-1][j];
			rep(j,arr[i]+1,Limit)
			{
				dp[i][j]=(Sum[i-1][j]-Sum[i-1][j-arr[i]-1]+Mod);
				if(dp[i][j]>=Mod) dp[i][j]-=Mod;
			}
			Sum[i][0]=dp[i][0];
			rep(j,1,Limit)
			{
				Sum[i][j]=(Sum[i][j-1]+dp[i][j]);
				if(Sum[i][j]>=Mod) Sum[i][j]-=Mod;
			}
		}
		Answer[I]=Sum[n][Limit];
	}
	dow(i,k,1)
	{
		rep(j,2,k/i)
			Answer[i]-=Answer[i*j];
		Answer[i]=((Answer[i]%Mod+Mod)%Mod);
	}
	cout<<Answer[1]<<endl;
	return 0;
}