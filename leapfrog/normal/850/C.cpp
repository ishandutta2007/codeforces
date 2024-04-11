//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=105;int n,a[N];
map<int,int>mp,rs;
inline int dfs(int x)
{
	if(rs.count(x)) return rs[x];
	set<int>st;for(int i=1;i<31;i++) if(x>>i)
		st.insert(dfs((x>>i)|(x&((1<<i)-1))));
	int r=0;for(;st.count(r);r++);return rs[x]=r;
}
int main()
{
	read(n);for(int i=1,x;i<=n;i++)
	{
		read(x);for(int j=2;j*j<=x;j++) if(x%j==0)
			{int c=0;while(x%j==0) x/=j,c++;mp[j]|=1<<c;}
		if(x!=1) mp[x]|=2;
	}rs[0]=0,rs[1]=0;
	int sg=0;for(auto x:mp) sg^=dfs(x.second);
	if(sg) puts("Mojtaba");else puts("Arpa");
	return 0;
}