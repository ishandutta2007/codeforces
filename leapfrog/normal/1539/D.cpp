//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n;struct node{ll a,b;char operator<(node y) const {return b<y.b;}}a[100005];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i].a),read(a[i].b);
	sort(a+1,a+n+1);ll nw=0,rs=0;int l,r;for(l=1,r=n;l<r;)
		if(a[l].b<=nw) rs+=a[l].a,nw+=a[l].a,l++;
		else if(a[l].b-nw<=a[r].a)
		{
			a[r].a-=a[l].b-nw,rs+=2*(a[l].b-nw);
			nw+=a[l].b-nw,rs+=a[l].a,nw+=a[l].a,l++;
		}
		else nw+=a[r].a,rs+=2*a[r].a,r--;
	if(l==r)
	{
		if(nw+a[l].a<a[l].b) rs+=a[l].a*2;
		else if(nw>a[l].b) rs+=a[l].a;
		else rs+=(a[l].b-nw)*2+(a[l].a-a[l].b+nw);
	}
	return printf("%lld\n",rs),0;
}