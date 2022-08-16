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

const int MaxN=1010;

int n;
int t[MaxN],c[MaxN];
int have,most;

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>t[i]>>c[i];
	for (int i=1;i<=n;++i)
	{
		if (have<=t[i]-t[i-1])
		{
			have=c[i];
		}
		else
		{
			have=have-(t[i]-t[i-1])+c[i];
		}
		most=max(most,have);
	}
	cout<<t[n]+have<<" "<<most<<endl;
	return 0;
}