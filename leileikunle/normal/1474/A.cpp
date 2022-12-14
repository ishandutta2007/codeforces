#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tt; cin>>tt;
	while(tt--)
	{
		char a[100005]={0};
		char b[100005]={0};	
		int n; cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		b[0] = '1';
		for(int i=1;i<n;i++)
		{
			if((a[i-1]+b[i-1])==(a[i]+'1')) b[i] = '0';
			else b[i]='1';
		}
		for(int i=0;i<n;i++)
		{
			cout<<b[i];
		}
		cout<<endl;
	}
 }