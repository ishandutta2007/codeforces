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

const int MaxN=110;

int n,m;
int a[MaxN];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	cin>>m;
	for (int i=1;i<=m;++i)
	{
		int x,y;
		cin>>x>>y;
		a[x-1]+=y-1;
		a[x+1]+=a[x]-y;
		a[x]=0;
	}
	for (int i=1;i<=n;++i)
		cout<<a[i]<<endl;
	return 0;
}