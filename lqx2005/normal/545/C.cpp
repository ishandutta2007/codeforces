#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,h;
}a[100005];
bool cmp(node a,node b)
{
	return a.x<b.x;
}
int main()
{
	ios::sync_with_stdio(0);
	int n,ans,x,h;
	cin>>n;
	if(n>=2) ans=2;
	else ans=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].h;
	}
	sort(a+1,a+n+1,cmp);
	bool flag=0; 
	for(int i=2;i<=n-1;i++)
	{
		if(flag)
		{
			if(a[i].x-a[i].h>a[i-1].x+a[i-1].h)
			{
				ans++;
				flag=0;
			}
			else if(a[i].x+a[i].h<a[i+1].x)
			{
				ans++;
			}
			else
			{
				flag=0;
			}
		}
		else
		{
			if(a[i].x-a[i].h>a[i-1].x)
			{
				ans++;
			}
			else if(a[i].x+a[i].h<a[i+1].x)
			{
				flag=1;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}