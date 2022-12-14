#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n,a[555555],mx,mn,ans,r;
bool used[555555];
queue<int> q;
int main()
{
	scanf("%d",&n);
	mn=1e9;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	ans=n;r=2;
	for (int i=1;i<=n/2;i++)
	{
		if (a[i]*2>mx) break;
		if (used[i])
		{
			if (!q.empty())
			{
				used[q.front()]=1;
				q.pop();
			}
			else used[r++]=1;
		}
		while(a[r]<a[i]*2) 
		{
			q.push(r); 
			r++;
		}
		if (r>n) break;
		used[r]=1;
		r++;
		if (!q.empty() && q.front()==i+1) q.pop();
		ans=n-i;
	}
	cout<<ans<<endl;
	return 0;
}