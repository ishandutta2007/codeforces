//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,rs[100005],tp;char vs[100005];
inline void dfs(int x) {if(vs[x]) return;else vs[x]=1,dfs(x*2%n),dfs((x*2+1)%n),rs[++tp]=x;}
int main()
{
	read(n);if(n&1) return puts("-1"),0;
	dfs(0);while(tp) printf("%d ",rs[tp--]);
	return printf("0\n"),0;
}