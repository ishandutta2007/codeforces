#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,ans=INT_MAX,x[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	sort(x+1,x+1+n);
	for(int i=1;i<=n/2;i++)
		ans=min(ans,x[i+n/2]-x[i]);
	cout<<ans<<"\n";
}