#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define MOD1 1000000007
#define MOD2 1000000009
mt19937 rand1(time(0));
int n,tp,B1,B2,pw1[N],pw2[N],s[N],st[N];
int z[N],fa[N][19],hs1[N][19],hs2[N][19];char a[N];
bool cmp(int x,int y)
{
	if(s[x]!=s[y]) return s[x]>s[y];
	for(int i=18;i>=0;--i)
		if(hs1[x][i]==hs1[y][i] && hs2[x][i]==hs2[y][i])
			x=fa[x][i],y=fa[y][i];if(x>=n || y>=n) return y<n;
	if(hs1[x][0]>n || hs1[y][0]>n) return hs1[y][0]>n;
	if(z[x]>=n && z[y]>=n) return hs1[x][0]<hs1[y][0];
	if(z[x]>=n || z[y]>=n) return z[y]<n;return hs1[x][0]>hs1[y][0];
}
int main()
{
	scanf("%s",a+1);n=strlen(a+1);
	B1=rand1()%MOD1;B2=rand1()%MOD2;pw1[0]=B1;pw2[0]=B2;
	for(int i=1;i<19;++i)
		pw1[i]=1ll*pw1[i-1]*pw1[i-1]%MOD1,pw2[i]=1ll*pw2[i-1]*pw2[i-1]%MOD2;
	for(int i=1;i<=n;++i)
	{s[i]=s[i-1];z[i]=i;if(a[i]=='(') ++s[i];else --s[i];}
	for(int i=n,t;i>=0;--i)
	{
		while(tp && s[i]<=s[st[tp]])
		{if(cmp(z[st[tp]],z[i])) z[i]=z[st[tp]];--tp;}
		if(!tp) z[i]=n;fa[i][0]=z[i];st[++tp]=i;
		if(a[i+1]==')') fa[i][0]=i+1,t=n+1;
		else t=s[z[i]]-s[i];hs1[i][0]=hs2[i][0]=t;
		for(int j=1;j<19;++j)
		{
			fa[i][j]=fa[fa[i][j-1]][j-1];
			hs1[i][j]=(1ll*hs1[i][j-1]*pw1[j-1]+hs1[fa[i][j-1]][j-1])%MOD1;
			hs2[i][j]=(1ll*hs2[i][j-1]*pw2[j-1]+hs2[fa[i][j-1]][j-1])%MOD2;
		}
	}
	for(int i=0;i<n;i=fa[i][0]) if(a[i+1]==')') putchar(')');
		else for(int j=1;j<=s[z[i]]-s[i];++j) putchar('(');return 0;
}