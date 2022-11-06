#include <bits/stdc++.h>

const int MAX_N = 500 + 10 , INF = 0x3f3f3f3f ;

char a[MAX_N] , b[MAX_N] ;
int n , m , t , nxt[MAX_N] , g[MAX_N][2] , f[MAX_N][MAX_N][MAX_N] ;

int main() {
	scanf("%d %d" , &n , &m) ;
	scanf("%s %s" , a + 1 , b + 1) ;
	b[m + 1] = '2' ;

	///

	int p ; p = nxt[1] = 0 ;
	for (int i = 2 ; i <= m ; ++i) {
		for (; p && b[p + 1] != b[i] ; p = nxt[p]) ;
		if (b[p + 1] == b[i]) ++p ;

		nxt[i] = p ;
	}

	for (int i = 0 ; i <= m ; ++i) {
		char c ; int p ;

		//add 0
		if (c == '0') g[i][0] = i + 1 ;
		else {
			p = i ;
			for (; p && b[p + 1] != '0' ; p = nxt[p]) ;
			if (b[p + 1] == '0') ++p ;

			g[i][0] = p ;
		}

		//add 1
		if (c == '1') g[i][1] = i + 1 ;
		else {
			p = i ;
			for (; p && b[p + 1] != '1' ; p = nxt[p]) ;
			if (b[p + 1] == '1') ++p ;

			g[i][1] = p ;
		}
	}

	///

	t = n - m + 1 ;
	for (int i = 0 ; i <= n ; ++i)
		for (int j = 0 ; j <= t ; ++j)
			for (int k = 0 ; k <= m ; ++k) f[i][j][k] = INF ;

	f[0][0][0] = 0 ;
	for (int i = 0 ; i < n ; ++i)
		for (int j = 0 ; j <= t ; ++j)
			for (int k = 0 ; k <= m ; ++k) {
				if (i == 8 && j == 3 && k == 3)
					i = i ;

				int nxt = a[i + 1] - '0' , res , nj , nk ;

				//add 0
				res = f[i][j][k] + (nxt ^ 0) ;
				nk = g[k][0] ; nj = j + (nk == m) ;
				f[i + 1][nj][nk] = std::min(f[i + 1][nj][nk] , res) ;

				//add 1
				res = f[i][j][k] + (nxt ^ 1) ;
				nk = g[k][1] ; nj = j + (nk == m) ;
				f[i + 1][nj][nk] = std::min(f[i + 1][nj][nk] , res) ;
			}

	for (int i = 0 ; i <= t ; ++i) {
		int res = f[n][i][0] ;
		for (int j = 0 ; j <= m ; ++j) res = std::min(res , f[n][i][j]) ;

		if (res == INF) printf("-1 ") ;
		else printf("%d " , res) ;
	}
	printf("\n") ;

	return 0 ;
}