#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
int main()
{
	int T;ll n,x,y,d,ans1,ans2;cin>>T;
	while (T--)
	{
		cin>>n>>x>>y>>d;
		if (abs(y-x)%d==0) cout<<abs(y-x)/d<<endl;
		else
		{
			ans1=1e17;ans2=1e17;
			if (y%d==1) ans1=(y-1)/d+(ll)ceil(1.0*x/d);
			if ((n-y+1)%d==1) ans2=(n-y)/d+(ll)ceil(1.0*(n-x)/d);
			ans1=min(ans1,ans2);
			if (ans1>1e12) puts("-1");
			else cout<<ans1<<endl;
		}
	}
}