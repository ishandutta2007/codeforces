#include<cstdio>
#include<algorithm>
using namespace std;
const int N=190092;
int n,i;
double p[N],x,y;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lf",p+i);
	sort(p+1,p+n+1);
	x=1;
	for(i=n;i&&x>y;i--){
		y+=(x-y)*p[i];
		x*=(1-p[i]);
	}
	printf("%.10lf",y);
}