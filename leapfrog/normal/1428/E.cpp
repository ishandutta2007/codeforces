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
struct node{ll w;int i,k;char operator<(node b) const {return w<b.w;}};
int n,K,a[100005];ll rs=0;priority_queue<node>q;inline ll sq(ll x) {return x*x;}
inline ll F(int i,int w) {return (w-a[i]%w)*sq(a[i]/w)+a[i]%w*sq(a[i]/w+1);}
int main()
{
	read(n,K);for(int i=1;i<=n;i++) read(a[i]),rs+=F(i,1);
	for(int i=1;i<=n;i++) q.push((node){F(i,1)-F(i,2),i,1});
	for(int i=1;i<=K-n;i++)
	{
		node x=q.top();q.pop(),rs-=x.w,x.k++;
		x.w=F(x.i,x.k)-F(x.i,x.k+1),q.push(x);
	}return printf("%lld\n",rs),0;
}