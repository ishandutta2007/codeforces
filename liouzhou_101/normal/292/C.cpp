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

int n;
int a[34];

int m;
int p[34];
int u[34];

vector<string> ans;

void check(int k,int s,int x,int len)
{
	if (x>255) return;
	if (s>4) return;
	if (k==m)
	{
		if (s==4&&len>0)
		{
			string ss;
			int t=0;
			for (int i=1;i<=m;++i)
			{
				ss+=p[i]+'0';
				if (u[i]) if (++t<4) ss+='.';
			}
			ans.push_back(ss);
		}
		return;
	}
	u[k]=1;
	if (len) check(k+1,s+1,p[k+1],1);
	u[k]=0;
	if (!(len&&x==0)) check(k+1,s,x*10+p[k+1],len+1);
}

void DFS(int k,int s)
{
	--k;
	if (s==(1<<n)-1)
	{
		m=k+k-1;
		for (int i=1;i<=k;++i)
			p[m-i+1]=p[i];
		check(1,1,p[1],1);
		if (m!=k*2)
		{
			m=k*2;
			for (int i=1;i<=k;++i)
				p[m-i+1]=p[i];
			check(1,1,p[1],1);
		}
	}
	++k;
	if (k>6) return;
	for (int i=1;i<=n;++i)
	{
		p[k]=a[i];
		DFS(k+1,s|(1<<(i-1)));
	}
}

void solve()
{
	DFS(1,0);
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	if (n>=7)
		puts("0");
	else
	{
		solve();
		cout<<ans.size()<<endl;
		for (int i=0;i<ans.size();++i)
			printf("%s\n",ans[i].c_str());
	}
	return 0;
}