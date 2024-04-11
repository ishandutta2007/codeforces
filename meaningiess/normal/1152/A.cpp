#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i,t0[2]={},t1[2]={},t,ans=0;cin>>n>>m;
	for (i=1;i<=n;i++) cin>>t,t0[t%2]++;
	for (i=1;i<=m;i++) cin>>t,t1[t%2]++;
	cout<<min(t0[0],t1[1])+min(t0[1],t1[0]);
}