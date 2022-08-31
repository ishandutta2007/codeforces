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
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=1010;

int n,ans;
int a[MaxN],b[MaxN];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;++i)
	{
		int flag=0;
		for (int j=1;j<=ans;++j)
		{
			if (b[j]<=a[i])
			{
				flag=1;
				b[j]++;
				break;
			}
		}
		if (!flag)
		{
			++ans;
			b[ans]=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}