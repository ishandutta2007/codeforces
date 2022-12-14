#include <cstdio>
int T;
double R,r,k;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf",&R,&r,&k);
		printf("%.8f\n",1/(1/(R-r)+k*k*(R-r)/(R*r)));
	}
}