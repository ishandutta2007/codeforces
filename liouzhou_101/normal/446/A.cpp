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
#include<list>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>
#include<unordered_set>
#include<unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=100010;

int n;
int a[MaxN];
int F[MaxN];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=n;i>=1;--i)
	{
		if (a[i+1]>a[i]) F[i]=F[i+1]+1;
		else F[i]=1;
	}
	int ans=0;
	for (int i=1;i<=n;++i)
	{
		ans=max(ans,F[i]);
		int x=a[i+F[i]-1]+1;
		if (i+F[i]<=n) ans=max(ans,F[i]+1);
		if (i+F[i]+1<=n) if (a[i+F[i]+1]>x) ans=max(ans,F[i]+1+F[i+F[i]+1]);
	}
	cout<<ans<<endl;
	return 0;
}