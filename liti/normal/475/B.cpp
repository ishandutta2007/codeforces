/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 20 + 3;
const int maxK = maxN * maxN ; 

bool check[maxN][maxN];
int dx[maxN], dy[maxN];

int n,m;
bool doJob() { 
	for( int i = 0 ; i < n ; i++ ) 
		for( int j = 0 ; j < m; j++ ) 
			if( check[i][j] == false ) {
		//		cerr << i << ' ' << j << endl;
				return false;
			}
	return true;
}

void dfs( pair<int,int> s ) { 
	int x = s.first , y = s.second;
//	cerr  << "B "<< x << ' ' << y << endl;
	check[x][y] = true;

	if( dx[y] == -1 && x != 0 && !check[x-1][y] ) 
		dfs( {x-1,y} ) ;
	if( dx[y] == 1 && x != n - 1  && !check[x+1][y] ) 
		dfs( {x+1,y} ) ;
	if( dy[x] == -1 && y != 0 && !check[x][y-1] ) 
		dfs( {x,y-1} ) ;
	if( dy[x] == 1 && y != m - 1 && !check[x][y+1] ) 
		dfs( {x,y+1} ) ;
}

int main() { 
	cin >> n >> m;

	string s;
	cin >> s;
	for( int i = 0 ; i < n ; i++ )
		if( s[i] == '>' ) 
			dy[i] = 1; 
		else
			dy[i] = -1;
	cin >> s;
	for( int i = 0 ; i < m ; i++ )
		if( s[i] == 'v' ) 
			dx[i] = 1; 
		else
			dx[i] = -1;

	for( int i = 0 ; i < n ; i++ ) 
		for( int j = 0 ; j < m ; j++ ) {
			memset( check , 0 , sizeof check ) ; 
		//	cerr << i << ' ' << j << endl;
			dfs( {i,j} ) ; 
			if( !doJob() ) {
				cout << "NO" << endl;
				return 0;
			}
		}
	cout << "YES" << endl;
}