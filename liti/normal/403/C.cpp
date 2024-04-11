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

const int maxN = 2000 + 100; 

vector<int> e[maxN] , eRev[maxN]; //Each vertex neighbours
int topol[maxN]; // Vertices in topological order
int topCheck[ maxN ] ; 

int check[maxN]; // Checks for SCC 

int n,ind;

void topSort( int node ) 
{
	topCheck[node] = 1; 
	for(int i = 0 ; i < SZ( eRev[node] ) ; i++) 
		if ( !topCheck[ eRev[node][i] ] ) 
			topSort( eRev[node][i] ) ;

	ind--; 
	topol[ind] = node;
}

void dfs( int node ) 
{
	check[node] = 1; 
	
	for( int i = 0 ; i < SZ( e[node] ) ; i++ ) 
		if ( !check[ e[node][i] ] ) 
			dfs( e[node][i] ) ; 
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	ind = n;

	for(int i = 0 ; i < n ; i++ )
	{
		for(int j = 0 ; j < n ;j++ )
		{
			int tmp;
			cin >> tmp;
			if ( tmp > 0 ) 
			{
				e[i].push_back(j);
				eRev[j].push_back(i);
			}
		}
	}

	for(int i = 0 ; i < n; i++ )
		if ( !topCheck[i] ) 
			topSort( i ) ; 

	int counter =0;
	for(int i = 0 ; i < n ;i++ )
		if ( !check[topol[i]] ) 
		{
			counter++;
			dfs( topol[i]) ; 
		}

	if( counter == 1 ) 
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}