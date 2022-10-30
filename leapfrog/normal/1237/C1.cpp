//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n;struct node{int a,b,c;}a[500005];char v[500005];
inline char cmp(node a,node b) {return a.a^b.a?a.a<b.a:a.b^b.b?a.b<b.b:a.c<b.c;}
map<int,map<int,map<int,int> > >mp;
inline void eras(int id,int x,int y,int z)
{
	mp[x][y].erase(z),v[id]=1;
	if(mp[x][y].empty()) mp[x].erase(y);
	if(mp[x].empty()) mp.erase(x);
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i].a),read(a[i].b),read(a[i].c);
	for(int i=1;i<=n;i++) mp[a[i].a][a[i].b][a[i].c]=i;
	for(int i=1;i<=n;i++) if(!v[i])
	{
		eras(i,a[i].a,a[i].b,a[i].c);
		auto x=mp.lower_bound(a[i].a);if(x==mp.end()) x--;
		auto y=x->second.lower_bound(a[i].b);if(y==x->second.end()) y--;
		auto z=y->second.lower_bound(a[i].c);if(z==y->second.end()) z--;
		int qwq=z->second;eras(qwq,a[qwq].a,a[qwq].b,a[qwq].c),printf("%d %d\n",i,qwq);
	}
	return 0;
}