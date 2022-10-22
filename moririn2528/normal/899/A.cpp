#include<iostream>
using namespace std;
int main(){
	int a[2]={0};
	int s=0;
	int n;
	int i,j,k;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k;
		a[k-1]++;
	}
	s=min(a[0],a[1]);
	a[0]-=s,a[1]-=s;
	s+=a[0]/3;
	cout<<s<<endl;
	return 0;
}