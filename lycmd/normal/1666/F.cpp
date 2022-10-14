#include<bits/stdc++.h>
using namespace std;
#define N 5005
#define Mod 998244353
#define For(i,x,y)for(i=x;i<=(y);i++)
#define Down(i,x,y)for(i=x;i>=(y);i--)
const int LIM=5000;
int f[N][N][2],fac[N],inv[N],aa[N],a[N],b[N];
int ksm(int x,int y)
{
	return(!y?1:1LL*ksm(1LL*x*x%Mod,y>>1)*(y&1?x:1)%Mod);
}
int C(int x,int y)
{
	return(y>x?0:1LL*fac[x]*inv[y]%Mod*inv[x-y]%Mod);
}
int main()
{
	int T,n,i,m,last,j,now,pre;
	cin>>T;
	fac[0]=1;
	For(i,1,LIM)fac[i]=1LL*fac[i-1]*i%Mod;
	inv[LIM]=ksm(fac[LIM],Mod-2);
	Down(i,LIM-1,0)inv[i]=1LL*inv[i+1]*(i+1)%Mod;
	while(T--)
	{
		cin>>n;
		For(i,1,n)cin>>aa[i];
		For(i,0,n)
		For(j,0,n)f[i][j][0]=f[i][j][1]=0;
		m=pre=0;
		last=n+1;
		Down(i,n,1)
		if(aa[i]!=aa[i-1])
		{
			a[++m]=a[i];
			b[m]=last-i;
			last=i;
		}
		f[0][0][1]=1;
		For(i,1,m)
		{
			For(j,0,i-1)
			{
				now=(j<<1)-pre;
				f[i][j+1][1]=(f[i][j+1][1]+1LL*f[i-1][j][1]*C(now-(j>0),b[i]-1))%Mod;
				f[i][j][0]=(f[i][j][0]+1LL*f[i-1][j][0]*C(now,b[i])+1LL*f[i-1][j][1]*C(now-1,b[i]-1))%Mod;
				f[i][j][1]=(f[i][j][1]+1LL*f[i-1][j][1]*C(now-1,b[i]))%Mod;
			}
			pre+=b[i];
		}
		cout<<f[m][n>>1][0]<<endl;
	}
	return 0;
}