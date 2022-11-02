#include<cstdio>
#include<cmath>
const int N=100002;
int n,i,u,v,k,f;
double x[N],y[N],l,r,mid,L,R,P,Q;
double max(double x,double y){
	return x>y?x:y;
}
double min(double x,double y){
	return x<y?x:y;
}
double abs(double x){
	return x>0?x:-x;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){//
		scanf("%lf%lf",x+i,y+i);
		if(y[i]>0)
			u++;
		else
			y[i]=-y[i],v++;
		l=max(l,abs(y[i])/2+0.00000001);
	}
	if(u&&v){
		printf("-1");
		return 0;
	}
	r=400000001000000000.0;
	for(k=1;k<=100;k++){
		mid=(l+r)/2;
		f=1;
		L=x[1]-sqrt(mid*mid-(mid-y[1])*(mid-y[1]));
		R=x[1]+sqrt(mid*mid-(mid-y[1])*(mid-y[1]));
		for(i=2;i<=n;i++){
			P=x[i]-sqrt(mid*mid-(mid-y[i])*(mid-y[i]));
			Q=x[i]+sqrt(mid*mid-(mid-y[i])*(mid-y[i]));
			if(P>R||Q<L){
				f=0;
				break;
			}
			L=max(L,P);
			R=min(R,Q);
		}
		if(f)
			r=mid;
		else
			l=mid;
	}
	if(l>400000000000000000.0)
		printf("-1");
	else
	printf("%.7lf",l);
	//while(1);
}