#include<bits/stdc++.h>
using namespace std;
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
	char c=getchar();int x=0,w=1;
	while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x*w;
}
inline void cmx(int&a,int b){a=a>b?a:b;}
inline void cmn(int&a,int b){a=a<b?a:b;}
const int N=15;
int n,a[N];
int dfs(int x,int s,int m)
{
	if(x==n+1)return (!s)&&m;
	if(dfs(x+1,s+a[x],m+1))return 1;
	if(dfs(x+1,s-a[x],m+1))return 1;
	if(dfs(x+1,s,m))return 1;
	return 0;
}
int main()
{
	int T=rd();
	while(T--)
	{
		n=rd();
		rep(i,1,n)a[i]=rd();
		int ff=dfs(1,0,0);
		puts(ff?"YES":"NO");
	}
	return 0;
}