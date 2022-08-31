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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=23;

int n;
int a[MaxN],b[MaxN];
vector<pii> v[MaxN];
int u[1<<MaxN];

int main()
{
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
		b[i]=1<<i;
	}
	for (int k=1;k<n;++k)
	{
		for (int i=0;i<k;++i)
			for (int j=i;j<k;++j)
				if (a[i]+a[j]==a[k])
					v[k].push_back(pii(i,j));
		if (v[k].empty())
		{
			puts("-1");
			return 0;
		}
	}
	int ans=n;
	u[1]=1;
	int now=0;
	for (int s=1;s<(1<<n);++s)
	{
		if (!u[s]) continue;
		while ((1<<now)<=s) ++now;
		if (now==n)
		{
			int t=0;
			for (int j=0;j<n;++j)
				if (s&b[j]) ++t;
			ans=min(ans,t);
			continue;
		}
		for (vector<pii>::iterator it=v[now].begin();it!=v[now].end();++it)
		{
			int t=b[it->X]|b[it->Y];
			if ((s&t)==t)
			{
				u[s^b[now]]=1;
				for (int i=0;i<now;++i)
					if (s&b[i])
						u[s^b[now]^b[i]]=1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}