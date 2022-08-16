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
typedef pair<ll,ll> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

int n,u[2000010];
vector<int> p;

int main()
{
	for (int i=2;i<=2000000;++i)
		if (!u[i])
		{
			p.push_back(i);
			for (int j=i;j<=2000000;j+=i)
				u[j]=1;
		}
	cin>>n;
	for (int i=0;i<n;++i)
		printf("%d ",p[i]);
	return 0;
}