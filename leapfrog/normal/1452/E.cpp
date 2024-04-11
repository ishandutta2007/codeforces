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
const int N=4005;int n,m,K,vl[N],fg[N];
struct node{int l,r;}a[N];vector<int>L[N],R[N];
int main()
{
	read(n,m,K);for(int i=1;i<=m;i++) read(a[i].l,a[i].r);
	sort(a+1,a+m+1,[](node a,node b){return a.l+a.r<b.l+b.r;});
	for(int i=1;i<=n-K+1;i++)
	{
		int cn=0;for(int j=m;j;j--)
			cn+=max(0,min(i+K-1,a[j].r)-max(i,a[j].l)+1),vl[j]=max(vl[j],cn);
	}
	int rs=vl[1];for(int i=1;i<=n-K+1;i++)
	{
		int cn=0;for(int j=1;j<=m;j++)
			cn+=max(0,min(i+K-1,a[j].r)-max(i,a[j].l)+1),rs=max(rs,vl[j+1]+cn);
	}return printf("%d\n",rs),0;
}