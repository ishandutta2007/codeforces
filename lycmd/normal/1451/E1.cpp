#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[233333],p1,p2,p3,p4,p5;
signed main(){
	cin>>n;
	cout<<"AND 1 2"<<endl;cin>>p1;
	cout<<"AND 1 3"<<endl;cin>>p2;
	cout<<"XOR 1 2"<<endl;cin>>p3;
	cout<<"XOR 1 3"<<endl;cin>>p4;
	cout<<"AND 2 3"<<endl;cin>>p5;
	a[1]=((p1|p2)|((p3&p4)^p5));a[2]=a[1]^p3;a[3]=a[1]^p4;
	for(int i=4;i<=n;i++){
		cout<<"XOR 1 "<<i<<endl; 
		int t;cin>>t;a[i]=a[1]^t;
	}fflush(stdout);cout<<"! ";
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
}
//