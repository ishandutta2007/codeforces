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

const int maxN = 100*100*100 + 10; 

vector<int>  c[maxN];
int dp[maxN],d[maxN];
int isSet[maxN];

int basicDfs( int node, int parent ) 
{
	int maxVal = -1;
	if ( isSet[node] )
		maxVal = 0;
	for(int i = 0 ; i < c[node].size() ; i++ )
	{
		if ( c[node][i] == parent ) 
			continue;
		int val = basicDfs( c[node][i], node ); 
		if ( val != -1 ) 
			maxVal = max( maxVal, val + 1 ) ; 
	}

	dp[node] = maxVal;
	return maxVal;
}	

void finalDfs( int node, int parent ) 
{
	int max1 = -1, max2 = -1;

	d[node] = max( d[node], isSet[node] - 1 ) ;
	for(int i = 0 ; i < c[node].size() ; i++ )
	{
		if ( c[node][i] == parent ) 
			continue;
		int newNode = c[node][i];
		if ( dp[newNode] >= max1 ) 
		{
			max2 = max1; 
			max1 = dp[newNode];
		}
		else if ( dp[newNode] > max2 ) 
			max2 = dp[newNode];
	}

//	cout << node + 1 << ' ' << d[node]<< ' ' << max1 << ' ' << max2 << endl;
	for(int i = 0 ; i < c[node].size() ; i++ )
	{
		if ( c[node][i] == parent ) 
			continue;
		int newNode = c[node][i];

		if ( d[node] != -1 ) 
			d[newNode] = d[node] + 1;
		if ( dp[newNode] == max1 )
		{   
			if ( max2 != -1 ) 	
				d[newNode] = max( d[newNode] , max2 + 2 ); 
		}
		else
			if ( max1 != -1 ) 
				d[newNode] = max( d[newNode] ,max1 + 2 ); 
		finalDfs( newNode, node ) ; 
	}

}


int main() 
{
	memset( d, -1, sizeof d ) ;
	int n,m,x;
	cin >> n >> m >> x; 

	for(int i = 0 ; i < m ;i++ )
	{
		int num; 
		cin >> num; 
		num--;
		isSet[num] = 1; 
	}

	for(int i = 0  ; i  < n - 1 ;i ++ ) 
	{
		int x,y;
		cin >> x >> y;
		x--;
		y--;
		c[x].push_back(y);
		c[y].push_back(x);
	}

	basicDfs( 0, -1 ) ; 
	
	d[0] = isSet[0] -1;

	finalDfs( 0, -1 ) ; 

	int counter =0 ; 
	for(int i = 0 ; i < n; i++ )
	{
//		cout << i + 1 << ' ' <<  max( d[i] , dp[i] )  << endl;
		if ( max( d[i], dp[i])  <= x ) 
			counter++;
	}
	cout << counter << endl;
}