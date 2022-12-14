#include<iostream>
#include<cstdio>
#include<set>
#include<map>
using namespace std;
map<long long,set<int> > mp;
set<int> s;
set<long long> sp;
long long a[155555];
int n,fr,se,ans;
bool f[155555];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		mp[a[i]].insert(i); 
	}
	for (map<long long,set<int> >::iterator it=mp.begin();it!=mp.end();it++)
	{
		s=it->second;
		if (s.size()>1) sp.insert(it->first); 
	}
	while(!sp.empty())
	{
		long long pos=*sp.begin();
		sp.erase(sp.begin());
		set<int>::iterator it=mp[pos].begin();
		fr=*it;it++;se=*it;
		a[se]*=2;
		f[fr]=1;
		mp[pos].erase(mp[pos].begin());
		mp[pos].erase(mp[pos].begin());
		if (mp[pos].size()>1) sp.insert(pos);
		if (mp[pos*2].size()==1) sp.insert(pos*2);
		mp[pos*2].insert(se); 
	}
	for (int i=1;i<=n;i++) 
	{
		if (!f[i]) ans++;
	}
	printf("%d\n",ans);
	for (int i=1;i<=n;i++)
	{
		if (!f[i])
		{
			printf("%I64d ",a[i]);
		}
	}
	return 0;
}