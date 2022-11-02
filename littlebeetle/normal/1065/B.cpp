#include<cstdio>
#include<iostream>
using namespace std;
int n;
long long m,p;
int main(){
	cin>>n>>m;
	p=n-2*m;
	if(p<0)
		cout<<0<<' ';
	else
		cout<<p<<' ';
	for(p=0;p<=n;p++)
		if(p*(p-1)/2>=m){
			cout<<n-p;
			return 0;
		}
}