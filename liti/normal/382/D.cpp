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

const int maxN = 2000; 

string s[maxN]; 
int check[maxN][maxN];
pair< int, pair<int, int> > ans[maxN*1000];
int se;
pair<int, int> sP[maxN*1000];
int se2;

int size,num;

bool che( int i, int j )
{
//	cerr << i << ' ' << j << endl;
	if ( s[i-1][j] == 'v' ) 
		return false;
	if ( s[i+1][j] == '^' ) 
		return false;
	if ( s[i][j-1] == '>' ) 
		return false;
	if ( s[i][j+1] == '<' ) 
		return false;
	return true;
}

int dfs( pair<int, int> node ) 
{
	int i = node.first;
	int j = node.second;

	while ( 1 ) 
	{
		check[i][j] = num;

		node.first = i; 
		node.second = j;

		switch( s[i][j] ) 
		{
			case '>' : 
				j++;
				break;
			case '<' : 
				j--;
				break;
			case 'v' :
				i++;
				break;
			case '^' :
				i--;
				break;
		}

		if ( s[i][j] == '#' ) 
		{
			ans[se]= make_pair( size, make_pair( node.first, node.second ) )  ; 
			se++;
			return 0;
		}

		if( check[i][j] == num ) 
			return 1;

		size++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;


	for(int i = 0 ; i < n ; i++ )
		cin >> s[i];

	if ( n == 1 || m == 1 ) 
	{
		cout << 0 << endl;
		return 0 ; 
	}

	se2= 0;
	for(int i = 1; i < n - 1 ; i++ )
		for(int j = 1 ; j < m - 1 ; j++ )
		{
			if ( (s[i][j] == '>' && s[i][j+1] == '<') || ( s[i][j] == 'v' && s[i+1][j] == '^' ) )
			{
				cout << -1 << endl;
				return 0;
			}
			if ( s[i][j] != '#' && che(i,j) ) 
			{
				//				cerr << i << ' ' << j << endl;
				sP[se2] = make_pair(i,j) ;
				se2 ++;
			}	
		}

	//	cout << "HI" << endl;
	se = 0 ; 
	for(int i = 0 ; i < se2 ; i++ )
	{
		size= 1;
		num = i + 1;
		if ( dfs( sP[i] )  ) 
		{
			cout << -1 << endl;
			return 0;
		}
	}


	sort( ans, ans + se) ;
	reverse( ans, ans + se ) ; 

	int r = 0 ; 

	if ( se == 0 ) 
	{
		cout <<r << endl;
		return 0; 
	}
	if ( se == 1 ) 
	{
		cout << ans[0].first + ans[0].first - 1  << endl;
		return 0;
	}

	r += ans[0].first; 

	for(int i = 1; i < se ; i++ )
		if ( ans[i].second == ans[0].second ) 
			ans[i].first--;
	ans[0].first--;

	sort( ans, ans + se ) ; reverse( ans, ans + se ) ; 
	r += ans[0].first ; 
	cout << r << endl;
}