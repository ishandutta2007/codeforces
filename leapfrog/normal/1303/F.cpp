//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int n,m,q,lim,a[305][305],fa[90005];char vs[305][305];
vector<pair<int,int> >dl[2000005],ad[2000005];int rs[2000005];
inline int id(int x,int y) {return m*(x-1)+y;}
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline char mrg(int x,int y) {return x=getf(x),y=getf(y),x^y?fa[x]=y,1:0;}
inline void solve(const vector<pair<int,int> >&v,int fg)
{
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) fa[id(i,j)]=id(i,j),vs[i][j]=0;
	for(int i=0;i<(int)v.size();i++)
	{
		int wh=v[i].first,qw=v[i].second,x=(wh-1)/m+1,y=(wh-1)%m+1,qr=1;vs[x][y]=1;
		//printf("solve %d %d %d %d %d\n",wh,x,y,fg,qw);
		for(int k=0;k<4;k++) if(vs[x+dx[k]][y+dy[k]]) qr-=mrg(wh,id(x+dx[k],y+dy[k]));
		rs[qw]+=fg*qr;
	}
}
int main()
{
	read(n),read(m),read(q);
	for(int i=1,x,y,c;i<=q;i++)
	{
		read(x),read(y),read(c),lim=max(lim,c);
		if(a[x][y]^c) dl[a[x][y]].push_back(make_pair(id(x,y),i)),ad[a[x][y]=c].push_back(make_pair(id(x,y),i));
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dl[a[i][j]].push_back(make_pair(id(i,j),0));
	for(int i=0;i<=lim;i++) reverse(dl[i].begin(),dl[i].end());
	for(int i=0;i<=lim;i++) solve(ad[i],1),solve(dl[i],-1);
	rs[0]=1;for(int i=1;i<=q;i++) printf("%d\n",rs[i]+=rs[i-1]);
	return 0;
}