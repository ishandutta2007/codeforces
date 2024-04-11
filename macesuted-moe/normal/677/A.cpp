#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		if(t<=k) ans++;
		else    ans+=2;
	}
	cout<<ans<<endl;
	return 0;
}