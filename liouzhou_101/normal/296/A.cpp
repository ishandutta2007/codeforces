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
map<int,int> F;

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int x;
		cin>>x;
		F[x]++;
	}
	for (map<int,int>::iterator it=F.begin();it!=F.end();++it)
		if (it->Y>n-n/2)
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}