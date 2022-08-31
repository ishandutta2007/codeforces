#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
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

const int MaxN=5010;

int u[MaxN],sg[MaxN];

int main()
{
	for (int i=1;i<MaxN;++i)
	{
		for (int j=1;j<=i;++j)
		{
			int x=max(j-2,0);
			int y=max(i-j-1,0);
			u[sg[x]^sg[y]]=1;
		}
		for (sg[i]=0;u[sg[i]];++sg[i]);
		memset(u,0,sizeof(u));
	}
	string s;
	cin>>s;
	int t=0;
	vector<pii> v;
	for (int i=1;i<s.size()-1;++i)
	{
		if (u[i]) continue;
		int j=i;
		while (s[j-1]==s[j+1])
		{
			++j;
			u[j]=1;
			if (j==s.size()-1) break;
		}
		v.push_back(pii(i,j-i));
		t^=sg[j-i];
	}
	if (!t)
	{
		puts("Second");
		return 0;
	}
	puts("First");
	for (int i=0;i<v.size();++i)
	{
		for (int j=1;j<=v[i].Y;++j)
		{
			if (!(t^sg[v[i].Y]^sg[max(j-2,0)]^sg[max(v[i].Y-j-1,0)]))
			{
				cout<<v[i].X+j<<endl;
				return 0;
			}
		}
	}
	return 0;
}