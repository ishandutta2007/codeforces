#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define ll long long
#define N 2005
#define eps 1e-5
//#define M
using namespace std;

int n;
double s,x;

int main(){
	scanf("%d",&n);
	double q=n;
	rep(i,1,2*n){
		scanf("%lf",&x);
		if(abs(x-(int)x)<eps){
			q-=1;
			continue;
		}
		s+=(double)(int)(x+1)-x;
	}
	double ans=1e7;
	rep(i,q,n) if(abs(s-i)<ans) ans=abs(s-i);
	printf("%.3lf\n",ans);
//	for(;;);
}