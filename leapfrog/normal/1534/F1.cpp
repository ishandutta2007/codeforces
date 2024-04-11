//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
const int N=400005;int n,m,*_,$[N<<2],*L[N],*R[N],a[N],F[N];char $$[N],*ch[N];
inline void dfsL(int x,int y,int rt)
{
	if(L[x][y]) return;else L[x][y]=rt;
	if(x<n) dfsL(x+1,y,rt);
	if(x>1&&ch[x-1][y]=='#') dfsL(x-1,y,rt);
	if(y>1&&ch[x][y-1]=='#') dfsL(x,y-1,rt);
	if(y<m&&ch[x][y+1]=='#') dfsL(x,y+1,rt);
}
inline void dfsR(int x,int y,int rt)
{
	if(R[x][y]) return;else R[x][y]=rt;
	if(x<n) dfsR(x+1,y,rt);
	if(x>1&&ch[x-1][y]=='#') dfsR(x-1,y,rt);
	if(y>1&&ch[x][y-1]=='#') dfsR(x,y-1,rt);
	if(y<m&&ch[x][y+1]=='#') dfsR(x,y+1,rt);
}
int main()
{
	read(n),read(m),ch[1]=$$;for(int i=1;i<=n;i++) scanf("%s",ch[i]+1),ch[i+1]=ch[i]+m;
	_=$;for(int i=1;i<=n;i++) L[i]=_,_+=m,R[i]=_,_+=m;
	memset(F,0x3f,sizeof(F)),F[0]=0;for(int i=1;i<=m;i++) read(a[i]);
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) if(ch[j][i]=='#') dfsL(j,i,i);
	for(int i=m;i>=1;i--) for(int j=1;j<=n;j++) if(ch[j][i]=='#') dfsR(j,i,i);
	for(int i=1;i<=m;i++) for(int j=n;j>=1;j--) if(ch[j][i]=='#'&&!--a[i]) {_[i]=j;break;}
	//for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%d%c",L[i][j],j==m?'\n':' ');
	//for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%d%c",R[i][j],j==m?'\n':' ');
	//for(int i=1;i<=m;i++) printf("%d%c",_[i],i==m?'\n':' ');
	//for(int i=1;i<=m;i++) if(_[i]>0) printf("%d %d\n",L[_[i]][i],R[_[i]][i]);
	for(int i=1;i<=m;i++) if(_[i]>0) F[L[_[i]][i]]=min(F[L[_[i]][i]],R[_[i]][i]);
	int rs=-1,nw=1;for(int i=m;i>=1;i--) F[i]=min(F[i+1],F[i]);
	//for(int i=1;i<=m;i++) printf("%d%c",F[i],i==m?'\n':' ');
	while(nw<=m+1) nw=F[nw]+1,rs++;
	return printf("%d\n",rs),0;
//	for(int i=1;i<=m;i++) if(F[i]<m) G[F[i]]=min(G[F[i]],G[i]+1);else r=max(r,G[i]+1);
//	for(int i=1;i<=m;i++) printf("%d%c",G[i],i==m?'\n':' ');
//	return printf("%d\n",G[m]),0;
}