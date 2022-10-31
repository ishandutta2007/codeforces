#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
template<class T>
void Read(T &x){
	static char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			if(f)
				x=-x;
			ungetc(c,stdin);
			return;
		}
	}
}
#define MAXN 10000
int x[MAXN+10],y[MAXN+10],n,mix=0x7fffffff,mxy,mxx=0x80000000,miy=0x7fffffff,w,v,u;
int main()
{
	Read(n),Read(w),Read(v),Read(u);
	int i;
	for(i=1;i<=n;i++){
		Read(x[i]),Read(y[i]);
		mix=min(x[i],mix);
		miy=min(y[i],miy);
	}
	for(i=1;i<=n;i++){
		if(x[i]==mix)
			mxy=max(mxy,y[i]);
		if(y[i]==miy)
			mxx=max(mxx,x[i]);
	}
	bool flag=0;
	if(1ll*u*mix>=1ll*v*mxy){
		for(i=1;i<=n;i++)
			if(x[i]==mix&&y[i]==mxy)
				break;
		while(1ll*(y[(i+n-2)%n+1]-y[i])*v>=1ll*u*(x[(i+n-2)%n+1]-x[i])){
			if(1ll*u*x[(i+n-2)%n+1]<1ll*y[(i+n-2)%n+1]*v){
				flag=1;
				break;
			}
			i=(i+n-2)%n+1;
		}
		if(!flag){
			printf("%.10lf\n",1.0*w/u);
			return 0;
		}
	}
	flag=0;
	for(i=1;i<=n;i++)
		if(x[i]==mxx&&y[i]==miy)
			break;
	if(1ll*x[i]*u>1ll*y[i]*v)
		flag=1;
	while(1ll*(y[i%n+1]-y[i])*v<1ll*(x[i%n+1]-x[i])*u){
		if(1ll*x[i%n+1]*u>1ll*y[i%n+1]*v)
			flag=1;
		i=i%n+1;
	}
	if(flag)
		printf("%.10lf\n",1.0*x[i]/v+1.0*(w-y[i])/u);
	else
		printf("%.10lf\n",1.0*w/u);
}