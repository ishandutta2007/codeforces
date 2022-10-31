/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 2000 + 10;
typedef long long ll;

ll a[2*maxN] , b[2*maxN];
int m[maxN][maxN];

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n; 

	for( int i = 0 ; i < n ; i++ ) 
		for( int j= 0 ; j < n ;j++ ) { 
			int num;
			cin >> num;
			m[i][j] = num;
			a[i+j] += num;
			b[i-j+n] += num;
		}

	vector<int> ret;
	ll sum = 0;
	for( int t = 0 ; t < 2 ; t++ ) { 
		int x = 0,y = t;
		ll ans = 0;
		for( int i = 0 ; i < n; i++ )
			for( int j= 0 ; j < n ; j++ ) 
				if( ( i + j ) % 2 == t ) 
					if( ans < a[i+j] + b[i-j+n] - m[i][j] ) { 
						ans = a[i+j] + b[i-j+n] - m[i][j];
						x = i;
						y = j;
					}
		sum += ans;
		ret.push_back( x + 1 ) ; ret.push_back( y + 1 ) ; 
	}

	cout << sum << endl;
	for( int i = 0 ; i <4 ; i++ ) 
		cout << ret[i] << ' ' ;
	cout << endl;
}