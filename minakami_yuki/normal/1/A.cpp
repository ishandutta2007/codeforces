#include<iostream>
using namespace std;
int main(){
	long long n,m,a;
	cin>>n>>m>>a;
	n=(n+a-1)/a;
	m=(m+a-1)/a;
	cout<<n*m<<endl;
	return 0; 
}