#include <iostream>
using namespace std;
unsigned long long int mcd(unsigned long long int a, unsigned long long int b){
	unsigned long long int t;
	while(b!=0){
		t=b;
		b=a%t;
		a=t;
	}
	return a;
}
int main(){
	unsigned long long int b,c,m,p,q;
	unsigned long long int a[100];
	int n,i;
	cin>>p>>q;
	m=mcd(p,q);
	p/=m;
	q/=m;
	cin>>n;
	for(i=1;i<=n;++i)
		cin>>a[i];
	b=1;
	c=a[n];
	bool r=true;
	for(i=n-1;i>=1;--i){
		m=b;
		b=c;
		if(c*a[i]/a[i]!=c||c*a[i]+m<m)r=false;
		c=c*a[i]+m;
	}
	cout<<((r&&c==p&&b==q)?"YES":"NO")<<endl;
	return 0;
}