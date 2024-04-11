#include<bits/stdc++.h>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(file) freopen(file".in","r",stdin)
#define fileout(file) freopen(file".out","w",stdout)

int xa,ya,xb,yb,xc,yc;
bool vis[1005][1005];
void draw(int x,int y,int x0,int y0) {
	fr(i,min(x0,x),max(x0,x)) vis[i][y0]=1;
	fr(i,min(y0,y),max(y0,y)) vis[x][i]=1;
}
int main() {
	cin>>xa>>ya>>xb>>yb>>xc>>yc;
	int tx=0,ty=0;
	fr(x,0,1000) fr(y,0,1000)
		if(abs(x-xa)+abs(y-ya)+abs(x-xb)+abs(y-yb)+abs(x-xc)+abs(y-yc)+1<
			abs(tx-xa)+abs(ty-ya)+abs(tx-xb)+abs(ty-yb)+abs(tx-xc)+abs(ty-yc)+1)
				tx=x,ty=y;
	draw(tx,ty,xa,ya);
	draw(tx,ty,xb,yb);
	draw(tx,ty,xc,yc);
	cout<<abs(tx-xa)+abs(ty-ya)+abs(tx-xb)+abs(ty-yb)+abs(tx-xc)+abs(ty-yc)+1<<endl;
	fr(i,0,1000) fr(j,0,1000) if(vis[i][j]) cout<<i<<' '<<j<<endl;
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}