#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <deque>

#define SZ(x) (( (int) x.size() ))

using namespace std;

const int maxN = 100*100*100 + 100;

vector<int>  c[maxN];
int p[maxN];
pair<int, int> nodeRange[maxN];
int counter;

int rangeVal[maxN*2]; //Segment tree modeled in array

int getMin(int index, int first, int last , int l, int r ) // Node Range: [first, last) , Range: [l,r)
{
	if ( l == first && r == last ) 
		return rangeVal[index];

	if ( rangeVal[index] == 1 ) 
		return 1;
	
	int middle = ( first + last ) / 2 ; // Divide to [first, middle) and [middle, last) 

	int minAns = 2;

	if ( l < middle ) 
		minAns = min( minAns, getMin( index * 2 , first, middle, l, min( middle, r ) ) ) ;	
	
	if ( r > middle ) 	  
		minAns = min( minAns, getMin( index * 2 + 1, middle, last, max( middle, l ) , r ) ) ;
	
//	cout << minAns << ' '  << first << ' ' << last << ' ' <<  l << ' ' << r << endl;
	return minAns;
}

void setVal(int index, int first, int last, int l, int r, int val ) 
{
	if ( l == first && r == last ) 
	{
		rangeVal[index] = val;
		return;
	}

	if ( rangeVal[index] == 1 && val == 1 ) 
		return;

	if ( rangeVal[index] == 1 ) 
	{
		rangeVal[index * 2] = 1;
		rangeVal[index * 2 + 1] = 1;
	}

	int middle = ( first + last ) / 2;

	if ( l < middle ) 
		setVal( index*2 , first, middle, l, min( middle, r ), val );

	if ( r > middle ) 
		setVal( index*2 + 1, middle, last, max( middle, l ), r, val ) ;
		
	rangeVal[index] = min( rangeVal[index*2], rangeVal[index*2+1] ) ; 


//	cout << rangeVal[index] << ' ' << first << ' ' << last << ' '  << l <<  ' ' << r << endl;
}

void dfs(int node, int parent)
{
	p[node] = parent;
	nodeRange[node].first = counter;
	counter++;
	
	for(int i = 0 ; i < c[node].size() ; i++ )
		if ( c[node][i] != parent ) 
			dfs( c[node][i] , node ) ; 
	nodeRange[node].second = counter;
}

int main() 
{
	int n;
	cin >> n;  
	for(int i = 0 ; i < n - 1 ; i++ )
	{
		int x,y;
		cin >> x >> y;
		x--;
		y--;
		c[x].push_back(y);
		c[y].push_back(x);
	}

	counter = 0;
	dfs( 0 , - 1 ) ; 

	int m;
	cin >> m;

	for(int i = 0 ; i < m ; i++ ) 
	{
		int oType; // Operation Type
		int node;

		cin >> oType >> node ;
		node--;

		switch( oType )
		{
			case 1:
				if ( getMin( 1, 0 , n , nodeRange[node].first, nodeRange[node].second ) == 0 &&
				  p[node] != -1 ) 
				{
					int par = p[node];
					setVal( 1, 0, n, nodeRange[par].first, nodeRange[par].first + 1, 0 ) ; 
				}
					
				setVal( 1, 0, n, nodeRange[node].first, nodeRange[node].second, 1 );
				break;
			case 2:
				setVal( 1, 0, n, nodeRange[node].first, nodeRange[node].first + 1 , 0 ) ; 
				break;
			case 3:
				cout << getMin( 1, 0, n, nodeRange[node].first, nodeRange[node].second ) << endl;
				break;
			default:
				break;
		}
	}
}