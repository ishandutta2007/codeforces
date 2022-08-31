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
string s;
int sx,sy,tx,ty,px,py;
map<int,int> vx,vy;

int main()
{
	cin>>n>>sx>>sy>>tx>>ty>>s;
	tx-=sx;
	ty-=sy;
	if (tx<0)
	{
		px=-1;
		tx=-tx;
	}
	else
		px=1;
	if (ty<0)
	{
		py=-1;
		ty=-ty;
	}
	else
		py=1;
	for (int i=0;i<n;++i)
	{
		if (s[i]=='E') ++vx[1];
		if (s[i]=='S') ++vy[-1];
		if (s[i]=='W') ++vx[-1];
		if (s[i]=='N') ++vy[1];
		if (vx[px]>=tx&&vy[py]>=ty)
		{
			cout<<i+1<<endl;
			return 0;
		}
	}
	puts("-1");
	return 0;
}