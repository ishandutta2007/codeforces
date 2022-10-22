#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxm=6e5+10,maxn=501;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
bool ans[maxm];
bitset<maxn>f[maxn][maxn],g[maxn][maxn];
int m,n,q;
char s[maxn][maxn];
struct qry{int id,x,xx,y,yy;};
void solve(int l,int r,const vector<qry> &q){
	if(l>r||!q.size())return;
	ri mid=l+r>>1;
	for(ri i=1;i<=m;++i)f[mid][i]=g[mid][i]=0;
	for(ri i=m;i;--i)
		if(s[mid][i]=='.')f[mid][i][i]=1,f[mid][i]|=f[mid][i+1];
		else f[mid][i]=0;
	for(ri i=mid-1;i>=l;--i)
		for(ri j=m;j;--j)
			if(s[i][j]=='.')f[i][j]=f[i+1][j]|f[i][j+1];
			else f[i][j]=0;
	for(ri i=1;i<=m;++i)
		if(s[mid][i]=='.')g[mid][i][i]=1,g[mid][i]|=g[mid][i-1];
		else g[mid][i]=0;
	for(ri i=mid+1;i<=r;++i)
		for(ri j=1;j<=m;++j)
			if(s[i][j]=='.')g[i][j]=g[i-1][j]|g[i][j-1];
			else g[i][j]=0;
	vector<qry>ql,qr;
	for(auto i:q){
		if(i.xx<mid)ql.push_back(i);
		else if(i.x>mid)qr.push_back(i);
		else ans[i.id]=(f[i.x][i.y]&g[i.xx][i.yy]).any();
	}
	solve(l,mid-1,ql);
	solve(mid+1,r,qr);
}
signed main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)scanf("%s",s[i]+1);
	scanf("%d",&q);
	vector<qry>v(q);
	for(ri i=0;i<q;++i)v[i].id=i,scanf("%d%d%d%d",&v[i].x,&v[i].y,&v[i].xx,&v[i].yy);
	solve(1,n,v);
	for(ri i=0;i<q;++i)puts(ans[i]?"Yes":"No");
	return 0;
}