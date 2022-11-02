/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;
typedef double ld;
typedef complex<ld> P; 

const int maxN = 4000*1000 + 10; 
const ld PI = 3.141592654;
typedef P Vec[maxN];

Vec a, tmp; 

inline void FFT( Vec a , int m , int inv = 0 ) { 
	for( int t = 2 ; t <= m ; t *= 2 ) {
		P wn = polar( ld(1) , (inv?-1:1) * 2 * PI / t ) ;
		for( int k = 0 ; k < m ; k += t ) {
			int s = k , e = k + t;
			int m = ( s + e ) / 2;
			P pow( 1 , 0 ) ;
			for( int i = s ; i < m ; i++ ) { 
				P x = a[i] + pow*a[i+m-s];
				P y = a[i] - pow*a[i+m-s] ; 
				a[i] = x;
				a[i+m-s] = y;
				pow = pow * wn;
			}
		}
	}
}
inline void make_ready( int m , int t ) { 
	for( int i = 0 ; i < m ; i++ ) { 
		int rev = 0;
		for( int j = 0 ; j < t ; j++ ) 
			if( (i>>j) & 1 ) 
				rev += (1<<(t-j-1));
		if( i < rev ) 
			swap( a[i] , a[rev] ) ; 
	}
}

int used[maxN];
int val[maxN];

vector<int> ans;
int main() { 
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	cin >> n >> m; 
	int tmpM = m;
	for( int i = 0 ; i < n ; i ++ ) { 
		cin >> val[i];
		a[val[i]].real(1); 
	}

	m = 2 * m + 1; 
	int t = 0;
	for( int i = 0 ; i < 24 ; i++ ) 
		if( (1<<i) >= m ) { 
			m = (1<<i);
			t = i;
			break;
		}

	make_ready( m , t ) ;
	FFT( a , m ) ; 
	for( int i = 0 ; i < m ; i++ ) 
		a[i] = a[i] * a[i];
	make_ready( m , t );
	FFT( a , m , 1 ) ; 
	for( int i = 0 ; i < m ; i++ ) 
		a[i] *= 1 / ld(m);

	//	for( int i = 0 ; i < m ; i++ ) 
	//		cout << a[i].real() << ' ' << a[i].imag() << endl;

	for( int i = 0 ; i < n ; i++ ) {
		used[val[i]] = 1;
		if( abs( a[val[i]].real() ) <= 0.5 ) 
			ans.push_back( val[i] ) ; 
	}
	for( int i = 0 ; i <= tmpM ; i++ ) 
		if( !used[i] && abs( a[i].real() ) > 0.5 ) {
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl << ans.size() << endl;
	for( int i = 0 ; i < sz(ans) ; i++ ) 
		cout << ans[i] << ' ';
	cout << endl;
}