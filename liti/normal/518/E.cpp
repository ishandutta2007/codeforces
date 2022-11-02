/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 3000*100 + 10; 
int mark[maxN];
int a[maxN];
int n,k;

void doJob( int i , int j , int mn , int mx ) { 
//	cout << i << ' ' << j << ' ' << mn << ' ' << mx << endl;
	int cnt = ( j - i  ) / k ;
	if( mx - mn - 1 <  cnt ) { 
		cout << "Incorrect sequence" << endl;
		exit(0);
	}
	if( mn >=  - ( cnt / 2 ) - 1 ) { 
		int val = mn + 1;
		for( int x = i ; x != j ; x += k ) 
			a[x] = val++;
	} else if( mx <=  (cnt / 2) + 1 ) { 
		int val = mx - cnt;
		for( int x = i ; x != j ; x += k ) 
			a[x] = val++;
	} else { 
		int val = - (cnt/2); 
//		cout << "BAGHALI " << cnt << endl;
		for( int x = i ; x != j ; x += k ) 
			a[x] = val++;
	}
}

int main() { 
	cin >> n >> k;

	for( int i =0 ; i < n ;i ++ )  {
		string s;
		cin >> s; 
		if( s == "?" ) 
			mark[i] = 1;
		else 
			a[i] = atoi( s.c_str() ) ; 
		//cout <<i << ' '<<  mark[i] << endl;
	}

	for( int i = 0 ; i < k ; i++ ) { 
		int mn = -1e9 - maxN; 
		int last = i; 
		int x = i;
		for( int j = i ; j < n ; j += k )  {
			if( !mark[j] ) {
				if( last != j ) 
					doJob( last , j , mn , a[j] ) ; 
				last = j + k; 
				mn = a[j];
			} 
			x = j;
		}
//		cerr << last << ' ' << i << ' ' << x << endl;
		if( x + k != last ) 
			doJob( last , x + k , mn , int( 1e9 + maxN ) ) ; 
	}

	for( int i = 0 ; i < n - k ; i++ ) 
		if( a[i] >= a[i+k] ) { 
			cout << "Incorrect sequence" << endl;
			return 0;
		}

	for( int i = 0 ; i < n ; i++ ) 
		cout << a[i] << ' ';
	cout << endl;
}