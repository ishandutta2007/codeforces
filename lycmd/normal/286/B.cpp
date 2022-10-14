#include<bits/stdc++.h>
using namespace std;
int const N=2000010;
int n,a[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		a[i]=i;
	for(int i=2;i<=n;i++){
		a[n+i-1]=a[n/i*i+i-1];
		for(int j=n/i*i+i-1;j>=i+1;j-=i)
			a[j]=a[j-i];
	}
	for(int i=n;i<=n+n-1;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}