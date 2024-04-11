#include<bits/stdc++.h>
using namespace std;
int const N=2333;
int n,t,a[N];
int main(){
	cin>>n;a[n]=1;
	for(int i=1;i<=n;i++){
		cout<<"?";
		for(int j=1;j<=n;j++)
			cout<<" "<<(j<n?n:i);
		cout<<endl,cin>>t;
		if(t){a[n]=n-i+1;break;}
	}
	for(int i=1;i<=n;i++){
		cout<<"?";
		for(int j=1;j<=n;j++)
			cout<<" "<<(j<n?a[n]:i);
		cout<<endl,cin>>t,a[t]=i;
	}
	cout<<"!";
	for(int i=1;i<=n;i++)
		cout<<" "<<a[i];
	cout<<endl;
}