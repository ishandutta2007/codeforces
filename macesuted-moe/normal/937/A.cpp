#include<iostream>
#include<string>
#include <cstring>
using namespace std;

int a[605];

int main()
{
	memset(a,0,sizeof(a));
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		a[t]++;
	}
	int ans=0;
	for(int i=1;i<601;i++) if(a[i]) ans++;
	cout<<ans<<endl;
	return 0;
}