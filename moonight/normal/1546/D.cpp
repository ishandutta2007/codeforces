#include<bits/stdc++.h>
#define ll long long
#define db double
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(int i=0;i<a.size();++i)
inline int rd()
{
	char c=getchar();int x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x;
}
inline void cmx(int&a,int b){a=a>b?a:b;}
inline void cmn(int&a,int b){a=a<b?a:b;}
const int N=100005,P=998244353;
int n,fac[N],ifac[N];char s[N];
inline int pw(int a,int b){int r=1;for(;b;b>>=1,a=1ll*a*a%P)if(b&1)r=1ll*r*a%P;return r;}
inline int C(int a,int b){return 1ll*fac[a]*ifac[b]%P*ifac[a-b]%P;}
int main()
{
	int T=rd();fac[0]=1;
	rep0(i,1,N)fac[i]=1ll*fac[i-1]*i%P;
	ifac[N-1]=pw(fac[N-1],P-2);
	per(i,N-1,1)ifac[i-1]=1ll*ifac[i]*i%P;
	while(T--)
	{
		n=rd();int s1=0,s2=0,s3=0;
		scanf("%s",s+1);
		for(int l=1,r;l<=n;l++)if(s[l]=='1')
		{
			r=l;
			while(s[r]=='1')r++;
			int s=r-l;s1+=s;
			if(s&1)s2++; 
			l=r-1;
		}
		s3=n-s1+(s1-s2)/2;
		printf("%d\n",C(s3,n-s1));
	}
	return 0;
}