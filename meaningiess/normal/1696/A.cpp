#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,z,i,mx=0;cin>>n>>z;
		for (i=1;i<=n;i++) {int t;cin>>t;mx=max(mx,t|z);}
		cout<<mx<<endl;
	}
}