#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=3e5+5,MAXM=3005;
int n,m,q,a[MAXN][2],p[MAXM][MAXM*2],pre[MAXN*2];
int fnd(int x){
	if(x!=pre[x]) pre[x]=fnd(pre[x]);
	return pre[x];
}
bool act[MAXM][MAXM*2];
int mg[2][100],*nw;
void Active(int x,int y){
	//nw[++*nw]=fnd(p[x][y]);
	for(int i=x-1; i<=x+1; i++)
		for(int j=y-1; j<=y+1; j++){
			int nx=i,ny=j;
			if(ny<1) ny+=m*2;
			if(ny>m*2) ny-=m*2;
			if(act[nx][ny]) nw[++*nw]=fnd(p[nx][ny]);
		}
	return ;
}
int ans;
int main(){
	//freopen("in","r",stdin);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1; i<=q; i++){
		scanf("%d%d",a[i],a[i]+1);
		p[a[i][0]][a[i][1]]=i;
		p[a[i][0]][a[i][1]+m]=i+q;
	}
	for(int i=1; i<=q*2; i++)
		pre[i]=i;
	for(int i=1; i<=q; i++){
		int x=a[i][0],y=a[i][1];
		act[x][y]=act[x][y+m]=1;
		nw=mg[0];
		*nw=0;
		Active(x,y);
		nw=mg[1];
		*nw=0;
		Active(x,y+m);
		bool t=0;
		for(int j=1; j<=*mg[0]; j++)
			for(int k=1; k<=*mg[1]; k++)
				if(mg[0][j]==mg[1][k]) t=1;
		if(t){
			act[x][y]=act[x][y+m]=0;
			continue;
		}
		ans++;
		for(int j=2; j<=*mg[0]; j++)
			pre[mg[0][j]]=mg[0][1];
		for(int j=2; j<=*mg[1]; j++)
			pre[fnd(mg[1][j])]=fnd(mg[1][1]);
	}
	printf("%d\n",ans);
	return 0;
}