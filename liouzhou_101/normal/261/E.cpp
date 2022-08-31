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

int nv,v[3000010],F[3000010],ans[3000010];
int np,p[110],u[110];

void DFS(int s,int k)
{
	if (k>np)
	{
		v[++nv]=s;
		F[nv]=ans[nv]=1000000000;
		return;
	}
	while (1)
	{
		DFS(s,k+1);
		if ((ll)s*p[k]>1000000000) break;
		s*=p[k];
	}
}

int main()
{
	for (int i=2;i<=100;++i)
		if (!u[i])
		{
			p[++np]=i;
			for (int j=2;i*j<=100;++j)
				u[i*j]=1;
		}
	DFS(1,1);
	sort(v+1,v+nv+1);
	ans[1]=F[1]=0;
	for (int k=2;k<=100;++k)
	{
		int j=1;
		for (int i=1;i<=nv;++i)
		{
			ans[i]=min(ans[i],F[i]+k);
			if (j>nv) continue;
			ll t=v[i]*(ll)k;
			while (j<=nv&&v[j]<t) ++j;
			if (j>nv) continue;
			F[j]=min(F[j],F[i]+1);
		}
	}
	int L,R,p,sum=0;
	cin>>L>>R>>p;
	for (int i=1;i<=nv;++i)
		if (L<=v[i]&&v[i]<=R&&ans[i]<=p) ++sum;
	cout<<sum<<endl;
	return 0;
}