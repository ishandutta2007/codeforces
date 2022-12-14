#include<bits/stdc++.h>
using namespace std;
int n,l,r,mid;
string s,str;
int main()
{
	cin>>n;
	cout<<0<<" "<<0<<endl;
	fflush(stdout);
	cin>>s;
	l=1;r=1e9;
	for (int i=1;i<n;i++)
	{
		mid=(l+r)/2;
		cout<<0<<" "<<mid<<endl;
		fflush(stdout);
		cin>>str;
		if (str==s) l=mid+1;
		else r=mid-1;
	}
	if (l>r)
	{
		if (!r) cout<<2<<" "<<l<<" "<<6<<" "<<l+1<<endl; 
		else cout<<2<<" "<<r<<" "<<6<<" "<<r-1<<endl;
	}
	else
	{
		cout<<0<<" "<<l<<" "<<1000<<" "<<l<<endl;
	}
	return 0;
}