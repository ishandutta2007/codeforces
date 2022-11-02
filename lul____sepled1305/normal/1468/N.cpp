#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int c[3],a[5];
	cin>>c[0]>>c[1]>>c[2];
	cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
	c[0]-=a[0];
	c[1]-=a[1];
	c[2]-=a[2];
	if(c[1] < 0 || c[2]<0 || c[0] < 0)
	{
		cout<<"NO"<<endl;
		return;
	}
	a[3] -= min(a[3],c[0]);
	a[4] -= min(a[4],c[1]);
	c[2] -= a[3];
	c[2] -= a[4];
	if(c[2] >= 0)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}