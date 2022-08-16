#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=300010;

int k;
char t[MaxN];

int n;
string s[MaxN];
vector<int> v[MaxN];

void init()
{
	cin>>n;
	for (int i=2;i<=n;++i)
	{
		int p;
		scanf("%d%s",&p,t);
		v[p].push_back(i);
		s[i]=t;
	}
	scanf("%s",t+1);
}

int p[MaxN];
int ans;

void DFS(int x,int k)
{
	for (int i=0;i<s[x].size();++i)
	{
		int j=k;
		while (j)
		{
			if (t[j+1]==s[x][i]) break;
			j=p[j];
		}
		k=j+(t[j+1]==s[x][i]);
		if (k==::k) ++ans;
	}
	for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
		DFS(*it,k);
}

void work()
{
	k=strlen(t+1);
	for (int i=2;i<=k;++i)
	{
		int j=p[i-1];
		while (j)
		{
			if (t[j+1]==t[i]) break;
			j=p[j];
		}
		p[i]=j+(t[j+1]==t[i]);
	}
	DFS(1,0);
	cout<<ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}