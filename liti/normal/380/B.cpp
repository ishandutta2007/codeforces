#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <iomanip>
#include <string>
#include <stack>
#include <cstring>

#define SZ(x) (( (int) x.size() ))

using namespace std;

const int maxN = 7000 + 100;

vector< pair< int, pair<int, int> > > a[maxN];
int le[maxN];
vector<int> e[1000000 + 100];

vector<int> v;
int d[1000000 + 123];

int n,m;

void rec( int l, int r, int level ) 
{
//	cout << l << ' ' << r << ' ' << level << endl;
	if ( level > n ) 
		return;
	for(int i = 0 ; i < SZ( a[level] ) ;i++ )
	{
		if ( a[level][i].second.first > r || a[level][i].second.second < l ) 
			continue;
		int val = a[level][i].first;
	//	cout<<  i << ' ' << val << endl;
		if ( d[ val ] >= SZ(v) || val != v[ d[val] ] )
		{
			d[val] = SZ(v);
			v.push_back(val);
		}
	}
	rec( e[l][0] , e[r][ max( SZ(e[r])  - 1 , 0 ) ], level + 1  ) ; 
}

void pA()
{
	v.clear();
	int x;
	int level ; 
	cin >> level >>  x; 
	rec( x,x, level ) ; 

	cout << v.size() << endl;
}

inline void calc()
{
	int q;
	cin >> q;
	if ( q == 2 ) 
		pA();
	else
	{
		int t,l,r,x;
		cin >> t >> l >> r >> x;
		a[t].push_back( make_pair(x, make_pair(l,r) ) ) ; 
	}
}

void cG()
{
	int num = 0 ; 
	int z = 1; 
	for(int j = 1; j<= 1000000 + 100 ;j++ )
	{
		if ( j == z )
		{
			z*= 2;
			e[j].push_back(num+1);
			e[j].push_back(num+2);
			num+= 2;
		}
		else
		{
			e[j].push_back(num+1);
			num++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m ;
	cG();
	for(int i =0 ; i < m ;i++ )
		calc();
}