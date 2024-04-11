//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,a[5005],g[5005];map<int,int>mp;
inline int gcd(int a,int b) {return b?gcd(b,a%b):a;}
inline int F(int x)
{
	int res=0;
	for(int i=2;i*i<=x;i++) if(!(x%i))
	{
		int qwq=mp[i]?-1:1;
		while(!(x%i)) res+=qwq,x/=i;
	}
	return res+((x^1)?(mp[x]?-1:1):0);
}
int main()
{
	read(n),read(m);int tot=1,res=0;
	for(int i=1;i<=n;i++) read(a[i]),g[i]=gcd(g[i-1],a[i]);
	for(int i=1,x;i<=m;i++) read(x),mp[x]=1;
	for(int i=1;i<=n;i++) res+=F(a[i]);
	for(int i=n,x;i>=1;i--) {if((x=F(g[i]/tot))<0) tot=g[i],res+=(-x)*i;}
	return printf("%d\n",res),0;
}