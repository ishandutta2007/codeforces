#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,Q,a[222222],b[222222],x;
long long m;
deque<int> q;
int main()
{
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		q.push_back(x);
	}
	for (int i=1;i<=2*n;i++)
	{
		a[i]=q[0];b[i]=q[1];
		if (a[i]<b[i])
		{
			q.pop_front();
			q.push_back(a[i]);
		}
		else
		{
			q.pop_front();q.pop_front();
			q.push_front(a[i]);q.push_back(b[i]);
		}
	}
	for (int i=1;i<=Q;i++)
	{
		scanf("%lld",&m);
		if (m<=2*n) 
		{
			printf("%d %d\n",a[m],b[m]);
		}
		else
		{
			printf("%d %d\n",q[0],q[(m-1-2*n)%(n-1)+1]);
		}
	}
	return Accepted;
}