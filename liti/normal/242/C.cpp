//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

map<pair<int,int>,int> mp; 

const int maxN = 100*1000 + 10; 

vector<pair<int,int>> que;
int dist[maxN];
int main() { 
	int x0,y0,x1,y1;
	cin >> x0 >> y0 >> x1 >> y1; 
	int n; 
	cin >> n; 

	int cnt = 1; 
	for( int i = 0 ; i < n ; i++ ) { 
		int r , a , b; 
		cin >> r >> a >> b; 
		for( int j = a ; j <= b ; j++ ) 
			mp[ make_pair( r , j ) ] = cnt++; 
	}
	memset( dist , -1 , sizeof dist ) ; 
	dist[mp[make_pair(x0,y0)]] = 0;
	que.push_back( { x0 , y0 } ) ; 
	for( int i = 0 ;i < __sz(que) ; i++ ) { 
		auto x = que[i];
		for( int dx = -1 ; dx < 2 ; dx++ ) 
			for( int dy = -1 ; dy < 2 ; dy++ ) { 
				int nx = x.first + dx; 
				int ny = x.second + dy; 
				if( mp.count( { nx , ny} ) && 
						dist[mp[make_pair(nx,ny)]] == -1 ) { 
					dist[mp[make_pair(nx,ny)]] = dist[mp[x]] + 1; 
					que.push_back( {nx,ny} ) ; 
				}
			}
	}
	cout << dist[mp[make_pair(x1,y1)]] << endl;
}