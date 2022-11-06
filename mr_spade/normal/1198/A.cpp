#include<bits/stdc++.h>
#define int long long
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int N=1e6+5;
int n,I,K,ans;
int a[N];
signed main()
{
	register int i;
	ios::sync_with_stdio(0);
	cin>>n>>I;I*=8;
	if((I/n)>=40)
		return cout<<"0"<<endl,0;
	K=1ll<<(I/n);
	for(i=1;i<=n;i++)
		cin>>a[i];
	int l=1,ans=1,cnt=1;
	sort(a+1,a+n+1);
	for(i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1])
			cnt++;
		while(cnt>K)
		{
			if(a[l]!=a[l+1])
				cnt--;
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<n-ans<<endl;
	return 0;
}