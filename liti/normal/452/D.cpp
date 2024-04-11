/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxK = 1000*10+ 10;
const int maxN = 1000 + 10;

int t[4][maxN*maxK + 3000];

int main() {
	int k;
	int tt[4];
	int n[4];
	cin >> k;
	for(int i = 0 ; i < 3 ; i++ ) 
		cin >> n[i];
	for(int i= 0 ; i < 3 ; i++ )
		cin >> tt[i];

	t[0][0] = k;
	int m = maxN*maxK + 3000;
	for(int i =0 ; i < 3; i++ ) { 
		int z = n[i];
		for(int j = 0; j < m ; j++ ) {
			z += t[i+1][j];
			int x = min( z, t[i][j] ) ; 
			z-=x;
			t[i][j+1] += t[i][j] - x;
			t[i+1][j+tt[i]] += x;
		}
	}

	for(int i = m - 1 ; i>= 0 ; i-- ) 
		if( t[3][i] ) {
			cout << i << endl;
			return 0;
		}
}