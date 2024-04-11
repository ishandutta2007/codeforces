/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 100*1000 + 10; 
const int maxM = 5000 + 10; 

int a[maxN], h[maxN];
ll fin[maxN];
int cnt[maxM];

int n,m,k,p;

ll gg( int i , ll val ) { 
//	cerr << i << ' ' << val << ' ' ;
	val = max( val - h[i] , 0ll ) ; 
//	cerr << (val + a[i] - 1)/a[i] << endl;
	return (val + a[i] - 1)/a[i];
}

bool canDo( ll v ) { 
	memset(cnt,0,sizeof cnt);
	int mx = 0;

//	cerr << "BEG :" << v << endl;

	for( int i = 0 ; i < n ; i++ ) {
		ll x = max(0ll,fin[i]-v);
//		cerr << "DBG " << i << " " << x << endl;
		if( x == 0 ) continue;
		ll b = x % p; 
		ll z = x / p;
		for( int j = (b==0) ; j <= z ; j++ ) {
			if( mx > m*k ) 
				return false;
			mx++;
			int ind = gg(i,b + p*1ll*j);
			if( ind >= m ) return false;
			cnt[ind]++;
		}
	}
	int sum = 0;
	for( int i = m - 1 ; i >= 0 ; i-- ) {
		sum += cnt[i];
//		cerr << "DAY " << i << ' ' << cnt[i] << endl;
		if( sum > (m-i)*k ) 
			return false;
	}
	return true;
}

int main() { 
	cin >> n >> m >> k >> p;

	for( int i = 0 ; i < n ; i++ ) {
		cin >> h[i] >> a[i];
		fin[i] = h[i] + a[i]*1ll*m ; 
	}

	ll s = -1 , e = 1e16;
	while( e - s > 1 ) { 
		ll mid = (s+e)/2;
		if( canDo(mid) ) e = mid;
		else s = mid;
	}
	cout << e << endl;

//	cout << canDo(14) << endl;
}