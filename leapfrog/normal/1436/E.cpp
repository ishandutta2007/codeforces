//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
vector<int>v[100005];int n,T[100005];
inline void add(int x,int y) {for(;x<=n;x+=x&(-x)) T[x]=max(T[x],y);}
inline int qry(int x) {int r=0;for(;x;x-=x&(-x)) r=max(T[x],r);return r;}
int main()
{
	read(n);for(int i=1;i<=n+1;i++) v[i].push_back(0);
	for(int i=1,x;i<=n;i++) read(x),v[x].push_back(i);
	for(int i=1;i<=n+1;i++) v[i].push_back(n+1);
	for(int i=1;i<=n+1;i++)
	{
		if((int)v[i].size()==n+2) return printf("%d\n",i),0;
		int tag=0;for(int j=0;j<(int)v[i].size()-1;j++) if(qry(v[i][j]+1)<v[i][j+1]) tag=1;
		if(!tag) return printf("%d\n",i),0;
		for(int j=0;j<(int)v[i].size()-1;j++) add(v[i][j]+1,v[i][j+1]);
	}
	return printf("%d\n",n+2),0;
}