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
const int N=200005,B=sqrt(N);
int n,m,X[N],Y[N],cf[N],tr[B+4][B+5],ls[N],cb[N];
inline void upd(int x,int w) {cf[x]+=w,cb[x/B]+=w;}
inline void add(int nw,int x,int y,int w)
{
	if(x+y<B) for(int i=0;i<y;i++) tr[x+y][(nw+x+i)%(x+y)]+=w;
	else for(int i=0;nw+i+x<=m;i+=x+y) {upd(nw+i+x,w);if(nw+i+x+y<=m) upd(nw+i+x+y,-w);}
}
inline int solve(int nw)
{
	int rs=0;for(int i=0;;rs+=cb[i/B],i+=B)
		if(i+B>nw) {for(int j=i;j<=nw;j++) rs+=cf[j];break;}
	for(int i=1;i<=B;i++) rs+=tr[i][nw%i];
	return rs;
}
int main()
{
	read(n,m);for(int i=1;i<=n;i++) read(X[i],Y[i]);
	for(int i=1,fg,w;i<=m;i++)
	{
		read(fg),read(w);
		if(fg&1) add(i,X[w],Y[w],(fg&1)?1:-1),ls[w]=i;
		else add(ls[w],X[w],Y[w],(fg&1)?1:-1),ls[w]=0;
		printf("%d\n",solve(i));
	}return 0;
}