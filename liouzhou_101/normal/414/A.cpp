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

int main()
{
	int n,k;
	cin>>n>>k;
	if (n==1)
	{
		if (k!=0)
		puts("-1");
		else
		puts("1");
		return 0;
	}
	if (k<n/2)
	{
		puts("-1");
		return 0;
	}
	int a=k-n/2+1;
	cout<<a<<" "<<a*2;
	set<int> H;
	H.insert(a);
	H.insert(a*2);
	for (int i=1,j=1;i<=n/2*2-2;i+=2,j+=2)
	{
		while (H.count(j)+H.count(j+1)) ++j;
		printf(" %d %d",j,j+1);
	}
	if (n%2) printf(" 1000000000");
	return 0;
}