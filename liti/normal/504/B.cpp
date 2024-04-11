/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 200*100*10 + 10; 

int a[maxN];
int fen[maxN];
void add( int x ) { 
	for( ; x < maxN ; x += x & (-x) )
		fen[x]++;
}
int get( int x ) { 
	int ret = 0;
	for( ; x ; x -= x & (-x) ) 
		ret += fen[x];
	return ret;
}

int main() { 
	int n;
	cin >> n;

	for( int t = 0 ; t < 2 ; t++ ) {
		memset(fen, 0, sizeof fen);
		for( int i= 0 ; i < n ; i++ ) {
			int num; cin >> num;
			a[i] += num - get( num + 1 ) ; 
			add( num + 1 ) ; 
		}
	}
	int tmp = 0;
	for( int i = n - 2 ; i >= 0 ; i-- ) {
		a[i] += tmp; tmp =0;
		if( a[i] >= n - i ) { 
			a[i] -= n - i;
			tmp = 1;
		}
	}
	memset( fen , 0 , sizeof fen ) ; 
	for( int i = 0 ; i < n ; i++ ) { 
		int s = -1 , e = n - 1 ; 
		while( e - s > 1 ) { 
			int m = ( s + e ) / 2; 
			int x = m - get( m + 1 ) ; 
			if( x < a[i] ) 
				s = m;
			else 
				e = m;
		}
		add( e + 1 ) ; 
		cout << e << ' ' ;
	}
	cout << endl;
}