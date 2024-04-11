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

const int maxN = 1000*100 + 100; 

pair<int,int> v[maxN];
vector<int> c[maxN];

int par[maxN], sz[maxN];
int enable[maxN];

int check[maxN]; 

void dunion( int a, int b ) 
{
	if( sz[a] > sz[b] ) 
		swap(a,b);	
	par[a] = b; 
	sz[b] += sz[a];
}

int dfind( int a ) 
{
	return ( par[a] == -1 ? a : par[a] = dfind( par[a] ) ) ; 
}

int main()
{
	memset( par, -1, sizeof par ) ; 

	long long n,m;
	cin >> n >> m;

	for(int i = 0 ; i < n ; i++ ) 
		cin >> v[i].first  , v[i].second = i , sz[i] = 1; 

	int x,y;
	for(int i = 0 ; i < m ; i++ )
	{
		cin >> x >> y; x--; y--; 
		c[x].push_back(y);
		c[y].push_back(x);
	}

	sort( v, v + n ) ; 
	reverse( v, v + n ) ; 

	long long ans =0 ; 
	for(int i = 0 ; i < n ; i++ ) 
	{
		long long tmp = 1 ; 
		for(int k = 0 ; k < SZ( c[v[i].second ] ) ; k++ ) 
		{
			int j = c[v[i].second][k];
			if( !enable[j] ) 
				continue;
			if( check[ dfind(j) ] != i + 1 ) 
			{
		//		cout << "DALL" << endl;
				check[ dfind(j) ] = i + 1; 
				ans += v[i].first * tmp * sz[ dfind(j) ]  ; 
//				cout << v[i].first << ' ' << tmp << ' ' << sz[ dfind(j) ] << endl;
				tmp += sz[ dfind(j) ] ; 
				dunion( dfind( v[i].second ) ,  dfind(j) ) ; 
			}
		}
		enable[ v[i].second ] = 1;
//		cout << tmp << endl;
	}

	cout << fixed << setprecision(6) << 2*ans/ (long double)( n*(n-1) )  << endl;
}