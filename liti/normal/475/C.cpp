/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000 + 10;
const int INF = maxN*maxN;
string a[maxN], b[maxN];
bool check[maxN][maxN];

int doJob( string* a, int n, int m ) {
	memset( check , 0 , sizeof check ) ;
	bool flg = 0;

	int x = 0 , y = 0;
	int h = 0;
	int w = 1;
	vector<bool> move;
	int s = 0,e =0;
	for( int i = 0 ; i < n ; i++ ) {
		for( int j = 0 ; j < m; j++ ) 
			if( a[i][j] == 'X' ) { 
				if( flg == 2 ) 
					return INF;
				flg = true;
				h++; 
				x = i;
				y = j;
			} else if ( flg == 1 && a[i][j] == '.' ) 
				flg = 2;
		if( flg != 0 ) { 
//			cout << "H " << h << endl;
//			for( int j = 0 ; j < n ; j++ ) 
//				cout << a[j] << endl;
			s = x, e = y;
			while(1) { 
	//			cerr << x << ' ' << y << ' ' << w << endl;
				if( x != n - 1 && y != m - 1 && a[x+1][y-h+1] == 'X' && a[x-w+1][y+1] == 'X' ) {
					w++;
					x++;
				}  else if ( y != m - 1 && a[x-w+1][y+1] == 'X' ) {
					y++;
					move.push_back(1);
				} else if ( x != n - 1 && a[x+1][y-h+1] == 'X' ) {
					x++;
					move.push_back(0);
				} else 
					break;
			}
			break;
		}
	}


	s = s + w - 1;
	for( int i = 0 ; i < w ; i++ ) 
		for( int j= 0 ; j < h ; j++ ) 
			check[s - i][e-j] = 1;
	for( int i = 0 ; i < (int)move.size() ; i++ ) { 
		if( move[i] ) { 
			e++;
			for( int j = 0 ; j < w ; j++ ) 
				check[s-j][e] = 1;
		} else { 
			s++ ;
			for( int j = 0 ; j < h ; j++ ) 
				check[s][e-j] = 1;
		}
	}
//	for( int i = 0 ; i < n ; i++ ) {
//		for( int j = 0 ; j < m ; j++ ) 
//			cout << check[i][j] ;
//		cout << endl;
//	}
	for( int i =0 ; i < n ; i++ ) 
		for( int j = 0 ; j < m ; j++ ) { 
			bool p = (a[i][j] == 'X' ? 1 : 0 ) ;
			if( check[i][j] != p ) 
				return INF;
		}
//	cerr << h << ' ' << w << endl;
	return h*w;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;

	for( int i = 0 ; i < n ;i++ ) 
		cin >> a[i];

	for( int i = 0 ; i < m ; i++ ) 
		for(int j = 0 ; j < n ; j++ ) 
			b[i] += a[j][i];
	int ans = min( doJob(a,n,m) , doJob(b,m,n) ) ; 
	cout << (ans == INF?-1:ans) << endl;
}