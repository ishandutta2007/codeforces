#include<cstdio>
#include<iostream>
#include<vector>
#include<bitset>

using namespace std;

const int MaxN=5010;

int n;
vector<int> v[MaxN],son[MaxN];

void init()
{
	cin>>n;
	for (int i=1;i<n;++i)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
}

vector<int> Q;
bitset<MaxN> S,F;
int used[MaxN],have[MaxN];

void solve(int x)
{
	used[x]=1;
	for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
		if (!used[*it])
		{
			solve(*it);
			son[x].push_back(*it);
		}
	have[x]=1;
	Q.clear();
	for (vector<int>::iterator it=son[x].begin();it!=son[x].end();++it)
	{
		have[x]+=have[*it];
		Q.push_back(have[*it]);
	}
	Q.push_back(n-have[x]);
	S<<=MaxN;
	S[0]=1;
	for (vector<int>::iterator it=Q.begin();it!=Q.end();++it)
		S|=S<<*it;
	F|=S;
}

void work()
{
	solve(1);
	int p=0;
	for (int i=1;i<n-1;++i) p+=F[i];
	cout<<p<<endl;
	for (int i=1;i<n-1;++i)
		if (F[i]) cout<<i<<" "<<n-i-1<<endl;
}

int main()
{
	init();
	work();
	return 0;
}