#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=1<<20;

int n;
int a[MaxN];
int u[MaxN];
int v[30];
vector<pair<int,int> > w;

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;++i)
	{
		if (a[i]==0) u[0]=1;
		w.clear();
		for (int j=0;j<20;++j)
		{
			if (a[i]&(1<<j)) v[j]=i;
			if (v[j]) w.push_back(make_pair(v[j],j));
		}
		sort(w.begin(),w.end());
		int now=0;
		for (vector<pair<int,int> >::reverse_iterator it=w.rbegin();it!=w.rend();++it)
		{
			now|=a[it->first];
			u[now]=1;
		}
	}
	int ans=0;
	for (int i=0;i<(1<<20);++i)
		ans+=u[i];
	cout<<ans<<endl;
	return 0;
}