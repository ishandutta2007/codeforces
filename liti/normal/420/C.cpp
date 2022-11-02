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
#include <cstdio>

#define SZ(x) (( (int) x.size() ))

using namespace std;

const int maxN = 3*1000*100 + 10;

int r[maxN];

int ps[maxN];
vector< pair<int, int> > a ;

int main()
{
	int n,p;
	cin >> n >> p;
	for(int i =0; i < n ;i++ ) 
	{
		int x,y;
		cin >> x >> y;
		x--;y--;
		a.push_back(make_pair(min(x,y),max(y,x)));
		r[x]++;
		r[y]++;
	}
	sort( a.begin()  , a.end() ) ; 

	long long ans = 0;
	for(int i = 0 ; i < SZ( a ) ; i++ )
	{
		int counter = 1 ; 
		while( i != SZ( a ) - 1 && a[i+1].first == a[i].first && a[i].second == a[i+1].second ) 
		{
			counter++;
			i++;
		}

		if( r[ a[i].first ] + r[ a[i].second ] >= p && r[ a[i].first ] + r[a[i].second ] - counter < p ) 
			ans--;
	}

	sort( r, r + n ) ; 

	for(int i = 0; i < n ; i++ )
	{
		int val = p - r[i];
		long long ind =  lower_bound( r, r + n , val ) - r;
	//	cout << r[i] << ' ' << ind << endl;
		if( ind <= i ) 
			ind = i + 1;
		ans += (n-ind);
	}

	cout << ans  << endl;
}