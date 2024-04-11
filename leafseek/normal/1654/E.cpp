#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=100000+5,Limit_0=40000000,Limit_1=1000000;
int a[MaxN],A[MaxN],c[MaxN];
int P[Limit_0<<1],S[Limit_1<<1];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n;
	cin>>n;
	rep(i,1,n) cin>>a[i];
	const int m=100000;
	int Ans=0;
	rep(x,-300,300)
	{
		rep(i,1,n) A[i]=(a[i]-x*i),P[A[i]+Limit_0]=0;
		rep(i,1,n) c[i]=(c[P[A[i]+Limit_0]]+1),P[A[i]+Limit_0]=i;
		int Max=0; rep(i,1,n) Max=max(Max,c[i]);
		Ans=max(Ans,Max);
	}
	rep(u,1,n)
	{
		int Max=0;
		rep(i,max(1,u-700),min(n,u+700))
		{
			if(i==u) continue;
			if((a[i]-a[u])%(i-u)) continue;
			Max=max(Max,(++S[Limit_1+((a[i]-a[u])/(i-u))]));
		}
		Ans=max(Ans,Max+1);
		rep(i,max(1,u-700),min(n,u+700))
		{
			if(i==u) continue;
			if((a[i]-a[u])%(i-u)) continue;
			S[Limit_1+((a[i]-a[u])/(i-u))]=0;
		}
	}
	cout<<(n-Ans)<<'\n';
	return 0;
}