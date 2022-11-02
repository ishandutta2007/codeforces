//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,m,ls[200005],res,rs[200005];char s[200005],t[200005];
inline void solve()
{
	read(n),read(m),scanf("%s%s",s+1,t+1);
	for(int i=n,x=m;i;i--) if(s[i]==t[x]&&x)
	{
		ls[x]=i,x--;if(x<m) res=max(res,ls[x+2]-ls[x+1]);
	}
	for(int i=1,x=1;i<=n;i++) if(s[i]==t[x]&&x<=m)
	{
		rs[x]=i,x++;if(x>1) res=max(res,rs[x-1]-rs[x-2]);
	}
	for(int i=1;i<m;i++) res=max(res,ls[i+1]-rs[i]);
	printf("%d\n",res);
}
//int main() {for(read(T);T--;) solve();return 0;}
int main() {return solve(),0;}