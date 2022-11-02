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
const int N=100005;int n,m,K,a[N],b[N];vector<int>X[N],Y[N];
inline int id(int x,int y) {return(x-1)*m+y;}
int main()
{
	read(n,m,K);for(int i=1;i<=K;i++) read(a[i],b[i]);
	for(int i=1;i<=K;i++) X[a[i]].push_back(b[i]),Y[b[i]].push_back(a[i]);
	for(int i=1;i<=100000;i++) sort(X[i].begin(),X[i].end()),sort(Y[i].begin(),Y[i].end());
	int lx=1,ly=1,rx=n,ry=m,x=1,y=0;ll tot=0;
	for(int tw;1;)
	{
		tw=ry;for(auto x:X[x]) if(x>=ly) tw=min(tw,x-1);
		tot+=tw-y,ry=tw,y=tw,lx++;if(lx>rx||ly>ry) break;
		//printf("%d ~ %d ; %d ~ %d . ( %d %d ) : %lld\n",lx,rx,ly,ry,x,y,tot);
		tw=rx;for(auto y:Y[y]) if(y>=lx) tw=min(tw,y-1);
		tot+=tw-x,rx=tw,x=tw,ry--;if(lx>rx||ly>ry) break;
		//printf("%d ~ %d ; %d ~ %d . ( %d %d ) : %lld\n",lx,rx,ly,ry,x,y,tot);
		tw=ly;for(auto x:X[x]) if(x<=ry) tw=max(tw,x+1);
		tot+=y-tw,ly=tw,y=tw,rx--;if(lx>rx||ly>ry) break;
		//printf("%d ~ %d ; %d ~ %d . ( %d %d ) : %lld\n",lx,rx,ly,ry,x,y,tot);
		tw=lx;for(auto y:Y[y]) if(y<=rx) tw=max(tw,y+1);
		tot+=x-tw,lx=tw,x=tw,ly++;if(lx>rx||ly>ry) break;
		//printf("%d ~ %d ; %d ~ %d . ( %d %d ) : %lld\n",lx,rx,ly,ry,x,y,tot);
	}//if(y==0) tot++;
	return puts(tot==1ll*n*m-K?"Yes":"No"),0;
}