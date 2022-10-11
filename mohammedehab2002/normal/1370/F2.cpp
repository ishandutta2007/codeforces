#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
int n,dep[2][1005],par[1005];
pair<int,int> query(int d,int d2)
{
	vector<int> q;
	for (int i=1;i<=n;i++)
	{
		if (min(dep[0][i],dep[1][i])==d && dep[0][i]+dep[1][i]!=d2)
		q.push_back(i);
	}
	cout << "? " << q.size();
	for (int i:q)
	cout << " " << i;
	cout << endl;
	int a,b;
	cin >> a >> b;
	assert(a!=-1);
	return {a,b};
}
void getdep(int a,int b)
{
	memset(dep,-1,sizeof(dep));
	for (int j=0;j<2;j++)
	{
		dep[j][a]=0;
		queue<int> q;
		q.push(a);
		while (!q.empty())
		{
			int node=q.front();
			q.pop();
			for (int u:v[node])
			{
				if (dep[j][u]==-1)
				{
					q.push(u);
					dep[j][u]=dep[j][node]+1;
					par[u]=node;
				}
			}
		}
		swap(a,b);
	}
}
int main()
{
	cout.flush();
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i=1;i<=n;i++)
		v[i].clear();
		for (int i=1;i<n;i++)
		{
			int a,b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		getdep(1,1);
		int l=query(0,1e9).second;
		auto p=query((l+1)/2,1e9);
		int up=(l+1)/2-(l-p.second)/2,f=p.first,s=p.first,d1=p.second,d2=up;
		while (up--)
		s=par[s];
		while (d1!=d2)
		{
			getdep(f,s);
			p=query((d1-d2+1)/2,d2);
			if (dep[0][p.first]<dep[1][p.first])
			f=p.first;
			else
			s=p.first;
			d2+=(d1-d2+1)/2;
		}
		cout << "! " << f << ' ' << s << endl;
		string ans;
		cin >> ans;
		if (ans[0]=='I')
		return 0;
	}
}