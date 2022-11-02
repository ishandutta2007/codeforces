#include<bits/stdc++.h>
using namespace std;

const int maxn=100010;
int n,m,k;
int a[maxn];
priority_queue<int,vector<int>,greater<int> > dui;

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans++;
		if (i>1)	dui.push(a[i]-a[i-1]-1);
	}
	for (int i=1;i<=n-k;i++)
	{
		ans+=dui.top();
		dui.pop();
	}
	printf("%d\n",ans);
	return 0;
}