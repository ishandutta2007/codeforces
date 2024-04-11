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

const int maxN = 2 * 100*100*10 + 1000;

int aa[maxN],a[maxN], num[maxN], end[maxN];
int z[maxN],zz[maxN]; // zarib
int tmpVal[maxN*4 + 100];
vector<int> c[maxN];
int counter;

void dfs( int node, int parent, bool h ) 
{	
	if ( h == 0 )
	{

		zz[node] = 1; 
	   	z[counter] = 1;
	}
   	else
	{
		zz[node] = -1 ;
	   	z[counter] = -1  ; 
	}

	a[counter] = aa[node];
	num[node] = counter;
	counter++;

	for( int i = 0 ; i < SZ( c[node] ) ; i++ ) 
		if ( c[node][i] != parent ) 
			dfs( c[node][i], node, !h ) ; 
	end[node] = counter;
}

void update(int index ) 
{
	tmpVal[ index * 2 ] += tmpVal[index];
	tmpVal[ index * 2 + 1 ] += tmpVal[index];
	tmpVal[index] = 0; 
}

void sVal( int sn , int en , int s, int e, int index,  int val )
{
	if( sn == s && en == e ) 
	{
//	cout << sn << ' ' << en << ' ' << s  << ' ' << e << ' ' << index << ' ' << val << endl;
		tmpVal[index] += val;
		
		return;
	}

	update(index);
	int m = ( s + e ) / 2; 

	if ( sn < m ) 
		sVal( sn, min( m, en ) , s, m, index*2 , val ) ; 
	if ( en > m ) 
		sVal( max( sn, m ) , en, m, e, index*2 + 1 , val ) ; 
}

void pVal( int node, int s , int e , int index ) 
{
	if ( e - s == 1 ) 
	{
		a[node] += tmpVal[index]*z[node];
		tmpVal[index] = 0;
		cout << a[node] << endl;
		return;
	}

	update(index);

	int m = ( s + e ) / 2 ; 
	if ( node < m ) 
		pVal( node, s, m , index*2 ) ; 
	else
		pVal( node, m, e , index*2 + 1 ) ; 
}

main()
{
	memset(tmpVal, 0, sizeof tmpVal ); 
	int n,m;
	cin >> n >> m;

	for(int i = 0 ; i < n ; i++ )
		cin >> aa[i];
	for(int i = 0 ; i < n - 1; i++ )
	{
		int x,y;
		cin >> x >> y ;
		x--;y--;
		c[x].push_back(y);
		c[y].push_back(x);
	}

	counter =0 ; 
	dfs( 0, -1, 0 ) ; 


	for(int i = 0 ; i < m ; i++ )
	{
		int t, x, val;
		cin >> t;

		if ( t == 1 ) 
		{
			cin >> x >> val; 
			x--;
			sVal( num[x], end[x] , 0, n , 1 , zz[x]*val ) ; 
		}
		else
		{
			cin >> x;
			x--;
			pVal( num[x], 0, n  , 1 ) ; 
		}
	}
}