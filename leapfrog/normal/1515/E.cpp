//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,P,f[505][505],rs,pw[500005],fc[500005],fi[500005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline int C(int n,int m) {return 1ll*fc[n]*fi[m]%P*fi[n-m]%P;}
int main()
{
	read(n),read(P),pw[0]=1;for(int i=1;i<=100000;i++) pw[i]=2ll*pw[i-1]%P;
	f[1][1]=1,f[2][1]=2,fc[0]=1;for(int i=1;i<=100000;i++) fc[i]=1ll*fc[i-1]*i%P;
	fi[100000]=ksm(fc[100000]);for(int i=100000;i;i--) fi[i-1]=1ll*fi[i]*i%P;
	for(int i=3;i<=n;i++) for(int j=1;j<=(i+1)/2;j++)
	{
		if(j==1) f[i][j]=pw[i-1];
		else for(int k=1;k<i-1;k++)
			f[i][j]=(f[i][j]+1ll*f[k][j-1]*C(i-j+1,i-k-1)%P*pw[i-k-2])%P;
		if(i==n) rs=(rs+f[i][j])%P;
	}
	return printf("%d\n",rs),0;
}