/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 100*1000 + 100;
const int maxK = 100 + 2;

ll d[maxN];
ll a[maxN];

ll s[maxN];
ll dp[maxN][maxK];

ll when( int i , int j , int k ) { 
	ll bi = dp[i][k-1] - s[i] + (i*1LL*a[i+1]) ; 
	ll bj = dp[j][k-1] - s[j] + (j*1LL*a[j+1]) ; 
	ll ai = -a[i+1];
	ll aj = -a[j+1];

	if( aj >= ai ) 
		return 1e16;

//	cout << i << ' ' << j << endl;

	ll ret = ( bj - bi + ai - aj - 1 ) / ( ai - aj ) ;
	return ret;
}


int main() { 
	int n,m,p;
	cin >> n >> m >> p; 

	for( int i = 1 ; i < n ; i++ ) {
		cin >> d[i];
		d[i] += d[i-1];
	}
	for( int i = 1; i <= m ; i++ ) { 
		int h,t;
		cin >> h >> t;
		a[i] = t - d[h-1];
	}

	ll x = *max_element( a + 1 , a + m + 1 ) + 1;
	for( int i = 1 ; i <= m ; i++ ) 
		a[i] = x - a[i];
	sort( a , a + m + 1 ) ; 

//	cin >> m >> p ; 
//	for( int i = 0 ; i < m ; i++ ) 
//		cin >> a[i+1] ;
//	for( int i= 0 ; i <= m ; i++ ) 
//		cout << a[i] << ' ' ;
//	cout<< endl;
	for( int i = 1 ; i <= m ; i++ ) 
		s[i] = a[i] + s[i-1];

	memset( dp , 95  , sizeof dp ) ; 

	dp[0][0] = 0;

	for( int k = 1 ; k <= p ; k++ ) {
		deque<pair<int,ll>> curr;
		curr.push_back( {k-1, 0} ) ;
		for( int i = k ; i <= m ; i++ ) { 
			while( curr.size() >= 2 && curr[1].second <= i ) 
				curr.pop_front();

			int j = curr[0].first;
//			cout << a[i] << ' ' << (curr.size() < 2 ? -1 : curr[1].second )  << endl;
			dp[i][k] = dp[j][k-1] + s[i] - s[j] - (i-j)*1LL*a[j+1];

			while( curr.size() >= 2 && when( curr.back().first,i, k ) <= curr.back().second ) 
				curr.pop_back();

			ll x = when( curr.back().first , i, k ) ;
//			cout << i << ' ' << dp[i][k] << "   " << j << ' ' << x << endl;
			if( x <= m ) { 
//				cout << "DBG "  << i << ' ' << k << ' ' << x << endl;
				curr.push_back( {i,x} );
			}
		}
	}

	cout << dp[m][p] << endl;
}