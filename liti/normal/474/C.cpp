/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

int x[4][2], y[4][2]; 
int xx[4], yy[4];
int a[4];

int ans;

int di( int i , int j ) { 
	int f = xx[i] - xx[j];
	int s = yy[i] - yy[j];
	return f*f + s*s;
}
void poo() { 
	int sum = 0;
	for( int i = 0 ; i < 4 ; i++ ) { 
		sum += a[i];
		xx[i] = x[i][0], yy[i] = y[i][0];
		for( int j = 0 ; j < a[i] ; j++ ) { 
			int tx = -x[i][1] + xx[i];
			int ty = -y[i][1] + yy[i];
			xx[i] = x[i][1] - ty;
			yy[i] = y[i][1] + tx;
		}
	}

	int aa[4] = {0,1,2,3};
	do { 
		if( di( aa[0] , aa[1] ) == di( aa[1], aa[2] ) && di( aa[1], aa[2])  == di( aa[2], aa[3] ) 
				&& di( aa[2], aa[3] ) == di( aa[3], aa[0] ) && di( aa[0] , aa[2] ) == di( aa[1] , aa[3] ) &&
				di( aa[0] , aa[2] ) != 0 && di( aa[3], aa[0] ) != 0 ) { 
			ans = min( ans, sum ) ; 
			return;
		}
	}while( next_permutation(aa, aa + 4) ) ;

}

void calc( int s ) { 
	if( s == 4 ) { 
		poo();
		return;
	}
	for( int i = 0 ; i < 4 ; i++ ) {
		a[s] = i;
		calc(s+1);
	}
}
void doJob() { 
	ans = 1000;
	for( int i =0 ; i < 4 ; i++ ) 
		for( int j = 0 ; j < 2 ; j++ ) 
			cin >> x[i][j] >> y[i][j] ;
	calc( 0 ) ; 

	if( ans == 1000 ) 
		cout << -1 << endl;
	else
		cout << ans << endl;
}
	

main() { 
	int n;
	cin >> n;

	for( int i = 0 ; i < n ; i++ ) 
		doJob(); 
}