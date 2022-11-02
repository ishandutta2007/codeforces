//
//
#include<bits/stdc++.h>
using namespace std;const int P=1e9+7;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,m,iv[2000005],fc[2000005],pw[1000005],p[1000005],pt=0;char v[1000005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline int C(int n,int m) {return 1ll*fc[n]*iv[m]%P*iv[n-m]%P;}
int main()
{
	fc[0]=iv[0]=1,n=2000000;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	iv[n]=ksm(fc[n]);for(int i=n-1;i;i--) iv[i]=1ll*iv[i+1]*(i+1)%P;
	pw[0]=1,n=1000000;for(int i=1;i<=n;i++) pw[i]=(pw[i-1]<<1)%P;
	for(int i=2;i<=n;i++)
	{
		if(!v[i]) p[++pt]=i;
		for(int j=1;j<=pt&&p[j]*i<=n;j++) {v[i*p[j]]=1;if(!(i%p[j])) break;}
	}
	for(read(T);T--;)
	{
		read(m),read(n);int res=1;
		for(int i=1;p[i]*p[i]<=m;i++)
		{
			int pnt=0;
			while(!(m%p[i])) m/=p[i],pnt++;
			res=1ll*res*C(n-1+pnt,pnt)%P;
		}
		if(m!=1) res=1ll*res*n%P;
		printf("%lld\n",1ll*res*pw[n-1]%P);
	}
	return 0;
}