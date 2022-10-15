#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1010;
const int MR[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
const int LIM = 1000010;
int _w;

int isp[LIM];
void prelude() {
    memset(isp, 1, sizeof isp);
    isp[0] = isp[1] = 0;
    for( int i = 2; i < LIM; ++i )
	if( isp[i] )
	    for( int j = i+i; j < LIM; j += i )
		isp[j] = 0;
}

ll gcd( ll a, ll b ) {
    return b ? gcd(b, a%b) : a;
}

ll fpow( __int128 a, ll b, ll mod ) {
    __int128 c = 1;
    while(b) {
	if( b & 1 ) c = c * a % mod;
	a = a * a % mod;
	b >>= 1;
    }
    return ll(c);
}

__int128 myabs( __int128 a ) {
    return a < 0 ? -a : a;
}

bool miller_rabin( ll x ) {
    if( x < LIM ) return isp[x];
    for( int i = 0; i < 20; ++i ) {
	ll y = MR[i];
	if( fpow(y, x-1, x) != 1 )
	    return false;
    }
    return true;
}

int n, k;
ll x[N];
map<ll,int> prm[N];
int prm_idx;

void pollard_rho( ll x ) {
    if( x <= 100 ) {
	for( int i = 2; i*i <= x; ++i )
	    while( x % i == 0 )
		x /= i, ++prm[prm_idx][i];
	if( x != 1 ) ++prm[prm_idx][x];
	return;
    }
    if( miller_rabin(x) ) {
	++prm[prm_idx][x];
	return;
    }
    __int128 a = 0, b = 0;
    while(1) {
	while( a == b ) {
	    a = rand() % x;
	    b = (a * a + 1) % x;
	}
	ll g = gcd(x, (ll)myabs(a-b));
	if( g != 1 ) {
	    pollard_rho(x/g);
	    pollard_rho(g);
	    break;
	}
	a = (a * a + 1) % x;
	b = (b * b + 1) % x;
	b = (b * b + 1) % x;
    }
}

set<ll> fuck;

ll mypow( ll a, ll b ) {
    const ll LIMIT = 2e18;
    // printf( "a = %lld, b = %lld\n", a, b );
    ll c = 1;
    while(b) {
	if( b & 1 ) {
	    if( (double)c * a >= LIMIT )
		return LIMIT;
	    c = c * a;
	}
	if( (double)a * a > LIMIT )
	    a = LIMIT;
	else a = a * a;
	b >>= 1;
    }
    // printf( "c = %lld\n", c );
    return c;
}

ll check( ll x, int i ) {
    ll y = (ll)powl(x, 1. / i);
    for( ll j = max(2ll, y-10); j <= y+10; ++j )
	if( x % j == 0 ) {
	    if( mypow(j, i) == x ) {
		// printf( "j = %lld, i = %d, x = %lld\n", j, i, x );
		return j;
	    }
	}
    return -1;
	    /*
    for (ll j = y - 1; j <= y + 2; j++) {
	if (j > 1 && x % j == 0) {
	    if (miller_rabin(j) == 0) return -1;
	    while (x % j == 0) x /= j, i--;
	    if (x == 1 && i == 0) return j;
	    else return -1;
	}
    }
    return -1;
	    */
}

void pollard_rho_fuck( ll x ) {
    if( miller_rabin(x) ) {
	++prm[prm_idx][x];
	fuck.insert(x);
	return;
    }
    for( int i = 63; i >= 2; --i ) {
	ll p = check(x, i);
	if( p == -1 ) continue;
	if( miller_rabin(p) == 0 ) continue;
	prm[prm_idx][p] = i;
	fuck.insert(p);
	break;
    }
}

void pollard_rho_fucked( ll x ) {
    if( prm[prm_idx].size() ) return;
    for( ll p : fuck ) {
	while( x % p == 0 )
	    x /= p, ++prm[prm_idx][p];
    }
    if( x != 1 ) {
	++prm[prm_idx][-1];
	++prm[prm_idx][-2];
    }
}

map<ll,vector<ll>> pk;
set<ll> allow;

int main() {
    prelude();
    _w = scanf( "%d%d", &n, &k );
    for( int i = 1; i <= n; ++i )
	_w = scanf( "%lld", x+i );
    if( k == 1 ) {
	puts("0");
	return 0;
    }
    for( int i = 1; i <= n; ++i ) {
	prm_idx = i;
	pollard_rho_fuck( x[i] );
	// printf( "prm[%lld] = %d\n", x[i], (int)prm[i].size() );
    }
    for( int i = 1; i <= n; ++i ) {
	prm_idx = i;
	pollard_rho_fucked( x[i] );
    }
    for( int i = 1; i <= n; ++i )
	if( prm[i].size() == 1 )
	    pk[prm[i].begin()->first].push_back( x[i] );
    int tot_pk = 0;
    for( auto it = pk.begin(); it != pk.end(); ++it ) {
	const vector<ll> &vec = it->second;
	if( vec.size() == 1 ) continue;
	allow.insert( it->first );
	tot_pk += (int)vec.size();
    }
    int p2 = 0;
    for( int i = 1; i <= n; ++i )
	if( prm[i].size() >= 2 ) {
	    bool flag = true;
	    for( auto it = prm[i].begin(); it != prm[i].end(); ++it ) {
		ll p = it->first;
		if( allow.count(p) == 0 ) {
		    flag = false;
		    break;
		}
	    }
	    if( flag ) ++p2;
	}
    if( tot_pk + p2 < k ) {
	puts("0");
	return 0;
    }
    if( k >= tot_pk && k <= tot_pk + p2 ) {
	for( auto it = pk.begin(); it != pk.end(); ++it ) {
	    const vector<ll> &vec = it->second;
	    if( vec.size() == 1 ) continue;
	    for( ll x : vec )
		printf( "%lld ", x );
	}
	int now = tot_pk;
	if( now == k ) return 0;
	for( int i = 1; i <= n; ++i ) {
	    if( prm[i].size() >= 2 ) {
		bool flag = true;
		for( auto it = prm[i].begin(); it != prm[i].end(); ++it ) {
		    ll p = it->first;
		    if( allow.count(p) == 0 ) {
			flag = false;
			break;
		    }
		}
		if( flag ) {
		    printf( "%lld ", x[i] );
		    ++now;
		    if( now == k ) return 0;
		}
	    }
	}
	assert(0);
    }
    // k < tot_pk
    if( k % 2 == 0 ) {
	int now = 0;
	for( auto it = pk.begin(); it != pk.end(); ++it ) {
	    const vector<ll> &vec = it->second;
	    if( vec.size() == 1 ) continue;
	    printf( "%lld %lld ", vec[0], vec[1] );
	    now += 2;
	    if( now == k ) return 0;
	}
	for( auto it = pk.begin(); it != pk.end(); ++it ) {
	    const vector<ll> &vec = it->second;
	    if( vec.size() == 1 ) continue;
	    for( int i = 2; i < (int)vec.size(); ++i ) {
		printf( "%lld ", vec[i] );
		++now;
		if( now == k ) return 0;
	    }
	}
	assert(0);
    }
    // k % 2 == 1
    ll p3 = -1;
    for( auto it = pk.begin(); it != pk.end(); ++it ) {
	const vector<ll> &vec = it->second;
	if( vec.size() == 1 ) continue;
	if( vec.size() >= 3 ) {
	    p3 = it->first;
	    printf( "%lld %lld %lld ", vec[0], vec[1], vec[2] );
	    break;
	}
    }
    if( p3 == -1 ) {
	for( int i = 1; i <= n; ++i )
	    if( prm[i].size() >= 2 ) {
		bool flag = true;
		for( auto it = prm[i].begin(); it != prm[i].end(); ++it ) {
		    ll p = it->first;
		    if( allow.count(p) == 0 ) {
			flag = false;
			break;
		    }
		}
		if( flag ) {
		    if( (int)prm[i].size() * 2 + 1 <= k ) {
			set<ll> used;
			printf( "%lld ", x[i] );
			for( auto it = prm[i].begin(); it != prm[i].end(); ++it ) {
			    ll p = it->first;
			    used.insert(p);
			    printf( "%lld %lld ", pk[p][0], pk[p][1] );
			}
			int now = (int)prm[i].size() * 2 + 1;
			if( now == k ) return 0;
			for( auto it = pk.begin(); it != pk.end(); ++it ) {
			    const vector<ll> &vec = it->second;
			    if( vec.size() == 1 ) continue;
			    if( used.count(it->first) ) continue;
			    printf( "%lld %lld ", vec[0], vec[1] );
			    now += 2;
			    if( now == k ) return 0;
			}
			assert(0);
		    }
		}
	    }
	puts("0");
	return 0;
    }
    int now = 3;
    if( now == k ) return 0;
    for( auto it = pk.begin(); it != pk.end(); ++it ) {
	const vector<ll> &vec = it->second;
	if( vec.size() == 1 ) continue;
	if( it->first == p3 ) {
	    continue;
	} else {
	    printf( "%lld %lld ", vec[0], vec[1] );
	    now += 2;
	    if( now == k ) return 0;
	}
    }
    for( auto it = pk.begin(); it != pk.end(); ++it ) {
	const vector<ll> &vec = it->second;
	if( vec.size() == 1 ) continue;
	int begin = -1;
	if( it->first == p3 ) {
	    begin = 3;
	} else {
	    begin = 2;
	}
	for( int i = begin; i < (int)vec.size(); ++i ) {
	    printf( "%lld ", vec[i] );
	    ++now;
	    if( now == k ) return 0;
	}
    }
    assert(0);
    return 0;
}