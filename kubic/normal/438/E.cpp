#pragma GCC optimize("Ofast")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define N 400005
#define MOD 998244353
int n,m,g=3,invG,l,lim,invN,r[N],inv[N],tmp1[N],tmp2[N],tmp3[N],a[N],b[N],ans[N];
void swp(int &x,int &y) {int t=x;x=y;y=t;}
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=getchar();
	while(isdigit(c)) res=(res<<1)+(res<<3)+(c&15),c=getchar();return res;
}
int qPow(int x,int y)
{
	int res=1;
	for(;y;y>>=1,x=1ll*x*x%MOD) if(y&1) res=1ll*res*x%MOD;return res;
}
void getLim(int n)
{
	l=0;lim=1;while(lim<n) ++l,lim<<=1;invN=qPow(lim,MOD-2);
	for(int i=1;i<lim;++i) r[i]=(r[i>>1]>>1)|((i&1)<<l-1);
}
void deriv(int n,int a[]) {for(int i=1;i<n;++i) a[i-1]=1ll*a[i]*i%MOD;a[n-1]=0;}
void integ(int n,int a[]) {for(int i=n-1;i>0;--i) a[i]=1ll*a[i-1]*inv[i]%MOD;a[0]=0;}
void NTT(bool fl,int a[])
{
	for(int i=0;i<lim;++i) if(i<r[i]) swp(a[i],a[r[i]]);
	for(int i=1,t1,t2,t3,t4;i<lim;i<<=1)
	{
		t1=qPow(fl?invG:g,(MOD-1)/(i<<1));
		for(int j=0;j<lim;j+=i<<1)
		{
			t2=1;
			for(int k=0;k<i;++k,t2=1ll*t1*t2%MOD)
			{
				t3=a[j+k];t4=1ll*t2*a[i+j+k]%MOD;
				a[j+k]=(t3+t4)%MOD;a[i+j+k]=(t3-t4+MOD)%MOD;
			}
		}
	}if(fl) for(int i=0;i<lim;++i) a[i]=1ll*a[i]*invN%MOD;
}
void polyInv(int n,int a[],int res[])
{
	if(n==1) {res[0]=qPow(a[0],MOD-2);return;}polyInv(n+1>>1,a,res);
	for(int i=0;i<n;++i) tmp1[i]=a[i];for(int i=n;i<lim;++i) tmp1[i]=0;
	getLim(n<<1);NTT(0,res);NTT(0,tmp1);
	for(int i=0;i<lim;++i) res[i]=1ll*(2-1ll*res[i]*tmp1[i]%MOD+MOD)*res[i]%MOD;
	NTT(1,res);for(int i=n;i<lim;++i) res[i]=0;
}
void polyLn(int n,int a[])
{
	getLim(n<<1);for(int i=0;i<lim;++i) tmp2[i]=0;
	polyInv(n,a,tmp2);deriv(n,a);NTT(0,a);NTT(0,tmp2);
	for(int i=0;i<lim;++i) a[i]=1ll*a[i]*tmp2[i]%MOD;NTT(1,a);integ(n,a);
	for(int i=n;i<lim;++i) a[i]=0;
}
void polyExp(int n,int a[],int res[])
{
	if(n==1) {res[0]=1;return;}polyExp(n+1>>1,a,res);
	for(int i=0;i<n;++i) tmp3[i]=res[i];for(int i=n;i<lim;++i) tmp3[i]=0;
	polyLn(n,tmp3);for(int i=0;i<n;++i) tmp3[i]=(a[i]-tmp3[i]+MOD)%MOD;++tmp3[0];
	getLim(n<<1);NTT(0,res);NTT(0,tmp3);
	for(int i=0;i<lim;++i) res[i]=1ll*res[i]*tmp3[i]%MOD;NTT(1,res);
	for(int i=n;i<lim;++i) res[i]=0;
}
int main()
{
	invG=qPow(g,MOD-2);n=rd();m=rd()+1;getLim(m<<1);
	for(int i=1;i<lim;++i) inv[i]=i==1?1:1ll*inv[MOD%i]*(MOD-MOD/i)%MOD;
	for(int i=1,x;i<=n;++i) {x=rd();if(x<m) a[x]=1;}
	for(int i=0;i<m;++i) a[i]=(MOD-(a[i]<<2))%MOD;++a[0];
	polyLn(m,a);for(int i=0;i<m;++i) a[i]=1ll*a[i]*inv[2]%MOD;polyExp(m,a,b);++b[0];
	for(int i=0;i<m;++i) a[i]=0;polyInv(m,b,a);for(int i=0;i<m;++i) a[i]=(a[i]<<1)%MOD;
	for(int i=1;i<m;++i) printf("%d\n",a[i]);return 0;
}