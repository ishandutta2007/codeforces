#include <iostream>
using namespace std;

int main(){
	int n,a,b;
	cin>>n;
	a=n/36;
	n-=a*36;
	b=(n%3<2)?n/3:n/3+1;
	if(b>=12){
		b-=12;
		a++;
	}
	cout<<a<<' '<<b<<endl;
	return 0;
}