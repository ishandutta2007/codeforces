#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,k,x,ans=1;
int a[N];
vector<int> b;
signed main()
{
	register int i;
	cin>>n>>k>>x;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(i=2;i<=n;i++)
		if(a[i]-a[i-1]>x)
			ans++,b.push_back((a[i]-a[i-1]+x-1)/x-1);
	sort(b.begin(),b.end(),greater<int>());
	while(!b.empty())
		if(k>=b.back())
			k-=b.back(),ans--,b.pop_back();
		else
			break;
	cout<<ans<<endl;
	return 0;
}