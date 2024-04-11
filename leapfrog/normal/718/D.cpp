//
#include<bits/stdc++.h>
using namespace std;const int Bas=137,P=1000000007;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,nxt;}e[200005];set<int>Ans;map<vector<int>,int>H;
int n,et,head[100005],deg[100005],HT=0;map<pair<int,int>,int>J;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et,++deg[x];}
inline int Hash(int x,int fa)
{
	if(J.count(make_pair(x,fa))) return J[make_pair(x,fa)];
	vector<int>v;for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) v.push_back(Hash(e[i].to,x));
	sort(v.begin(),v.end());int Hs;if(H.count(v)) Hs=H[v];else Hs=H[v]=++HT;
	return J[make_pair(x,fa)]=Hs;
}
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	for(int i=1;i<=n;i++) if(deg[i]<4) Ans.insert(Hash(i,0));
	return printf("%d\n",(int)Ans.size()),0;
}