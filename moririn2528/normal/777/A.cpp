#include<iostream>
using namespace std;
int main(){
	int n,m;
	int i,j,k;
	int a[3]={0,1,2};
	cin>>n>>m;
	n%=6;
	for(i=0;i<n;i++){
		if(i%2==0){
			j=a[0],a[0]=a[1],a[1]=j;
		}else{
			j=a[2],a[2]=a[1],a[1]=j;
		}
	}
	cout<<a[m]<<endl;
	return 0;
}