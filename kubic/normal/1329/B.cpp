#include <bits/stdc++.h>
using namespace std;
int T,n,MOD,ans1,ans2,t1,t2,lst;
struct Matrix
{
	int a[2][2];
	Matrix(bool fl=0) {a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;if(fl) a[0][0]=a[1][1]=1;}
	Matrix operator * (Matrix t)
	{
		Matrix res;
		for(int i=0;i<2;++i) for(int j=0;j<2;++j) for(int k=0;k<2;++k)
			res.a[i][j]=(res.a[i][j]+1ll*a[i][k]*t.a[k][j]%MOD)%MOD;return res;
	}
}a,b;
Matrix qPow(Matrix x,int y)
{
	Matrix res(1);
	for(;y;y>>=1,x=x*x) if(y&1) res=res*x;return res; 
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&MOD);if(n==1) {printf("%d\n",1%MOD);continue;}
		a.a[0][0]=0;a.a[0][1]=MOD-1;a.a[1][0]=1;a.a[1][1]=2;
		lst=1;ans1=1%MOD;ans2=3%MOD;
		for(int i=2;(1<<i)-1<=n;++i)
		{
			b=qPow(a,(1<<i-1)-1);t1=ans1;t2=ans2;
			ans1=(1ll*t1*b.a[0][0]%MOD+1ll*t2*b.a[1][0]%MOD)%MOD;
			ans2=(1ll*t1*b.a[0][1]%MOD+1ll*t2*b.a[1][1]%MOD)%MOD;
			if((1<<i)<=n) ans1=ans2,ans2=(ans2<<1|1)%MOD;lst=i;
		}
		if((1<<lst)<n)
		{
			b=qPow(a,n-(1<<lst));t1=ans1;t2=ans2;
			ans1=(1ll*t1*b.a[0][0]%MOD+1ll*t2*b.a[1][0]%MOD)%MOD;
			ans2=(1ll*t1*b.a[0][1]%MOD+1ll*t2*b.a[1][1]%MOD)%MOD;
		}printf("%d\n",ans2);
	}return 0;
}