#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<list>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=100010;

int prime[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int state[66];
vector<int> q[1<<16];

int n;
int a[110],b[110];
int F[110][1<<16],G[110][1<<16];

void get(int n,int s)
{
	b[n]=G[n][s];
	if (n>1) get(n-1,s^state[b[n]]);
}

int main()
{
	for (int i=1;i<=60;++i)
	{
		for (int j=0;j<16;++j)
			if (i%prime[j]==0) state[i]|=1<<j;
	}
	for (int s=0;s<1<<16;++s)
		for (int j=1;j<=60;++j)
			if (!(s&state[j])) q[s].push_back(j);
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	for (int i=0;i<=n;++i)
		for (int j=0;j<1<<16;++j)
			F[i][j]=10010;
	F[0][0]=0;
	for (int i=1;i<=n;++i)
	{
		for (int s=0;s<1<<16;++s)
		{
			for (auto x : q[s])
			{
				int tmp=F[i-1][s]+abs(a[i]-x);
				if (F[i][s|state[x]]>tmp)
				{
					F[i][s|state[x]]=tmp;
					G[i][s|state[x]]=x;
				}
			}
		}
	}
	int best_s=0;
	for (int s=0;s<1<<16;++s)
		if (F[n][s]<F[n][best_s]) best_s=s;
	get(n,best_s);
	for (int i=1;i<=n;++i)
		cout<<b[i]<<" ";
	return 0;
}