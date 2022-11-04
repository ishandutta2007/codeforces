#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , x , y , z , m;
map <II,int> ma , p; 

int mi(int i , int j , int k)
{
	return min(i,min(j,k));
}

int main()
{
	int i , ma1=0 , p1 , ma2=0 , p21 , p22;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> x >> y >> z; 
		if (mi(x,y,z) > ma1)
		{
			p1 = i;
			ma1 = mi(x,y,z);
		}
		if (ma[make_pair(min(x,y),max(x,y))] > 0)
		{
			m = z+ma[make_pair(min(x,y),max(x,y))];
			if (mi(x,y,m) > ma2)
			{
				ma2 = mi(x,y,m);
				p21 = p[make_pair(min(x,y),max(x,y))];
				p22 = i;
			}
		}
		if (ma[make_pair(min(x,z),max(x,z))] > 0)
		{
			m = y+ma[make_pair(min(x,z),max(x,z))];
			if (mi(x,m,z) > ma2)
			{
				ma2 = mi(x,m,z);
				p21 = p[make_pair(min(x,z),max(x,z))];
				p22 = i;
			}
		}
		if (ma[make_pair(min(y,z),max(y,z))] > 0)
		{
			m = x+ma[make_pair(min(y,z),max(y,z))];
			if (mi(m,y,z) > ma2)
			{
				ma2 = mi(m,y,z);
				p21 = p[make_pair(min(y,z),max(y,z))];
				p22 = i;
			}
		}
		if (z > ma[make_pair(min(x,y),max(x,y))])
		{
			ma[make_pair(min(x,y),max(x,y))] = z;
			p[make_pair(min(x,y),max(x,y))] = i;
		}
		if (y > ma[make_pair(min(x,z),max(x,z))])
		{
			ma[make_pair(min(x,z),max(x,z))] = y;
			p[make_pair(min(x,z),max(x,z))] = i;
		}
		if (x > ma[make_pair(min(y,z),max(y,z))])
		{
			ma[make_pair(min(y,z),max(y,z))] = x;
			p[make_pair(min(y,z),max(y,z))] = i;
		}
	}
	if (ma1 >= ma2) cout << "1\n" << p1 << "\n";
	else cout << "2\n" << p21 << " " << p22 << "\n";
	return 0;
}