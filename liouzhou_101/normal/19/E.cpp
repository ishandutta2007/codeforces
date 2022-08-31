#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>

using namespace std;

const int MaxN=10010;

int n,m;
int x[MaxN],y[MaxN];
vector<pair<int,int> > v[MaxN];
int used[MaxN],flag[MaxN],pre[MaxN];

int have,get,root;
int Time,first[MaxN],second[MaxN];
int alive[MaxN],on[MaxN];

bitset<MaxN> u[MaxN];

vector<int> ans;

void build(int x,int p)
{
	used[x]=1;
	flag[x]=p;
	first[x]=++Time;
	u[x][x]=1;
	for (vector<pair<int,int> >::iterator it=v[x].begin();it!=v[x].end();++it)
		if (!used[it->first])
		{
			pre[it->first]=x;
			build(it->first,p^1);
			second[x]=Time;
			on[it->second]=1;
			u[x]|=u[it->first];
		}
		else if (flag[it->first]!=(p^1))
			get=1;
}

void init()
{
	cin>>n>>m;
	for (int i=1;i<=m;++i)
	{
		scanf("%d%d",&x[i],&y[i]);
		v[x[i]].push_back(make_pair(y[i],i));
		v[y[i]].push_back(make_pair(x[i],i));
	}
	for (int i=1;i<=n;++i)
		if (!used[i])
		{
			build(i,0);
			if (get)
			{
				++have;
				get=0;
				root=i;
			}
		}
}

void work()
{
	if (have>1)
	{
		puts("0");
		return;
	}
	if (!have)
	{
		cout<<m<<endl;
		for (int i=1;i<=m;++i)
		{
			if (i>1) putchar(' ');
			printf("%d",i);
		}
		return;
	}
	for (int i=1;i<=m;++i)
	{
		if (u[root][x[i]]&&u[root][y[i]])
			alive[i]=1;
	}
	for (int i=1;i<=m;++i) if (alive[i]&&!on[i])
		if (flag[x[i]]==flag[y[i]])
			ans.push_back(i);
	if (ans.size()>1) ans.clear();
	for (int i=1;i<=m;++i) if (on[i])
	{
		int task=0,rev=-1;
		int cut=(pre[x[i]]==y[i])?x[i]:y[i];
		for (int j=1;j<=m;++j) if (alive[j]&&!on[j])
			if (u[cut][x[j]]^u[cut][y[j]])
			{
				if (rev==-1)
					rev=flag[x[j]]^flag[y[j]];
				else if ((flag[x[j]]^flag[y[j]])!=rev)
				{
					task=1;
					break;
				}
			}
			else
				if (flag[x[j]]==flag[y[j]])
				{
					task=1;
					break;
				}
		if (!task) ans.push_back(i);
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();++i)
	{
		if (i) putchar(' ');
		printf("%d",ans[i]);
	}
}

int main()
{
	init();
	work();
	return 0;
}