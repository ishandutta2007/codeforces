#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int N=150005;int n,a[N];vector<int>v;
inline char chk(int x)
{
	if(x<=0||x>=n) return 1;
	if(x&1) return a[x]<a[x+1];else return a[x]>a[x+1];
}
inline char chk(int x,int y)
{
	swap(a[x],a[y]);char rs=1;for(int x:v) rs&=chk(x);
	rs&=chk(x)&&chk(x+1)&&chk(x-1)&&chk(y)&&chk(y+1)&&chk(y-1);
	swap(a[x],a[y]);return rs;
}
int main()
{
	read(n);int rs=0;for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<n;i++) if(!chk(i)) v.push_back(i);
	if(v.size()>4l) return puts("0"),0;
	for(int i=1;i<=n;i++) rs+=chk(v[0],i);
	for(int i=1;i<=n;i++) rs+=chk(v[0]+1,i);
	return printf("%d\n",rs-chk(v[0],v[0]+1)),0;
}