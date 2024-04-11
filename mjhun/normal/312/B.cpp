#include <iostream>
using namespace std;

int main(){
	int a,b,c,d;
	double r,ra,n1,n2,p1,p2,m1,m2;
	cin>>a>>b>>c>>d;
	p1=(double)a/b;
	p2=(double)c/d;
	n1=1-p1;
	n2=1-p2;
	r=p1;ra=0;
	m1=1;
	m2=1;
	while(r!=ra){
		ra=r;
		m1*=n1;
		m2*=n2;
		r+=m1*m2*p1;
	}
	cout.precision(15);
	cout<<r<<endl;
	return 0;
}