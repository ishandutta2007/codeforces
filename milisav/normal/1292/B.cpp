#include<bits/stdc++.h>
using namespace std;
long long xi0,yi0,ax,ay,bx,by;
long long xs,ys,t;
long long x[1000000];
long long y[1000000];
int main() {
	scanf("%lld %lld %lld %lld %lld %lld",&xi0,&yi0,&ax,&ay,&bx,&by);
	scanf("%lld %lld %lld",&xs,&ys,&t);
	int n=1;
	x[0]=xi0;
	y[0]=yi0;
	while(x[n-1]<=xs+t && y[n-1]<=ys+t) {
		x[n]=ax*x[n-1]+bx;
		y[n]=ay*y[n-1]+by;
		n++;
	}
	int ma=0;
	for(int i=0;i<n;i++) {
		for(int j=i;j<n;j++) {
			long long t1;
			t1=min(abs(xs-x[i])+abs(ys-y[i]),abs(xs-x[j])+abs(ys-y[j]));
			if(t1<=t && t1+x[j]-x[i]+y[j]-y[i]<=t) {
				ma=max(ma,j-i+1);
			}
		}
	}
	printf("%d",ma);
	return 0;
}