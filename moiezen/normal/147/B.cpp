#include <cstdio>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define rpd(i,r,l) for(int i=r;i>=l;i--)
#define N 305
int n,m,x,y,tmp,ans;
struct mat{
	int v[N][N];
}g[9],p,q;
mat operator*(mat a,mat b){
	mat res;
	rpt(i,1,n) rpt(j,1,n){
		res.v[i][j]=a.v[i][j];if(b.v[i][j]<res.v[i][j]) res.v[i][j]=b.v[i][j];
		rpt(k,1,n) if(a.v[i][k]+b.v[k][j]>res.v[i][j]) res.v[i][j]=a.v[i][k]+b.v[k][j];
	}
	return res;
}
void clear(mat&a){
	rpt(i,1,n) rpt(j,1,n) a.v[i][j]=i==j?0:-1<<22;
}
bool check(mat a){
	rpt(i,1,n) if(a.v[i][i]>0) return true;
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	rpt(i,1,n) rpt(j,1,n) g[0].v[i][j]=-1<<22;
	while(m--){
		scanf("%d%d",&x,&y);
		scanf("%d%d",&g[0].v[x][y],&g[0].v[y][x]);
	}
	rpt(t,1,8) g[t]=g[t-1]*g[t-1];
	clear(p);tmp=0;ans=0;
	rpd(i,8,0){
		q=p*g[i];
		if(check(q)) ans=tmp+(1<<i);
		else tmp=tmp+(1<<i),p=q;
	}
	printf("%d",ans);
}