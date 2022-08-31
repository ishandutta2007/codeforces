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
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

int F[]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};

int main()
{
	int n;
	cin>>n;
	int s=1;
	set<int> H;
	int m=sqrt(n),k=0;
	for (int i=2;i<=m;++i)
	{
		if (H.count(i)) continue;
		int x=0,t=i;
		while (1)
		{
			++x;
			H.insert(t);
			if (t>m) ++k;
			if ((ll)t*i>n) break;
			t*=i;
		}
		s^=F[x];
	}
	if ((n-m-k)%2) s^=1;
	puts(s?"Vasya":"Petya");
	return 0;
}