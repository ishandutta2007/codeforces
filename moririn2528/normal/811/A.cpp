#include<iostream>
using namespace std;
int main(){
	int a[2];
	int i,j,k;
	cin>>a[0]>>a[1];
	for(i=0;;i++){
		a[i%2]-=i+1;
		if(a[i%2]<0){
			if(i%2==0)cout<<"Vladik"<<endl;
			else cout<<"Valera"<<endl;
			break;
		}
	}
	return 0;
}