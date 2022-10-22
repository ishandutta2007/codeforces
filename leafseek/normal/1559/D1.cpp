#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=100000+5;
struct Connection_Disjoint_Set
{
	int Next[MaxN];
	inline void Initalize(const register int len)
		{rep(i,1,len) Next[i]=i;}
	inline int getf(const register int u)
	{
		if(u!=Next[u])
			Next[u]=getf(Next[u]);
		return Next[u];
	}
	inline void Merge(const register int u,const register int v)
	{
		register int fu=getf(u),fv=getf(v);
		if(fu!=fv)
			Next[fv]=fu;
	}
	inline bool Same(const register int u,const register int v)
		{return (getf(u)==getf(v));}
};
Connection_Disjoint_Set C1,C2;
queue<int> qu,qv;
int main()
{
	ios::sync_with_stdio(false),cin.tie(NULL);
	register int n,m1,m2;
	cin>>n>>m1>>m2;
	register int u,v;
	C1.Initalize(n);
	while(m1--)
		cin>>u>>v,C1.Merge(u,v);
	C2.Initalize(n);
	while(m2--)
		cin>>u>>v,C2.Merge(u,v);
	register int Sum=0;
	rep(i,1,n)
		rep(j,1,n)
		{
			if(C1.Same(i,j)||C2.Same(i,j))
				continue;
			++Sum,qu.push(i),qv.push(j);
			C1.Merge(i,j),C2.Merge(i,j);
		}
	cout<<Sum<<endl;
	rep(i,1,Sum)
	{
		cout<<qu.front()<<' ',qu.pop();
		cout<<qv.front()<<' ',qv.pop();
		cout<<'\n';
	}
	return 0;
}