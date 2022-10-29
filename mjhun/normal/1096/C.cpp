#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int tn;
	cin>>tn;
	while(tn--){
		int a;
		cin>>a;//180*c/d=a
		int d=
		180/__gcd(180,a);
		if(d*a/180==d-1)d*=2;
		cout<<d<<endl;
	}
	return 0;

}