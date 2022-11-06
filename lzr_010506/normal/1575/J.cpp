#include <bits/stdc++.h>

const int MAX_N = 1e3 + 10 , dx[3] = {0 , 1 , 0} , dy[3] = {1 , 0 , -1} ;

struct data {
	int x , y ;
}f[MAX_N][MAX_N] ;

int n , m , q , mp[MAX_N][MAX_N] ;

void merge(int x , int y) {
	mp[x][y] = 1 ;
	f[x][y] = (data){x + 1 , y} ;
}

data findroot(int x , int y) {
	data nw = f[x][y] ;
	if (nw.x == -1) return (data){x , y} ;
	else return (f[x][y] = findroot(nw.x , nw.y)) ;
}

int main() {
	scanf("%d %d %d" , &n , &m , &q) ;
	for (int i = 1 ; i <= n + 1 ; ++i)
		for (int j = 1 ; j <= m ; ++j) f[i][j] = (data){-1 , -1} ;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= m ; ++j) {
			scanf("%d" , &mp[i][j]) ; --mp[i][j] ;

			if (mp[i][j] == 1) merge(i , j) ;
		}

	///

	for (; q-- ;) {
		int x = 1 , y ; scanf("%d" , &y) ;

		for (; x <= n ;) {
			data nw = findroot(x , y) ;
			x = nw.x ; y = nw.y ;

			if (x <= n) {
				int tx = x + dx[mp[x][y]] , ty = y + dy[mp[x][y]] ;
				merge(x , y) ; x = tx ; y = ty ;
			}
		}

		printf("%d " , y) ;
	}

	return 0 ;
}