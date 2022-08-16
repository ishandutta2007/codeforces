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

const int MaxN=100010;

int n,k;
int a[MaxN];

int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	if (n<k)
	{
		puts("-1");
	}
	else
	{
		cout<<a[n-k+1]<<" "<<a[n-k+1]<<endl;
	}
	return 0;
}