#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef int ll;
const int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}},maxk=31,maxn=510;
int d[maxn][maxn],f[maxk][maxn][maxn],k,m,n,r[maxn][maxn];
inline ll calc(ll nx,ll ny,ll mx,ll my,ll type){
	if(type==0)return d[nx][ny];
	if(type==1)return r[nx][ny];
	if(type==2)return d[mx][my];
	if(type==3)return r[mx][my];
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	if(k&1){
		for(ri i=1;i<=n;puts(""),++i)
			for(ri j=1;j<=m;++j)
				printf("-1 ");
		return 0;
	}
	k>>=1;
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<m;++j)
			scanf("%d",&r[i][j]);
	for(ri i=1;i<n;++i)
		for(ri j=1;j<=m;++j)
			scanf("%d",&d[i][j]);
	memset(f,0x3f,sizeof f);
	memset(f[0],0,sizeof f[0]);
	for(ri p=1;p<=k;++p)
		for(ri i=1;i<=n;++i)
			for(ri j=1;j<=m;++j)
				for(ri l=0;l<4;++l){
					ri mx=i+dir[l][0],my=j+dir[l][1];
					if(mx>0&&mx<=n&&my>0&&my<=m)f[p][i][j]=min(f[p][i][j],f[p-1][mx][my]+calc(i,j,mx,my,l));
				}
	for(ri i=1;i<=n;printf("\n"),++i)
		for(ri j=1;j<=m;++j)
			printf("%d ",f[k][i][j]<<1);
	return 0;
}