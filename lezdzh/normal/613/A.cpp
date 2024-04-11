#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int x[100002],y[100002];
int main(){
	int n,xx,yy;
	scanf("%d%d%d",&n,&xx,&yy);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]),
		x[i]-=xx,y[i]-=yy;
	x[0]=x[n],y[0]=y[n];
	double r1=2e9,r2=-2e9;
	for(int i=0;i<n;i++){
		if(1ll*(x[i]-x[i+1])*x[i]+1ll*(y[i]-y[i+1])*y[i]>=0&&
			1ll*(x[i+1]-x[i])*x[i+1]+1ll*(y[i+1]-y[i])*y[i+1]>=0)
				r1=min(r1,abs(1.0*x[i]*y[i+1]-1.0*x[i+1]*y[i])/
					sqrt(1.0*(x[i+1]-x[i])*(x[i+1]-x[i])+1.0*(y[i+1]-y[i])*(y[i+1]-y[i])));
		r1=min(r1,sqrt(1.0*x[i]*x[i]+1.0*y[i]*y[i]));
		r2=max(r2,sqrt(1.0*x[i]*x[i]+1.0*y[i]*y[i]));
	}
	printf("%.12lf",acos(-1)*(r2*r2-r1*r1));
}