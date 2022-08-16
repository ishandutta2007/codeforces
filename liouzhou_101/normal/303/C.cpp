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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

int n,k;
int a[5010];
int w[1000010],u[1000010];

int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;++i)
		for (int j=1;j<i;++j)
			++w[a[i]-a[j]];
	for (int i=1;i<=a[n]+1;++i)
	{
		int t=0;
		for (int j=i;j<=a[n];j+=i)
			t+=w[j];
		if (t>k*(k+1)/2) continue;
		t=0;
		for (int j=1;j<=n;++j)
		{
			int x=a[j]%i;
			if (u[x]==i) ++t;
			u[x]=i;
		}
		if (t<=k)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	puts("-1");
	return 0;
}