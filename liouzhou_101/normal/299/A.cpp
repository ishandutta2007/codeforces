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

int n;
int a[100010];

int main()
{
	cin>>n;
	for (int i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n);
	for (int i=1;i<n;++i)
		if (a[i]%a[0])
		{
			puts("-1");
			return 0;
		}
	cout<<a[0]<<endl;
	return 0;
}