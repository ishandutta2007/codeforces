//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,bl[1000005];struct node{int x,y,id;}a[1000005];const int N=1000;
inline char operator<(node a,node b) {return bl[a.x]^bl[b.x]?bl[a.x]<bl[b.x]:(bl[a.x]&1?a.y>b.y:a.y<b.y);}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i].x),read(a[i].y),a[i].id=i;
	for(int i=0;i<=1000000;i++) bl[i]=i/N;
	sort(a+1,a+n+1);for(int i=1;i<=n;i++) printf("%d%c",a[i].id,i==n?'\n':' ');
	return 0;
}