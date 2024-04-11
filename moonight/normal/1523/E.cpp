#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define gc getchar()
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,V) for(int i=0;i<V.size();++i) 
inline int rd()
{
	int x=0,w=1;char c=gc;
	while(c!='-'&&!isdigit(c))c=gc;
	if(c=='-')w=-1,c=gc;
	while(isdigit(c))x=x*10+c-'0',c=gc;
	return x*w;
}
const int N=100005,P=1000000007;
int fac[N],ifac[N];
inline int pw(int a,int b)
{
	int r=1;
	for(;b;b>>=1,a=1ll*a*a%P)if(b&1)r=1ll*r*a%P;
	return r;
}
inline int C(int a,int b)
{
	if(a<0||b<0||a<b)return 0;
	return 1ll*fac[a]*ifac[a-b]%P;
}
inline int iC(int a,int b)
{
	return 1ll*ifac[a]*fac[a-b]%P;
}
int main()
{
	fac[0]=1;rep0(i,1,N)fac[i]=1ll*fac[i-1]*i%P;
	ifac[N-1]=pw(fac[N-1],P-2);
	per(i,N-1,1)ifac[i-1]=1ll*ifac[i]*i%P;
	int T=rd();
	while(T--)
	{
		int n,k,s=1;n=rd();k=rd();k--;
		//C(n-(i-1)*k,i)/C(n,i)
		rep(i,1,n)
		{
			if(n<(i-1)*k+i)break;
			s=(s+1ll*C(n-(i-1)*k,i)*iC(n,i))%P;
		}
		printf("%d\n",s);
	}
	return 0;
}