#include<bits/stdc++.h>
#define int long long
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=1000000+5;
int a[MaxN],b[MaxN],pa[MaxN],pb[MaxN];
int rec[MaxN];
inline int gcd(const register int x,const register int y)
{
	return (y==0)?x:gcd(y,x%y);
}
inline int lcm(const register int x,const register int y)
{
	return x/gcd(x,y)*y;
}
inline int qp(const register int x,const register int l,const register int m)
{
	if(m==1) return 0;
	if(l==0) return (1%m);
	register int half=qp(x,l>>1,m);
	register int Mul=(half*half)%m;
	return ((l&1)?((Mul*x)%m):Mul);
}
inline void Ex_gcd(int a,int b,int& x,int& y)
{
	if(b==0)
	{
		x=1;
		y=0;
	}
	else
	{
		Ex_gcd(b,a%b,y,x);
		y-=(a/b)*x;
	}
}
inline int inv(const register int x,const register int m)
{
	register int u,v;
	Ex_gcd(x,m,u,v);
	return ((u%m)+m)%m;
}
signed main()
{
	register int n,m,Goal,k,Day=0;
	scanf("%lld%lld%lld",&n,&m,&Goal);
	rep(i,1,n)
		scanf("%lld",&a[i]);
	rep(i,1,m)
		scanf("%lld",&b[i]);
	if(!(n<=m))
	{
		swap(n,m);
		rep(i,1,m)
			swap(a[i],b[i]);
	}
	rep(i,1,n)
		pa[a[i]]=i;
	rep(i,1,m)
		pb[b[i]]=i;
	register int Sum=0,Gcd=gcd(n,m),Lcm=lcm(n,m);
	k=m/Gcd;
	register int pos,Inv=inv(n/Gcd,m/Gcd);
	rep(i,1,n)
	{
		if(pb[a[i]]==0)
			continue;
		pos=(pb[a[i]]-i);
		if(pos%Gcd!=0)
			continue;
		++rec[((pos/Gcd*Inv)%k+k)%k+1];
	}
	rep(i,1,k)
		Sum+=(rec[i]=(n-rec[i]));
	--Goal;
	Day+=((Goal/Sum)*Lcm),Goal%=Sum;
	rep(i,1,k)
	{
		if(Goal>=rec[i])
			Goal-=rec[i],Day+=n;
		else
		{
			while(Goal>=0)
			{
				++Day;
				if(a[(Day+n-1)%n+1]!=b[(Day+m-1)%m+1])
					--Goal;
			}
			break;
		}
	}
	printf("%lld\n",Day);
	return 0;
}