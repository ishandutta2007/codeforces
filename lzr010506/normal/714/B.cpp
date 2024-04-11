#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n , a[100000 + 2];
map < int , int > use;
vector < int > v;

int main()
{
	cin >> n;
	for( register int i = 1 ; i <= n ; i++ )
		scanf( "%d" , &a[i] );
	sort( a + 1 , a + n + 1 );
	for( register int i = 1 ; i <= n ; i++ )
		if( !use[ a[i] ] )
			use[ a[i] ] = 1 , v.push_back( a[i] );
	if( v.size() > 3 ) puts( "NO" );
	else if( v.size() == 1 )
		puts( "YES" );
	else if( v.size() == 2 )
		puts( "YES" );
	else if( v[1] - v[0] == v[2] - v[1] )
		puts( "YES" );
	else puts( "NO" );
	return 0;
}