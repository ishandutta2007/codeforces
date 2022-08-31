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

const int MaxN=100010;

int n;
int a[MaxN];
int ans;
int head,tail,Q[MaxN];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	Q[head=tail=1]=a[1];
	for (int i=2;i<=n;++i)
	{
		while (head<=tail&&Q[tail]<a[i])
		{
			ans=max(ans,a[i]^Q[tail]);
			--tail;
		}
		Q[++tail]=a[i];
	}
	Q[head=tail=1]=a[n];
	for (int i=n-1;i>=1;--i)
	{
		while (head<=tail&&Q[tail]<a[i])
		{
			ans=max(ans,a[i]^Q[tail]);
			--tail;
		}
		Q[++tail]=a[i];
	}
	cout<<ans<<endl;
	return 0;
}