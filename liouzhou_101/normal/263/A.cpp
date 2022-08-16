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
	for (int i=1;i<=5;++i)
		for (int j=1;j<=5;++j)
		{
			int x;
			cin>>x;
			if (x)
			{
				cout<<abs(i-3)+abs(j-3)<<endl;
				return 0;
			}
		}
	return 0;
}