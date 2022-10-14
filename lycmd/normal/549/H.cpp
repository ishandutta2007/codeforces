#include<bits/stdc++.h>
#define double long double
#define calc(f,a,b) (f(f((a+k)*(b+k),(a+k)*(b-k)),f((a-k)*(b+k),(a-k)*(b-k)))) 
using namespace std;
double a,b,c,d;
int check(double k){
	return calc(max,a,d)>=calc(min,b,c)&&calc(min,a,d)<=calc(max,b,c);
} 
int main(){
	cin>>a>>b>>c>>d;
	double l=0.0,r=2e9;
	while(r-l>max(r,1.0l)*1e-9){
		double mid=(l+r)/2.0;
		if(check(mid))r=mid;else l=mid;
	}
	cout<<fixed<<setprecision(10)<<r<<"\n";
}