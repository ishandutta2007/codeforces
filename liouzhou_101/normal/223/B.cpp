#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=1<<18;

int n,m;
char s[MaxN],t[MaxN];
vector<pair<int,int> > v[30],w[30];
int F[MaxN],G[MaxN];

void init()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
}

void work()
{
	for (int i=1,j=0;i<=n;++i)
	{
		int x=s[i]-'a';
		if (s[i]==t[j+1])
		{
			++j;
			v[x].push_back(make_pair(i,j));
		}
		if (!v[x].empty())
			F[i]=v[x].rbegin()->second;
		else
			F[i]=-MaxN;
	}
	for (int i=n,j=m+1;i>=1;--i)
	{
		int x=s[i]-'a';
		if (s[i]==t[j-1])
		{
			--j;
			w[x].push_back(make_pair(i,j));
		}
		if (!w[x].empty())
			G[i]=w[x].rbegin()->second;
		else
			G[i]=MaxN;
	}
	for (int i=1;i<=n;++i)
		if (F[i]<G[i])
		{
			puts("NO");
			return;
		}
	puts("YES");
}

int main()
{
	init();
	work();
	return 0;
}