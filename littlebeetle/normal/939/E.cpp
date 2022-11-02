#include<cstdio>
const int N=500002;
const double eps=1e-7;
int n,opt,x,a[N],cnt,id;
double s,ans;
double max(double x,double y){
	return x>y?x:y;
}
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d",&x);
			a[++cnt]=x;
			while(id+1<cnt&&(s+a[id+1]+a[cnt])/(id+2)>a[id+1]-eps)
				s+=a[++id];
			ans=max(ans,a[cnt]-(s+a[cnt])/(id+1));
		}
		else
			printf("%.9lf\n",ans);
	}
}