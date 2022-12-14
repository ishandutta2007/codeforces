#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		char a[n+1];
		cin>>a;
		if(a[0]=='2' && a[1]=='0' && a[2]=='2' && a[3]=='0'){
			cout<<"YES"<<endl;
		}else if(a[0]=='2' && a[1]=='0' && a[2]=='2' && a[3]!='0')
		{
			if(a[n-1]=='0'){
				cout<<"YES"<<endl;
			}else{
			cout<<"NO"<<endl;
			}
		}else if(a[0]=='2' && a[1]=='0' && a[2]!='2')
		{
			if(a[n-1]=='0' && a[n-2]=='2')
			{
				cout<<"YES"<<endl;
			}else{
			cout<<"NO"<<endl;
			}	
		}else if(a[0]=='2' && a[1]!='0')
		{
			//cout<<1<<endl;
			if(a[n-1]=='0' && a[n-2]=='2' && a[n-3]=='0')
			{
				cout<<"YES"<<endl;
			}else{
			cout<<"NO"<<endl;
			}
		}else if(a[0]!='2')
		{
			if(a[n-1]=='0' && a[n-2]=='2' && a[n-3]=='0' &&a[n-4]=='2')
			{
				cout<<"YES"<<endl;
			}else{
			cout<<"NO"<<endl;
			}
		}
	}
}