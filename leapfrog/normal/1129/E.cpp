//Coded by Kamiyama_Shiki on 2021.11.14 {{{
//
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
const int N=505;
int n,sz[N],id[N],fa[N];vector<int>v;
inline void makef(int it,int f)
{
	fa[v[it]]=f;for(int i=it;i<(int)v.size()-1;i++) v[i]=v[i+1];
	v.pop_back();
}
inline int findps(int x) {for(int i=0;i<(int)v.size();i++) if(v[i]==x) return i;return -1;}
inline int getps(int l,int r,int fa)
{
	if(l>r) return -1;
	printf("1\n1\n%d\n",r-l+1);int cnt=0,vl,md=(l+r)>>1;
	for(int j=l;j<=r;j++) printf("%d%c",v[j],j==r?'\n':' ');
	printf("%d\n",fa),fflush(stdout),read(cnt);if(!cnt) return -1;
	if(l==r) return l;else if(~(vl=getps(l,md,fa))) return vl;else return getps(md+1,r,fa);
}
int main()
{
	read(n),sz[1]=n,id[1]=1;
	for(int i=2;i<=n;i++)
	{
		printf("1\n1\n%d\n",n-1);
		for(int j=2;j<=n;j++) printf("%d%c",j,j==n?'\n':' ');
		printf("%d\n",i),fflush(stdout),read(sz[i]),id[i]=i;
	}
	sort(id+1,id+n+1,[&](int a,int b) {return sz[a]>sz[b];});
	for(int i=2;i<=n;i++) v.push_back(id[i]);
	for(int z=n-1,i=id[z],vl;z>=1;i=id[--z]) while(1)
		if(~(vl=getps(findps(i)+1,v.size()-1,i))) makef(vl,i);else break;
	puts("ANSWER");for(int i=2;i<=n;i++) printf("%d %d\n",fa[i],i);
	return 0;
}