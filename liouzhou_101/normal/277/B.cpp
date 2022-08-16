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
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

pii rec[210];

int n,m;
int main()
{
	cin>>n>>m;
	if(m==3) 
	{
		if(n==3)
		{
			puts("0 0\n10 0\n0 10");
		}
		else
		if(n==4)
		{
			puts("0 0\n10 0\n0 10\n1 1");
		} else 
			puts("-1");
		return 0;
	}
	int x=0,y=0;
	for(int i=0;i<m;i++) 
		rec[i]=pii(x,y), x+=100000, y+=(i+1)*100;
	for(int i=m;i<n;i++) 
	{
		rec[i]=pii(rec[i-m].X+1,rec[i-m].Y);
		if(i==m) rec[i]=pii(-100000,-101);
		if(i-m==m-1) rec[i]=pii(100000000,rec[i-m].Y+1);
	}
	for(int i=0;i<n;i++)
		printf("%d %d\n",rec[i].X,rec[i].Y);
	return 0;
}