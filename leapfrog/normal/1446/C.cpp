#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
set<int>s;int n;
inline int dfs(const set<int>&s,int dep=31)
{
	set<int>_0,_1;
	for(set<int>::iterator i=s.begin();i!=s.end();i++)
		if((*i>>dep)&1) _1.insert(*i);else _0.insert(*i);
	if((int)_0.size()<=1&&(int)_1.size()<=1) return _0.size()+_1.size();
	if((int)_0.size()<=1) return dfs(_1,dep-1)+_0.size();
	if((int)_1.size()<=1) return dfs(_0,dep-1)+_1.size();
	return 1+max(dfs(_0,dep-1),dfs(_1,dep-1));
}
int main()
{
	read(n);
	for(int i=1,x;i<=n;i++) read(x),s.insert(x);
	return printf("%d\n",n-dfs(s)),0;
}