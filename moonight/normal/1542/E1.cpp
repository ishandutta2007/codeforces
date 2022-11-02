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
const int N=505,M=N*N,B=M/2;
int n,P,res,ans[N],f[2][M],s[2][M];
int main()
{
	n=rd();P=rd();f[0][B]=1;
	rep(i,B,B*2)s[0][i]=1; 
	rep(i,1,n)
	{
		int u=i&1,v=u^1;
		memset(f[u],0,sizeof(f[u]));
		memset(s[u],0,sizeof(s[u]));
		ll t=1;int sz=i*(i-1)/2;
		rep(j,B-sz,B+sz)
		{
			f[u][j]=t;
			t=(t+P-s[v][j]+s[v][j-i]+s[v][j+i]+P-s[v][j])%P;
		}
		rep(j,B-sz,B*2)s[u][j]=(s[u][j-1]+f[u][j])%P;
		rep0(j,1,i)ans[i]=(ans[i]+1ll*(s[v][B*2]+P-s[v][B+j])*(i-j))%P;
	}
	rep(i,1,n)res=(1ll*res*i+ans[i])%P;
	printf("%d\n",res);return 0;
}