#include<iostream>
using namespace std;
int t[105];
int main(){
	int n,m;
	int i,j,k;
	int a,b;
	int s=0;
	cin>>n>>m;
	m++;
	for(i=0;i<n;i++){
		cin>>a;
		t[--a]++;
	}
	for(i=0,a=0;i<m;i++){
		a+=t[i];
	}
	for(i=0,s=a;i<100-m;i++){
		a+=t[i+m]-t[i];
		if(s<a)s=a;
	}
	s=n-s;
	cout<<s<<endl;
	return 0;
}