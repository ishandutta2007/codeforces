#include<bits/stdc++.h>
using namespace std;
int const N=200010;
int n,a[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]+=i;
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
		if(a[i]==a[i+1])
			cout<<":(\n",exit(0);
	for(int i=1;i<=n;i++)
		cout<<a[i]-i<<" ";
	cout<<"\n";
}