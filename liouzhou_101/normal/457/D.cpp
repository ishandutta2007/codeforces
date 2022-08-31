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
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=100010;

ld a[MaxN],b[MaxN];

ld C(int n,int m)
{
	if (n<0||m<0||n<m) return -1e100;
	return b[n]-b[m]-b[n-m];
}

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=1;i<=m;++i)
	{
		a[i]=log(i);
		b[i]=b[i-1]+a[i];
	}
	ld ans=0;
	for (int i=0;i<=n;++i)
		for (int j=0;j<=n;++j)
		{
			ans+=exp(C(m-n*(i+j)+i*j,k-n*(i+j)+i*j)+C(n,i)+C(n,j)-C(m,k));
			if (ans>1e99)
			{
				puts("1e99");
				return 0;
			}
		}
	printf("%.20f\n",(double)ans);
	return 0;
}