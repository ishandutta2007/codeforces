#include<bits/stdc++.h>
using namespace std;
long long n,x,ans;
priority_queue<long long>q;
signed main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		x-=i;
		q.push(x);
		if (q.top()>x)
		{
			ans+=q.top()-x;
			q.pop();
			q.push(x);
		}
	}
	cout<<ans;
}