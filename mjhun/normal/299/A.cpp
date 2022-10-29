#include <iostream>
using namespace std;

int a[100005];

int mcd(int b, int c){
	int t;
	while(c!=0){
		t=b%c;
		b=c;
		c=t;
	}
	return b;
}

int main(){
	int n,i,m;
	bool bl=true;
	cin>>n;
	for(i=1;i<=n;++i)
		cin>>a[i];
	
	m=a[1];
	
	for(i=2;i<=n&&m!=1;++i)
		m=mcd(m,a[i]);
	
	i=1;
	while(i<=n&&a[i]!=m) ++i;
	
	cout<<((i>n)?(-1):m)<<endl;
	
	return 0;
}