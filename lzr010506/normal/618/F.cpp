#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int n,flag;
long long a[N],b[N];
vector< pair<int,int> > v[N];
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("tt.in","r",stdin);
	#endif
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]+=a[i-1];
	for(int i=1;i<=n;i++) scanf("%d",&b[i]),b[i]+=b[i-1];
	if(a[n]>b[n]) 
	{
		for(int i=1;i<=n;i++) swap(a[i],b[i]);
		flag=1;
	}
	v[0].push_back(make_pair(0,0));
	for(int j=0,i=1;i<=n;i++)
	{
		while(j<n&&b[j+1]<=a[i]) j++;
		v[a[i]-b[j]].push_back(make_pair(i,j));
	}
	for(int k=0;k<n;k++)
	if(v[k].size()>1)
	{
		if(!flag)
		{
			printf("%d\n",v[k][1].first-v[k][0].first);
			for(int i=v[k][0].first+1;i<=v[k][1].first;i++) printf("%d ",i);puts("");
			printf("%d\n",v[k][1].second-v[k][0].second);
			for(int i=v[k][0].second+1;i<=v[k][1].second;i++) printf("%d ",i);puts("");
			return 0;
		}
		else
		{
			printf("%d\n",v[k][1].second-v[k][0].second);
			for(int i=v[k][0].second+1;i<=v[k][1].second;i++) printf("%d ",i);puts("");
			printf("%d\n",v[k][1].first-v[k][0].first);
			for(int i=v[k][0].first+1;i<=v[k][1].first;i++) printf("%d ",i);puts("");
			return 0;
		}
	}

}