#include <iostream>
using namespace std;

int main(){
	int p,x,r=0,i;
	unsigned long long int a;
	bool b;
	cin>>p;
	if(p==2){
		cout<<1<<endl;
		return 0;
	}
	for(x=2;x<p;++x){
		b=true;
		i=a=1;
		while(b&&i<p-1){
			a*=x;
			b = (a-1)%p !=0;
			if(b)
				a=a%p;
			++i;
		}
		if(b){
			b=(a*x-1)%p==0;
		}
		r+=b?1:0;
	}
	cout<<r<<endl;
	return 0;
}