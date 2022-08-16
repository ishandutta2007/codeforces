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

int main()
{
	int n,m;
	cin>>n>>m;
	cout<<min(n,m)+1<<endl;
	for (int i=0;i<=min(n,m);++i)
	{
		cout<<i<<" "<<m-i<<endl;
	}
	return 0;
}