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

const int maxN = 1000*100 + 10; 

vector<int> c[maxN];
vector<int> ans;
int val[maxN], goal[maxN];

void dfs( int node, int p , int f, int s , int h ) 
{
	if( h % 2 == 0 ) 
	{
		if( !f && val[node] != goal[node] ) 
		{
			ans.push_back( node ) ; 
			f = true; 
		}
		else if ( f && val[node] == goal[node] ) 
		{
			ans.push_back( node ) ; 
			f = false;  
		}
	}
	if( h % 2 == 1 ) 
	{
		if( !s && val[node] != goal[node] ) 
		{
			ans.push_back( node ) ; 
			s = true; 
		}
		else if ( s && val[node] == goal[node] ) 
		{
			ans.push_back( node ) ; 
			s = false;  
		}
	}

	for(int i = 0 ; i < SZ( c[node] ) ; i++ ) 
		if( c[node][i] != p ) 
			dfs( c[node][i] , node, f, s, h + 1 ) ; 
}

int main()
{
	int n;
	cin >> n;
	for(int i =0 ; i < n - 1 ; i ++  ) 
	{
		int x,y;
		cin >> x >> y;
		x--;
		y--;
		c[x].push_back(y); 
		c[y].push_back(x);
	}
	for(int i =0  ; i < n ; i++ ) 
		cin >> val[i] ;
	for(int i = 0; i < n ; i++ ) 
		cin >> goal[i];

	dfs( 0, -1 , 0 , 0, 0 ) ; 
	cout << SZ( ans ) << endl;
	for(int i =0 ; i < SZ( ans ) ; i++ ) 
		cout << ans[i] + 1  << ' ' ;
	cout << endl;
}