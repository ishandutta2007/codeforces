#include<bits/stdc++.h>
using namespace std;
string a[105];
int main()
{
	int n;
	cin>>n;
	int ans=n;
	for(int i=0;i<n;i++)
	{
		string s,t;
		cin>>s>>t;
		a[i]=s+' '+t;
		for(int j=0;j<i;j++)
			if(a[i]==a[j])
			{
				ans--;
				break;
			}
	}
	cout<<ans<<endl;
	return 0;
}