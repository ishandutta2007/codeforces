#include<cstdio>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define N 100005
int n,m,x,y,nx,ny,cx[N],cy[N];
int main(){
	scanf("%d%d",&n,&m);
	rpt(i,1,n) cx[i]=cy[i]=0;
	nx=ny=0;
	rpt(i,1,m){
		scanf("%d%d",&x,&y);
		if(!cx[x]) cx[x]=1,nx++;
		if(!cy[y]) cy[y]=1,ny++;
		printf("%I64d ",1LL*(n-nx)*(n-ny));
	}
	return 0;
}