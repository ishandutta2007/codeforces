#include <iostream>
using namespace std;
long long int x,y,x2,y2;
int mcd(int a, int b){
	int q,r,t;
	x=0;x2=1;y=1;y2=0;
	
	while(b!=0){
		q=a/b;
		r=a%b;
		
		t=x;
		x=x2-q*x;
		x2=t;
		
		t=y;
		y=y2-q*y;
		y2=t;
		
		a=b;
		b=r;
	}
	return a;
}

int main(){
	long long int a,b,c,m;
	cin>>a>>b>>c;
	m=mcd(a,b);
	if(c%m!=0)
		cout<<-1<<endl;
	else
		cout<<-x2*(c/m)<<' '<<-y2*(c/m)<<endl;
	return 0;
}