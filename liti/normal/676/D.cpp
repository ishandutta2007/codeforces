//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<int,int> pii; 

const int maxN = 1000 + 10; 
string a[maxN]; 
vector<int> c[maxN*maxN*4]; 
map<char,vector<int>> mp = { 
	{ '+' , {0,1,2,3} } , 
	{ '-' , {1,3} } , 
	{ '|' , {0,2} } , 
	{ '^' , {0} } , 
	{ '>' , {1} } , 
	{ 'v' , {2} } , 
	{ '<' , {3} } , 
	{ 'L' , {0,1,2} } , 
	{ 'R' , {0,2,3} } , 
	{ 'D' , {0,1,3} } , 
	{ 'U' , {1,2,3} } 
} ; 

int dx[] = { -1 , 0 , 1 , 0 } , 
	dy[] = { 0 , 1 , 0 , -1 } ; 

int n,m;

int gg( int i , int j , int k ) { 
	return i * m * 4 + j * 4 + k; 
}

int que[maxN*maxN*4+10],en; 
int dis[maxN*maxN*4+10]; 

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> m; 
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i]; 
	for( int i = 0 ; i < n ; i++ ) 
		for( int j = 0 ; j < m ; j++ ) 
			for( int k = 0 ; k < 4 ; k++ ) { 
				c[gg(i,j,k)].push_back(gg(i,j,(k+1)%4)); 
				int nx = i + dx[k] , ny = j + dy[k]; 
				if( min(nx,ny) < 0 || nx >= n || ny >= m ) continue; 
				auto& x = mp[a[i][j]]; 
				auto& y = mp[a[nx][ny]]; 
				int nk = (k+2)%4; 
				for( auto xx : x ) 
					for( auto yy : y ) 
						if( (k-xx+4)%4 == (nk-yy+4)%4 ) { 
							int t= (k-xx+4)%4; 
							c[gg(i,j,t)].push_back(gg(nx,ny,t)); 
						}
			} 
	int sx,sy,tx,ty; 
	cin >> sx >> sy >> tx >> ty; 
	sx--; sy--; tx--; ty--; 
	int dest = gg(tx,ty,0)/4; 
	memset( dis , -1 , sizeof dis ) ; 

	que[en++] = gg(sx,sy,0); 
	dis[gg(sx,sy,0)] = 0; 
	
	for( int i = 0 ; i < en ; i++ ) { 
		int s = que[i]; 
//		cerr << dis[s] << "  " << s/m/4+1 << ' ' << s/4%m +1 << ' ' <<  s % 4 << endl;
		if( s/4 == dest ) { 
			cout << dis[s] << endl;
			return 0; 
		}
		for( auto x : c[s] ) if( dis[x] == -1 ) { 
			dis[x] = dis[s] + 1; 
			que[en++] = x; 
		}
	}
	cout << -1 << endl;
}