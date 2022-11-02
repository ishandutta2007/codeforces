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
int n;struct node{int l;double p;}a[500005];double rs=0,ls=0;
inline char cmp(node a,node b) {return a.l*a.p*(1-b.p)-1e-10>b.l*b.p*(1-a.p);}
int main()
{
	read(n);for(int i=1,x;i<=n;i++) read(a[i].l),rs+=a[i].l,read(x),a[i].p=x/100.0;
	sort(a+1,a+n+1,cmp);for(int i=1;i<=n;i++) rs+=(1-a[i].p)*ls,ls+=a[i].p*a[i].l;
	return printf("%.10lf\n",rs),0;
}