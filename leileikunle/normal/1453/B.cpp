#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T; cin>>T;
	while(T--)
	{
		int n; cin>>n;
		long long int a[n+2]={0},b[n+2]={0};
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		long long int sum = 0;
		for(int i=2;i<=n;i++)
		{
			b[i] = abs(a[i] - a[i-1]);
			sum += b[i];
		}
		long long int minn = sum-b[2];
		for(int i=1;i<=n;i++)
		{
			long long int f = sum;
			sum = sum - b[i] - b[i+1] + abs(a[i+1] - a[i-1]);
			minn = min(minn,sum);
			sum = f;
		}
		sum -= b[n];
		minn = min(minn,sum);
		cout<<minn<<endl;
	}
}