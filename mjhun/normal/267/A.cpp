#include <iostream>
using namespace std;
int main() {
	int n,a,b,r,t;
	cin>>n;
	while(n--){
		cin>>a>>b;
		r=0;
		while(a!=0&&b!=0){
			if(a<b){
				t=a;a=b;b=t;
			}
			r+=a/b;
			a=a%b;
		}
		cout<<r<<endl;
	}
	return 0;
}