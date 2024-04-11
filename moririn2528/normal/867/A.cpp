#include<iostream>
using namespace std;
int main(){
	int n;
	char ca[200];
	cin>>n;
	cin>>ca;
	if(ca[0]=='S' && ca[n-1]=='F')cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}