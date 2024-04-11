//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 500 + 10; 

int mat[maxN][maxN]; 
string s; 

int main() { 
	int n,m; cin >> n >> m; 
	for( int i = 0 ; i < m ; i++ ) { 
		int u,v; cin >> u >> v; 
		u--; v--; 
		mat[u][v] = mat[v][u] = 1; 
	}
	s.resize(n); 
	int last = -1; 
	for( int i = 0 ; i < n ; i++ ) { 
		int cnt = 0; 
		for( int j = 0 ; j < n ; j++ ) 
			cnt += mat[i][j]; 
		if( cnt == n - 1 ) 
			s[i] = 'b'; 
		else if( last != -1 ) { 
			if( mat[i][last] ) 
				s[i] = 'a'; 
			else
				s[i] = 'c'; 
		} else { 
			last = i; 
			s[i] = 'a'; 
		}
	}
	for( int i = 0 ; i < n ; i++ ) 
		for( int j = i + 1 ; j < n ; j++ ) 
			if( mat[i][j] != (abs( (int)s[i] - (int)s[j])<2) ) { 
				cout << "No\n"; 
				return 0; 
			}
	cout << "Yes\n" << s << endl;
}