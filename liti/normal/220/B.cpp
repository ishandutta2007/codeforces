/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;
#define ALL( x ) ( (x).begin() ) , ( (x).end() )

const int maxN = 100*100*10 + 10;
vector<int> a[maxN];
map<int,int> ind;
vector<pair<int,int> > good;
int main() { 
	int n;
	int m;
	scanf( "%d %d" , &n, &m ) ;
	int cnt = 0;
	for( int i = 0 ; i < n ; i++ ) { 
		int num;
		scanf( "%d" , &num ) ;

		int& p = ind[num];
		if( p == 0 ) 
			p = ++cnt;
		a[p].push_back( i ) ; 
		if( a[p].size() == num ) 
			good.push_back( { p , num } ) ;
	}

	for( int i = 0 ; i < m ; i++ ) { 
		int l, r;
		scanf( "%d%d" , &l , &r ) ; 
		int ret = 0;
		for( auto x : good ) { 
			int ind = lower_bound( ALL( a[x.first] ) , l - 1 ) - a[x.first].begin();
			if( a[x.first].size() >= ind + x.second  &&
					a[x.first][ind + x.second - 1] < r &&
					( ind + x.second == a[x.first].size() ||
					  a[x.first][ind + x.second ] >= r ) ) 
				ret++;
		}
		printf( "%d\n" , ret ) ;
	}
}