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
const int N=100005;struct ${int x,y;}a[N],sa,sb,st;int n;
pair<double,int>A[N],B[N];double d[N];
inline double dis($ a,$ b) {return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+1.0*(a.y-b.y)*(a.y-b.y));}
int main()
{
	read(sa.x,sa.y,sb.x,sb.y,st.x,st.y,n);
	for(int i=1;i<=n;i++) read(a[i].x,a[i].y);
	for(int i=1;i<=n;i++) d[i]=dis(st,a[i]),A[i]=make_pair(dis(sa,a[i])-d[i],i),B[i]=make_pair(dis(sb,a[i])-d[i],i);
	sort(A+1,A+n+1),sort(B+1,B+n+1);double sm=0;for(int i=1;i<=n;i++) sm+=2ll*d[i];
	//for(int i=1;i<=n;i++) printf("%.5lf%c",A[i].first,i==n?'\n':' ');
	//for(int i=1;i<=n;i++) printf("%.5lf%c",B[i].first,i==n?'\n':' ');
	//printf("%.10lf\n",sm);
	double rs=min(sm+A[1].first,sm+B[1].first);
	if(A[1].second!=B[1].second) rs=min(rs,sm+A[1].first+B[1].first);
	else if(n^1) rs=min(rs,min(sm+A[1].first+B[2].first,sm+A[2].first+B[1].first));
	return printf("%.10lf\n",rs),0;
}