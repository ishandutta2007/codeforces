#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;cin>>n>>m;
	if (m<=n/2) cout<<max(1,m);else cout<<max(0,n-m);
}