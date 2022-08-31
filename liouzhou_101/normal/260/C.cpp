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

typedef long long int64;
typedef long double real;
typedef pair<int,int> pii;

#define X first
#define Y second

const int MaxN=100010;
const int INF=2000000000;

int n,x;
int64 a[MaxN];

int main()
{
	cin>>n>>x;
	for (int i=1;i<=n;++i)
		scanf("%I64d",&a[i]);
	int p=x;
	int get=INF,way;
	while (1)
	{
		--p;
		if (!p) p=n;
		if (a[p]<get)
		{
			get=a[p];
			way=p;
		}
		if (p==x) break;
	}
	int64 v=(int64)get*n;
	for (int i=1;i<=n;++i)
		a[i]-=get;
	for (int i=x;;)
	{
		if (!a[i])
		{
			a[i]=v;
			break;
		}
		--a[i];
		++v;
		--i;
		if (i<1) i+=n;
	}
	for (int i=1;i<=n;++i)
		printf("%I64d ",a[i]);
	return 0;
}