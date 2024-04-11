#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long ans=0;
	int n,i,j;cin>>n;
	for (i=2;i<n;i++) ans+=i*(i+1);
	cout<<ans;
}