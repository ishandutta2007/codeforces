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

int main()
{
	int n;
	cin>>n;
	int x=0;
	for (int i=1;i<=n;++i)
		for (int j=i;j<=n;++j)
		{
			int t=i*i+j*j;
			int p=sqrt(t);
			if (p<=n) if (p*p==t) ++x;
		}
	cout<<x<<endl;
	return 0;
}