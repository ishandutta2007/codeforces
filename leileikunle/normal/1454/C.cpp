#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T; cin>>T;
	while(T--)
	{
		int n;  cin>>n;
		int a[n+2]={0},b[n+2]={0},c[n+2]={0};
		a[0] = 0;
		int maxn = 0;
		int minn = 2*1e5+1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			c[a[i]] = 1;
			maxn = max(maxn,a[i]);
			minn = min(minn,a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i] != a[i-1])
				b[a[i]]++;
		}
		b[a[1]]--;  b[a[n]]--;
		for(int i=1;i<=n;i++)
		{
			if(c[i]) b[i]++;
		}
		int minnn = b[minn];
		for(int i=1;i<=n;i++)
		{
				if(c[i])
				{
					int e = b[i];
					minnn = min(minnn,e);
				}	
		}
		cout<<minnn<<endl;
	}
}