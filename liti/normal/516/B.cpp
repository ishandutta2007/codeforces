/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 2000 + 10; 

string a[maxN];
int val[maxN][maxN];
int dx[4] = { 0 , 1 , 0 , -1 }; 
int dy[4] = { 1 , 0 , -1 , 0 }; 
int n,m;

bool isValid( int x , int y ) { 
	return ( x >= 0 && y >= 0 && x < n && y < m ) ; 
}

queue<pair<int,int>> que;
int main() { 
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for( int i = 0 ; i < n ; i++ )
		 cin >> a[i];

	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ ) if( a[i][j] == '.' ) {
			int &cnt = val[i][j];
			for( int k = 0 ; k < 4 ; k++ ) 
				if( isValid( i + dx[k] , j + dy[k] ) && a[i+dx[k]][j+dy[k]] == '.' ) 
					cnt++;
			if( cnt == 1 ) 
				que.push( {i,j} ) ; 
		}

	while( que.size() ) { 
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		if( val[x][y] == 0 ) 
			continue;
		for( int k = 0 ; k < 4 ; k++ ) 
			if( isValid( x + dx[k] , y + dy[k] ) && a[x+dx[k]][y+dy[k]] == '.' ) { 
				if( k == 0 )  a[x][y] = '<' , a[x][y+1] = '>' ; 
				else if( k == 1 )  a[x][y] = '^' , a[x+1][y] = 'v' ; 
				else if( k == 2 )  a[x][y] = '>' , a[x][y-1] = '<' ;  
				else  a[x][y] = 'v' , a[x-1][y] = '^' ; 
				int i = x + dx[k] , j = y + dy[k] ; 
				for( int k = 0 ; k < 4 ; k++ ) 
					if( isValid( i + dx[k] , j + dy[k] ) && a[i+dx[k]][j+dy[k]] == '.' ) {
						val[ i + dx[k] ][j + dy[k]] --; 
						if( val[ i + dx[k]][j+dy[k]] == 1 ) 
							que.push( { i + dx[k] , j + dy[k] } );
					}
			}
	}

	for( int i = 0 ; i < n ; i ++ ) 
		for( int j = 0 ; j < m ; j++ ) 
			if( a[i][j] == '.' ) { 
				cout << "Not unique" << endl;
				return 0;
			}
	for( int i = 0 ; i < n ; i++ ) 
		cout << a[i] << endl;
}