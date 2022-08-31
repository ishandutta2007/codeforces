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

int m;
ld R,ans;
ld s[100010];

int main()
{
	cin>>m>>R;
	for (int i=1;i<=m;++i)
		s[i]=s[i-1]+2*i;
	for (int i=1;i<=m;++i)
	{
		ans+=2;
		if (i>1) ans+=sqrt(2)+2;
		if (i<m) ans+=sqrt(2)+2;
		if (i>2) ans+=s[i-2]+(i-2)*sqrt(2)*2;
		if (i<m-1) ans+=s[m-i-1]+(m-i-1)*sqrt(2)*2;
	}
	printf("%.20lf\n",ans*R/m/m);
	return 0;
}