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

const int MaxN=2010;

int ans,n;
int a[MaxN];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i];
		a[i]=(a[i]>=0)?a[i]:-a[i];
	}
	for (int i=1;i<=n;++i)
	{
		int x=0;
		for (int j=1;j<i;++j) x+=a[j]<a[i];
		int y=0;
		for (int j=i+1;j<=n;++j) y+=a[j]<a[i];
		ans+=min(x,y);
	}
	cout<<ans<<endl;
	return 0;
}