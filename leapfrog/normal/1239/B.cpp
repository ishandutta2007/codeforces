//{{{
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}/*}}}*/
int n,ls[300005],rs,le,ri,cn;char s[300005],t[300005];
int main()
{
	read(n),scanf("%s",s+1);int nw=0,mn=0,id=0;
	for(int i=1;i<=n;i++) nw+=s[i]=='('?1:-1,nw<mn?mn=nw,id=i:0;
	if(nw) return puts("0\n1 1"),0;else for(int i=1;i<=n;i++) t[i]=s[(i+id-1)%n+1];
	vector<int>v;v.push_back(0);for(int i=1;i<=n;i++)
		{ls[i]=ls[i-1]+(t[i]=='('?1:-1);if(!ls[i]) v.push_back(i),cn++;}
	rs=cn,le=ri=1;for(int i=1;i<(int)v.size();i++)
	{
		int l=v[i-1]+1,r=v[i],t=0;
		for(int j=l;j<=r;j++) t+=ls[j]==1;
		if(t>rs) rs=t,le=l,ri=r;
	}
	v.clear(),v.push_back(0);for(int i=1;i<=n;i++) if(ls[i]==1) v.push_back(i);
	for(int i=1;i<(int)v.size();i++)
	{
		int l=v[i-1]+1,r=v[i],t=cn;if(!ls[l]) continue;
		for(int j=l;j<=r;j++) t+=ls[j]==2;
		if(t>rs) rs=t,le=l,ri=r;
	}
	return printf("%d\n%d %d\n",rs,(le+id-1)%n+1,(ri+id-1)%n+1),0;
}