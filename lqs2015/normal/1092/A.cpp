#include<bits/stdc++.h>
using namespace std;
int n,k,t,len;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		len=n/k;
		for (int i=1;i<=k;i++)
		{
			for (int j=1;j<=len;j++) 
			{
				cout<<(char)(i+'a'-1);
			}
		}
		for (int i=1;i<=n-k*len;i++) cout<<'a';
		cout<<endl;
	}
	return 0;
}