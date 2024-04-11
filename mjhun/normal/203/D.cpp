#include <iostream>
#define INF 1e10
using namespace std;

int main(){
	bool cont=true;
	double tx,ty,tz,a,b,m,vx,vy,vz,x,y,z,t;
	cin>>a>>b>>m>>vx>>vy>>vz;
	
	x=a/2;
	y=m;
	z=0;
	
	while(cont){
		if(vx==0)
			tx=INF;
		else if(vx>0)
			tx=(a-x)/vx;
		else
			tx=-x/vx;
		
		ty=-y/vy;
		
		if(vz==0)
			tz=INF;
		else if(vz>0)
			tz=(b-z)/vz;
		else
			tz=-z/vz;
			
		if(tx<ty&&tx<tz){
			t=tx;
		}
		else if(tz<ty&&tz<tx){
			t=tz;
		}
		else{
			t=ty;
			cont=false;
		}
		x+=vx*t;
		y+=vy*t;
		z+=vz*t;
		if(t==tx)
			vx=-vx;
		if(t==tz)
			vz=-vz;
	}
	cout.precision(15);
	cout<<x<<' '<<z<<endl;
	return 0;
}