#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();int x=0;bool f=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
const int maxn=5e5+5;
int n,m,T,p[maxn],tot=0,vis[maxn],s[maxn];
void init()
{
	for(int i=2;i<=3e5;i++)
	{
		if(!vis[i])p[++tot]=i,vis[i]=1;
		for(int j=1;j<=tot&&p[j]*i<=3e5;j++)vis[i*p[j]]=1;
	}
	for(int i=3e5;i>=1;i--)
	{
		while(p[tot-1]>=i&&tot>0)tot--;
		s[i]=p[tot];
	}
//	for(int i=1;i<=100;i++)cout<<s[i]<<endl;
}
void solve()
{
	n=read();
	int x=s[n+1];
	int y=s[x+n];
	cout<<x*y<<endl;
}
signed main()
{
	init();T=read();
	while(T--)solve();
	return 0;
}