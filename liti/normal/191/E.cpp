/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 1000*100 + 100;
const int maxL = 20;
ll seg[maxL][maxN];
ll a[maxN];

int n;

void makeTree( int xl = 0 , int xr = n , int id = 0 ) { 
	if( xr - xl == 1 ) { 
		seg[id][xl] = a[xr] - a[xl];
		return;
	}
	int xm = (xl+xr) >> 1; 
	makeTree( xl , xm , id + 1 ) ; 
	makeTree( xm , xr , id + 1 ) ; 

	for( int i = xl ; i < xm ; i++ ) 
		seg[id][i] = a[xm] - a[i];
	for( int i = xm ; i < xr ; i++ ) 
		seg[id][i] = a[i+1] - a[xm];

	sort( &seg[id][xl] , &seg[id][xm] ) ; 
	sort( &seg[id][xm] , &seg[id][xr] ) ; 
}

ll findGreater( ll v , int xl = 0 , int xr = n , int id = 0 ) { 
	if( xr - xl == 1 ) 
		return seg[id][xl] >= v;

	int xm = (xl+xr)>>1;
	ll ret = 0;
	ret += findGreater( v , xl , xm , id + 1 ) ; 
	ret += findGreater( v , xm , xr , id + 1 ) ; 

	int ind = xr; 
	for( int i = xl ; i < xm ; i++ ) { 
		while( ind != xm && seg[id][ind-1] + seg[id][i] >= v ) 
			ind--;
		ret += xr - ind;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	ll k;
	cin >> n >> k;
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i+1];
	for( int i = 1 ; i < n ; i++ ) 
		a[i+1] += a[i];

	makeTree();

	ll s = -1e15 , e = 1e15; 
	while( e - s > 1 ) { 
		ll m = (s+e)>>1;
		if( findGreater(m) < k ) 
			e = m;
		else
			s = m;
	}
	cout << s << endl;
}