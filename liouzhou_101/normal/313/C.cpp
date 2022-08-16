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

int n;
int a[2000010],b[2000010];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	int k=0;
	for (;1<<k<<k!=n;++k);
	for (int i=0;i<=k;++i)
		for (int j=1;j<=1<<i<<i;++j)
			b[j]=max(b[j],k-i+1);
	ll ans=0;
	for (int i=1;i<=n;++i)
		ans+=(ll)a[i]*b[i];
	cout<<ans<<endl;
	return 0;
}