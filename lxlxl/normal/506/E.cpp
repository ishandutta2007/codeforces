#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
#define inf 1e9
using namespace std;

const int maxn = 210;
const int maxp = 610;
const int Mod = 10007;

char str[maxn];
//      l     r   n24
int f[maxn][maxn][maxn];
int n24[maxn],Dec[maxn];
int n,m;
struct matrix
{
	int a[maxp][maxp];
	matrix(){memset(a,0,sizeof a);}
}one,A,st; int sti[maxn],edi[maxn],edec[maxn],ed,tot;
inline matrix operator *(matrix &a,matrix &b)
{
	matrix ret;
	for(int i=1;i<=tot;i++)
	{
		for(int j=i;j<=tot;j++)
			for(int k=i;k<=j;k++) (ret.a[i][j]+=a.a[i][k]*b.a[k][j]%Mod)%=Mod;
	}
	return ret;
}
matrix pw(int k)
{
	matrix re=one;
	for(;k;k>>=1,st=st*st)
		if(k&1) re=re*st;
	return re;
}

int cal(int l,int r) { if(l>r) return 0; return str[l]==str[r]?0:1; }

int main()
{
	scanf("%s",str+1); n=strlen(str+1);
	scanf("%d",&m);
	
	if(str[1]==str[n]) f[1][n][0]=1;
	else f[1][n][1]=1;
	
	for(int s=n;s>=1;s--)
	{
		for(int l=1;l+s-1<=n;l++)
		{
			int r=l+s-1;
			for(int k=0;k<=n;k++) if(f[l][r][k])
			{
				int tmp=f[l][r][k];
				if(str[l]==str[r]) (f[l+1][r-1][k+cal(l+1,r-1)]+=tmp)%=Mod;
				else (f[l+1][r][k+cal(l+1,r)]+=tmp)%=Mod,(f[l][r-1][k+cal(l,r-1)]+=tmp)%=Mod;
			}
		}
	}
	
	for(int l=1;l<=n+1;l++)
	{
		if(l-2>=0)
		{
			for(int k=0;k<=n;k++) if(f[l][l-2][k])
				(n24[k]+=f[l][l-2][k])%=Mod;
		}
		for(int k=0;k<=n;k++) if(f[l][l-1][k])
		{
			(n24[k]+=f[l][l-1][k])%=Mod;
			if((n+m)&1) (Dec[k]+=f[l][l-1][k])%=Mod;
		}
	}
	
	for(int i=0;i<=n;i++) if(n24[i]) ed++;
	tot=n+(n+1)/2+ed;
	for(int i=1;i<=n;i++) st.a[i][i]=24,st.a[i][i+1]=1;
	for(int i=1;i<=(n+1)/2;i++) st.a[n+i][n+i]=25,st.a[n+i][n+i+1]=i<(n+1)/2?1:0;
	ed=n+(n+1)/2;
	for(int i=0;i<=n;i++) if(n24[i])
	{
		sti[i]=n+1-i;
		edi[i]=++ed; st.a[ed][ed]=26;
		A.a[sti[i]][sti[i]]=1;
		int Need=(n-i+1)/2;
		if((n+m)&1) edec[i]=n+Need;
		st.a[n+Need][edi[i]]=1;
	}
	
	for(int i=1;i<=tot;i++) one.a[i][i]=1;
	int ans=0;
	if((n+m)&1)
	{
		matrix temp=st;
		matrix Nst=pw((n+m+1)/2-1);
		A=A*Nst;
		for(int i=0;i<=n;i++) if(Dec[i]) (ans-=Dec[i]*A.a[sti[i]][edec[i]]%Mod)%=Mod;
		A=A*temp;
	}
	else
	{
		matrix Nst=pw((n+m+1)/2);
		A=A*Nst;
	}
	for(int i=0;i<=n;i++) if(n24[i]) (ans+=A.a[sti[i]][edi[i]]*n24[i]%Mod)%=Mod;
	if(ans<0) ans+=Mod;
	printf("%d\n",ans);
	
	return 0;
}