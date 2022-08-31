#include<cstdio>
#include<iostream>

using namespace std;

int x0,y0,z0,x1,y1,z1,a1,a2,a3,a4,a5,a6;

void solve()
{
	int ans=0;
	if (y0<0) ans+=a1;
	if (y0>y1) ans+=a2;
	if (z0<0) ans+=a3;
	if (z0>z1) ans+=a4;
	if (x0<0) ans+=a5;
	if (x0>x1) ans+=a6;
	cout<<ans<<endl;
}

int main()
{
	cin>>x0>>y0>>z0>>x1>>y1>>z1>>a1>>a2>>a3>>a4>>a5>>a6;
	solve();
	return 0;
}