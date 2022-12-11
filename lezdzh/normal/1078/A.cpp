#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	long long a,b,c;
	long long x0,y0,x,y;
	cin>>a>>b>>c>>x0>>y0>>x>>y;
	c+=a*x0;
	c+=b*y0;
	c=-c;
	x-=x0;
	y-=y0;
	if(x<0)a=-a,x=-x;
	if(y<0)b=-b,y=-y;
	if(c<0)a=-a,b=-b,c=-c;
	if(!x||!y||a*b>=0)printf("%.12f\n",1.0*(x+y));
	else{
		double u=min(1.0*x,max(0.,1.0*c/a)),v=max(0.,min(1.0*x,1.0*(c-b*y)/a)),uu=1.0*(c-a*u)/b,vv=1.0*(c-a*v)/b;
		printf("%.12f\n",u+uu+sqrt((v-u)*(v-u)+(vv-uu)*(vv-uu))+x+y-v-vv);
	}
}