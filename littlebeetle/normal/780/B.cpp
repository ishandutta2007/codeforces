#include<cstdio>
const int N=1000002;
int n,i,x[N],v[N];
double l,r,mid,L,R;
double max(double x,double y){
	return x>y?x:y;
}
double min(double x,double y){
	return x<y?x:y;
}
bool check(double p){
	L=-1e9;R=2e9;
	for(i=1;i<=n;i++)
		L=max(L,x[i]-v[i]*p),
		R=min(R,x[i]+v[i]*p);
	return R>L;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",x+i);
	for(i=1;i<=n;i++)
		scanf("%d",v+i);
	l=0;r=1e9;
	while((r-l)>1e-7){
		mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	printf("%.7lf",l);
}