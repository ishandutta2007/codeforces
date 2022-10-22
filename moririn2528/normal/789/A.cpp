#include<iostream>
using namespace std;
int main(){
	int n,m;
	int i,j,k;
	int a,b;
	int s=0;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a;
		s+=(a-1)/m+1;
	}
	s=(s-1)/2+1;
	cout<<s<<endl;
	return 0;
}