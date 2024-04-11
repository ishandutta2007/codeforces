//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<int,int> pii; 
typedef long double ld; 

const int maxN = 2000 * 100 + 100; 
int a[maxN]; 
ld isum[maxN]; ll psum[maxN]; 

ld dp[maxN] , odp[maxN]; 

pair<int,ld> que[maxN];  
inline ld when( int i , int j ) { //when i surpass j ? 
	ld ia = isum[i] , ib = odp[i] - isum[i] * psum[i]; 
	ld ja = isum[j] , jb = odp[j] - isum[j] * psum[j]; 
	// ia * x + ib = ja * x + jb => x = (jb - ja) / (ia - ib) 
//	cerr << ia << ' ' << ib << "  !!!  " << ja << ' ' << jb << endl;
	return (jb-ib) / (ia - ja);  
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	cout << fixed << setprecision(9); 
	int n,t; cin >> n >> t; 
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i]; 
	ld ans = 0; 
	for( int i = n - 1 ; i >= 0 ; i-- ) { 
		isum[i] = isum[i+1] + 1 / ld(a[i]); 
		psum[i] = psum[i+1] + a[i]; 
		ans += a[i] * isum[i]; 
	}
//	cerr << ans << endl;

	for( int k = 1 ; k < t ; k++ ) { 
		swap( odp , dp ) ; 
		int st, en = st = 0; 
		que[en++] = {n-k,0}; 
		for( int i = n - k - 1 ; i >= 0 ; i-- ) {
			while( en - st > 1 && que[st+1].second <= psum[i] ) 
				st++; 
//			cerr << "ST " << st <<  ' ' << que[st+1].second << "?" << psum[i] << '\r' << endl;
			int u = que[st].first; 
			dp[i] = (psum[i]-psum[u])*isum[u] + odp[u]; 
//			cerr << k << ' ' << i << " -> " << dp[i] << "  u: " << u << '\r'<< endl;
			while( en - st > 1 && when( i , que[en-2].first ) <= que[en-1].second ) 
				en--; 
//			cerr << i << " <---> " << when( i , que[en-1].first ) << '\r' << endl;
			que[en] = { i , when( i , que[en-1].first ) }; 
			en++; 
		}
	}
	cout << ans - dp[0] << endl;
}