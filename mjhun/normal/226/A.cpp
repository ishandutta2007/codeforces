#include <iostream>
#define ull unsigned long long int
using namespace std;
int n,m;
ull r;
ull pw(int i){
	if(i==0)return 1;
	ull a;
	if(i%2==0){
		a=pw(i/2);
		return (a*a)%m;
	}
	return (3*pw(i-1))%m;
}
int main(){
	cin>>n>>m;
	r=pw(n);
	r=(r+m-1)%m;
	cout<<r<<endl;
}