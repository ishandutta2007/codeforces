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
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=3010;
const ll INF=1000000000000000000LL;

int n,m;
int p[MaxN];
int F[MaxN*MaxN];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>p[i];
	for (int i=1;i<=n;++i)
		for (int j=i+1;j<=n;++j)
			if (p[i]>p[j]) ++m;
	F[0]=0;
	F[1]=1;
	for (int i=2;i<=m;++i)
		F[i]=F[i-2]+4;
	cout<<F[m]<<endl;
	return 0;
}