#pragma GCC optimize(2)
#pragma GCC optimize(3)
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
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
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
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100010];
unordered_map<ll,int> mp;
int read()
{
	int x=0;char ch=getchar();while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) x=x*10+ch-'0',ch=getchar();return x;
}
int b[200010];
int main()
{
	int n=read(),i,j,B,ans=0;
	for (i=1;i<=n;i++) a[i]=read();
	for (j=-100;j<=100;j++)
	{
		mp.clear();
		ll u=0;
		for (i=1;i<=n;i++)
		{
			mp[a[i]+u]++;
			u+=j;
		}
		for (auto p:mp) ans=max(ans,p.second);
	}
	for (i=1;i<=n;i++)
	{
		for (j=i+1;j<=i+1000 && j<=n;j++)
		{
			if ((a[j]-a[i])%(j-i)==0) b[(a[j]-a[i])/(j-i)+100000]++,ans=max(ans,b[(a[j]-a[i])/(j-i)+100000]+1);
		}
		for (j=i+1;j<=i+1000 && j<=n;j++)
		{
			if ((a[j]-a[i])%(j-i)==0) b[(a[j]-a[i])/(j-i)+100000]--;
		}
	}
	cout<<n-ans;
}