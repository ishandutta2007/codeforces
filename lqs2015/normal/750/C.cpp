#include<iostream>
using namespace std;
int n,l,r,c,x,y;
int main()
{
	l=-1e9;r=1e9;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>x>>y;
		if (y==1) l=max(l,1900-c);
		else r=min(r,1900-c);
		c+=x;
	}
	if (l>=r) cout<<"Impossible"<<endl;
	else if (r==1e9) cout<<"Infinity"<<endl;
	else cout<<r+c-1<<endl;
	return 0;
}