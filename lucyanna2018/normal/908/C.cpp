#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n;
double r,x[1010],y[1010];
int main(){
	scanf("%d%lf",&n,&r);
	for(int i=0; i<n; i++){
		scanf("%lf",&x[i]);
		y[i] = r;
		for(int j=0; j<i; j++){
			if(fabs(x[i] - x[j]) <= 2 * r){
				y[i] = max(y[i], y[j] + sqrt(4*r*r-(x[i]-x[j])*(x[i]-x[j])));
			}
		}
		printf("%.12lf%c",y[i], i<n-1?' ':'\n');
	}
	return 0;
}