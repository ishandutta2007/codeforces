#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 101010;
int _w;

int n, x[N], y[N], u[N], v[N];
map<pii,int> mp;

int ggcd( int a, int b ) {
    return b ? ggcd(b, a%b) : a;
}

int main() {
    int T;
    _w = scanf( "%d", &T );
    while( T-- ) {
	_w = scanf( "%d", &n );
	mp.clear();
	for( int i = 1; i <= n; ++i ) {
	    _w = scanf( "%d%d%d%d", x+i, y+i, u+i, v+i );
	    u[i] -= x[i];
	    v[i] -= y[i];
	    int g = ggcd( abs(u[i]), abs(v[i]) );
	    u[i] /= g;
	    v[i] /= g;
	    mp[pii(u[i], v[i])]++;
	}
	ll ans = 0;
	for( auto it = mp.begin(); it != mp.end(); ++it ) {
	    pii vec = it->first;
	    int cnt = it->second;
	    vec.first = -vec.first;
	    vec.second = -vec.second;
	    ans += 1LL * cnt * mp[vec];
	}
	printf( "%lld\n", ans/2 );
    }
    return 0;
}