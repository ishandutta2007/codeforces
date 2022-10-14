#include<bits/stdc++.h>
using namespace std;
int const N=233;
int n,a[N],s;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],s+=a[i];
	cout<<s<<"\n";
}