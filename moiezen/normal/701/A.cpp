#include <cstdio>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define N 105
int n,s,a[N],d[N],u[N][N];
int main(){
	scanf("%d",&n);
	s=0;
	rpt(i,1,n) scanf("%d",&a[i]),s+=a[i];
	s/=(n/2);
	rpt(i,1,100) d[i]=0;
	rpt(i,1,n) u[a[i]][++d[a[i]]]=i;
	rpt(i,1,s/2){
		while(d[i]) printf("%d %d\n",u[i][d[i]--],u[s-i][d[s-i]--]);
	}
}