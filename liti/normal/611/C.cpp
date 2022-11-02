//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
#define SZ(x) ((int) (x).size())

const int maxN = 500 + 10; 
string s[maxN];
int a[maxN][maxN];
int psum[maxN][maxN]; 

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	int n,m; cin >> n >> m; 
	for( int i = 0 ; i < n ; i++ ) { 
		cin >> s[i];
		for( int j = 0 ; j < m ; j++ ) { 
			if( s[i][j] == '.' ) { 
				if( i && s[i-1][j] == '.' ) 
					a[i][j]++; 
				if( j && s[i][j-1] == '.' ) 
					a[i][j]++; 
			}
			psum[i+1][j+1] = psum[i][j+1] + psum[i+1][j] - psum[i][j] + a[i][j]; 
		}
	}
	int q; cin >> q; 
	for( int t = 0 ; t < q ; t++ ) { 
		int i1 , j1 , i2 , j2; 
		cin >> i1 >> j1 >> i2 >> j2; 
		i1--; j1--;
		int ans = psum[i2][j2] - psum[i2][j1] - psum[i1][j2] + psum[i1][j1]; 
		if( j1 ) { 
			for( int i = i1 ; i < i2 ; i++ )
				if( s[i][j1] == '.' && s[i][j1-1] == '.' ) 
					ans--; 
		}
		if( i1 ) { 
			for( int j = j1 ; j < j2 ; j++ ) 
				if( s[i1][j] == '.' && s[i1-1][j] == '.' ) 
					ans--; 
		}
		cout << ans << '\n'; 
	}
}