#include<iostream>
using namespace std;
int main(){
	int n;
	int a,b,c;
	cin>>n;
	if(n==1){
		cout<<"1 1\n1"<<endl;
	}else{
		cout<<(n-1)*2<<" 2\n1 2"<<endl;
		return 0;
	}
}