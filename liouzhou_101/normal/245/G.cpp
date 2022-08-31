#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>
#include<string>

using namespace std;

const int MaxN=10010;

int n,m;
char s[MaxN][30],t[MaxN][30];
vector<string> p;
vector<int> v[MaxN];
short int F[MaxN][MaxN];
int d[MaxN],get[MaxN];
bitset<MaxN> b[MaxN];

int main()
{
	cin>>m;
	for (int i=1;i<=m;++i)
	{
		scanf("%s%s",s[i],t[i]);
		p.push_back(s[i]);
		p.push_back(t[i]);
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	n=p.size();
	for (int i=1;i<=m;++i)
	{
		int x=lower_bound(p.begin(),p.end(),s[i])-p.begin();
		int y=lower_bound(p.begin(),p.end(),t[i])-p.begin();
		v[x].push_back(y);
		v[y].push_back(x);
		b[x][y]=b[y][x]=1;
	}
	for (int i=0;i<n;++i)
	{
		sort(v[i].begin(),v[i].end());
		for (int x=0;x<v[i].size();++x)
			for (int y=x+1;y<v[i].size();++y)
				F[v[i][x]][v[i][y]]++;
	}
	cout<<n<<endl;
	for (int i=0;i<n;++i)
	{
		for (int j=i+1;j<n;++j)
		{
			if (b[i][j]) continue;
			if (F[i][j]>d[i])
			{
				d[i]=F[i][j];
				get[i]=1;
			}
			else if (F[i][j]==d[i])
				++get[i];
			if (F[i][j]>d[j])
			{
				d[j]=F[i][j];
				get[j]=1;
			}
			else if (F[i][j]==d[j])
				++get[j];
		}
		cout<<p[i]<<" "<<get[i]<<endl;
	}
	return 0;
}