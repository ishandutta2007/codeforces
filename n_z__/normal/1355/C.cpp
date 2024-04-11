#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int ans=0;
	for(int x=max(c+1,a+b);x<=b+c;x++)
		ans+=(min(d+1,x)-c)*(min(x-b,b)-max(x-c,a)+1);
	cout<<ans;
}