#include <bits/stdc++.h>
using namespace std;
int a[100005],no[100005];
map<int,vector<int> > m;
int main()
{
	int n,p,mx=0;
	scanf("%d%d",&n,&p);
	for (int i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(a,a+n);
	for (int i=0;i<n;i++)
	{
		no[(a[i]%p-i%p+p-1)%p]++;
		mx=max(mx,a[i]-i-1);
	}
	for (int i=0;i<n;i++)
	m[max(a[i],mx)].push_back(i);
	vector<int> v;
	for (int x=mx;x<a[n-1];x++)
	{
		bool br=0;
		for (int i:m[x])
		{
			if ((i+1)%p==0)
			br=1;
			no[(a[i]%p-i%p+p-1)%p]--;
		}
		if (br)
		break;
		if (!no[x%p])
		v.push_back(x);
	}
	printf("%d\n",v.size());
	for (int i:v)
	printf("%d ",i);
}