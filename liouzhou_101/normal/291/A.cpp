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

int n;
map<int,int> F;

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int x;
		cin>>x;
		if (x) F[x]++;
	}
	int ans=0;
	for (map<int,int>::iterator it=F.begin();it!=F.end();++it)
		if (it->X)
		{
			if (it->Y==2)
				++ans;
			else if (it->Y>=3)
			{
				puts("-1");
				return 0;
			}
		}
	cout<<ans<<endl;
	return 0;
}