#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MOD=12345;

long long n;

vector<int> v[26],tmp;
vector<pair<int,int> > w;
vector<vector<int> > p;

void DFS(int k)
{
	if (k==w.size())
	{
		p.push_back(tmp);
		return;
	}
	for (int i=0;i<w[k].second;++i)
	{
		tmp[k]=i;
		DFS(k+1);
	}
}

int m;
int A[130][130],V[130][130],t[130][130];

void init()
{
	int T;
	cin>>n>>T;
	while (T--)
	{
		char c;
		int x;
		cin>>c>>x;
		v[c-'A'].push_back(x);
	}
	for (int i=0;i<26;++i)
	{
		sort(v[i].begin(),v[i].end());
		v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
		for (int j=0;j<v[i].size();++j)
			w.push_back(make_pair(i,v[i][j]));
	}
	for (int i=0;i<w.size();++i)
		tmp.push_back(0);
	DFS(0);
	m=p.size();
	for (int i=0;i<m;++i)
		for (int k=0;k<26;++k)
			if (!v[k].empty())
			{
				tmp=p[i];
				for (int j=0;j<w.size();++j)
					if (w[j].first==k) (tmp[j]+=1)%=w[j].second;
				(A[lower_bound(p.begin(),p.end(),tmp)-p.begin()][i]+=1)%=MOD;
			}
}

void calc(long long n)
{
	if (!n)
	{
		for (int i=0;i<m;++i)
			for (int j=0;j<m;++j)
				V[i][j]=(i==j);
		return;
	}
	calc(n>>1);
	for (int i=0;i<m;++i)
		for (int j=0;j<m;++j)
		{
			t[i][j]=V[i][j];
			V[i][j]=0;
		}
	for (int i=0;i<m;++i)
		for (int j=0;j<m;++j)
			for (int k=0;k<m;++k)
				(V[i][j]+=t[i][k]*t[k][j])%=MOD;
	if (n&1)
	{
		for (int i=0;i<m;++i)
			for (int j=0;j<m;++j)
			{
				t[i][j]=V[i][j];
				V[i][j]=0;
			}
		for (int i=0;i<m;++i)
			for (int j=0;j<m;++j)
				for (int k=0;k<m;++k)
					(V[i][j]+=t[i][k]*A[k][j])%=MOD;
	}
}

void work()
{
	calc(n);
	int ans=0;
	for (int i=0;i<m;++i)
	{
		int flag=0;
		int used=0;
		for (int j=0;j<p[i].size();++j)
			if (!p[i][j]) used|=1<<w[j].first;
		for (int j=0;j<26;++j) if (!v[j].empty())
			if (!(used&(1<<j))) flag=1;
		if (flag) continue;
		(ans+=V[i][0])%=MOD;
	}
	cout<<ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}