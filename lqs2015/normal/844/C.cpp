#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
int n,a[111111],b[111111],pos;
map<int,int> mp;
vector<vector<int> > v;
vector<int> cur;
bool used[111111];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) b[i]=a[i];
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++) mp[b[i]]=i;
	for (int i=1;i<=n;i++)
	{
		if (used[i]) continue;
		cur.clear();
		pos=i;
		cur.push_back(i); 
		while(1)
		{
			used[pos]=1;
			pos=mp[a[pos]];
			if (used[pos]) break;
			cur.push_back(pos); 
		}
		v.push_back(cur); 
	}
	printf("%d\n",v.size());
	for (int i=0;i<v.size();i++)
	{
		printf("%d ",v[i].size());
		sort(v[i].begin(),v[i].end());
		for (int j=0;j<v[i].size();j++)
		{
			printf("%d ",v[i][j]);
		}
		printf("\n");
	}
	return 0;
}