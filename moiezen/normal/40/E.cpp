#include <cstdio>
#include <iostream>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define N 1005
int n,m,k,p,x[N],y[N],z[N];
int d[N],mult[N],x0,ans;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rpt(i,1,k) scanf("%d%d%d",&x[i],&y[i],&z[i]);
	scanf("%d",&p);
	if(n<m){
		std::swap(n,m);
		rpt(i,1,k) std::swap(x[i],y[i]);
	}
	rpt(i,1,n) d[i]=0,mult[i]=1;
	rpt(i,1,k) d[x[i]]++,mult[x[i]]*=z[i];
	rpt(i,1,n) if(!d[i]) x0=i;
	ans=1;
	rpt(i,1,n) if(i!=x0){
		if(d[i]==m){
			if(mult[i]==1) ans=0;
		}
		else rpt(j,1,m-d[i]-1) (ans*=2)%=p;
	}
	if((n^m)&1) ans=0;
	printf("%d",ans);
}