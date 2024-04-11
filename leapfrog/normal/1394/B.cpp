//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct Hash
{
	unsigned Hash1,Hash2;
	inline char operator==(Hash b) const {return Hash1==b.Hash1&&Hash2==b.Hash2;}
	inline Hash operator+(Hash b) const {return(Hash){Hash1+b.Hash1,Hash2+b.Hash2};}
	inline Hash operator+(unsigned b) const {return(Hash){Hash1+b,Hash2+b};}
	inline Hash operator*(unsigned b) const {return(Hash){Hash1*b,Hash2*b};}
	inline Hash operator*(Hash b) const {return(Hash){Hash1*b.Hash1,Hash2*b.Hash2};}
}Bas=(Hash){137,149},All,bs[200005],Hs[25][25];
int n,m,k,res=0;vector<pair<int,int> >v[200005];
inline void dfs(int x,Hash nw)
{
	if(x>k) return(void)(res+=nw==All);
	for(int i=0;i<x;i++) dfs(x+1,nw+Hs[x][i]);
}
int main()
{
	read(n),read(m),read(k),bs[0]=(Hash){1,1};
	for(int i=1;i<=n;i++) bs[i]=bs[i-1]*Bas,All=All+bs[i];
	for(int x,y,w;m--;) read(x),read(y),read(w),v[x].push_back(make_pair(w,y));
	for(int i=1;i<=n;i++)
	{
		sort(v[i].begin(),v[i].end());int nw=v[i].size();
		for(int j=0;j<nw;j++) Hs[nw][j]=Hs[nw][j]+bs[v[i][j].second];
	}
	return dfs(1,(Hash){0,0}),printf("%d\n",res),0;
}