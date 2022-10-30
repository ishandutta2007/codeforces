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
const int N=100005;int n,a[N],l[N],r[N];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	l[1]=1;for(int i=2;i<=n;i++) if(a[i-1]<a[i]) l[i]=l[i-1]+1;else l[i]=1;
	r[n]=1;for(int i=n-1;i;i--) if(a[i+1]>a[i]) r[i]=r[i+1]+1;else r[i]=1;
	int rs=0;for(int i=1;i<=n;i++) rs=max(rs,max(l[i-1]+1,r[i+1]+1));
	for(int i=2;i<n;i++) if(a[i-1]+1<a[i+1]) rs=max(rs,l[i-1]+r[i+1]+1);
	return printf("%d\n",rs),0;
}