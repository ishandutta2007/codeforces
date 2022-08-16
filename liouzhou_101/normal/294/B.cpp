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

const int MaxN=210;

int n,st;
int t[MaxN],w[MaxN];
int F[MaxN][MaxN][MaxN];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		cin>>t[i]>>w[i];
		st+=t[i];
	}
	F[0][0][st]=1;
	for (int i=0;i<n;++i)
		for (int j=0;j<=st;++j)
			for (int k=0;k<=st;++k)
			{
				if (!F[i][j][k]) continue;
				F[i+1][j][k]=1;
				if (j+w[i+1]<=st&&k-t[i+1]>=0&&j+w[i+1]<=k-t[i+1]) F[i+1][j+w[i+1]][k-t[i+1]]=1;
			}
	int ans=st;
	for (int j=0;j<=st;++j)
		for (int k=0;k<=st;++k)
			if (F[n][j][k]) ans=min(ans,k);
	cout<<ans<<endl;
	return 0;
}