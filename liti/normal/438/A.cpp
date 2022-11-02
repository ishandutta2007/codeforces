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

const int maxN = 1000 + 10; 
int c[maxN][maxN];
pair<int, int>  val[maxN];

int main()
{
	int n,m;
	cin >> n >> m;

	for(int i = 0 ; i < n ; i++ ) 
	{
		cin >> val[i].first ;
		val[i].second = i; 
	}

	for(int i = 0 ; i < m ; i++ ) 
	{
		int x,y;
		cin >> x >> y ; x--; y--;
		c[x][y] = 1; 
		c[y][x] = 1; 
	}

	sort( val, val + n ) ; 
	reverse( val, val + n ) ; 

	long long ans =0 ; 
	for(int i = 0 ; i < n ; i++ )
		for(int j = 0 ; j  < n ; j++ ) 
			if( c[val[i].second ][val[j].second] ) 
				ans += val[j].first , c[val[i].second][val[j].second ] = 0, c[val[j].second][val[i].second ] = 0 ; 
	cout << ans << endl;
}