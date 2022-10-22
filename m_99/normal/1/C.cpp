#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000
#define PI 3.14159265358979323846
double get_dis(double x1,double y1,double x2,double y2){
	return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

double naiseki(double x1,double y1,double x2,double y2){
	return x1*x2+y1*y2;
}

double get(double a,double b,double c){
	return pow(c,2)*(pow(a,2)+pow(b,2)-pow(c,2));
}

int main(){
	
	double x1,x2,x3,y1,y2,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	
	double c = get_dis(x1,y1,x2,y2),a = get_dis(x2,y2,x3,y3),b = get_dis(x3,y3,x1,y1);

	double X = get(b,c,a)+get(c,a,b)+get(a,b,c);
	double x4 = (get(b,c,a)*x1 + get(c,a,b)*x2 + get(a,b,c)*x3) / X;
	double y4 = (get(b,c,a)*y1 + get(c,a,b)*y2 + get(a,b,c)*y3) / X;
	
	//cout<<fixed<<setprecision(15)<<get_dis(x1,y1,x4,y4)<<','<<get_dis(x2,y2,x4,y4)<<','<<get_dis(x3,y3,x4,y4)<<endl;;
	
	double dir1 = acos(naiseki(x1-x4,y1-y4,x2-x4,y2-y4)/(get_dis(x1,y1,x4,y4)*get_dis(x2,y2,x4,y4)));
	double dir2 = acos(naiseki(x2-x4,y2-y4,x3-x4,y3-y4)/(get_dis(x2,y2,x4,y4)*get_dis(x3,y3,x4,y4)));
	double dir3 = acos(naiseki(x3-x4,y3-y4,x1-x4,y1-y4)/(get_dis(x3,y3,x4,y4)*get_dis(x1,y1,x4,y4)));
	/*
	cout<<x2-x4<<','<<y2-y4<<','<<x3-x4<<','<<y3-y4<<endl;
  	cout<<naiseki(x2-x4,y2-y4,x3-x4,y3-y4)<<endl;
	cout<<dir1<<','<<dir2<<','<<dir3<<endl;
	*/
	for(int i=3;i<=100;i++){
		double A = (3.14159265358979323846*2.0)/i;
		if(abs(round(dir1/A)-(dir1/A))>=0.00001)continue;
		if(abs(round(dir2/A)-(dir2/A))>=0.00001)continue;
		if(abs(round(dir3/A)-(dir3/A))>=0.00001)continue;
		
		
		
		double S;
		double l = get_dis(x1,y1,x4,y4);
		S = 0.5 * l * l * sin(A) * i;
		
		
		
		cout<<fixed<<setprecision(10)<<S<<endl;
		return 0;
	}
	
	return 0;
}