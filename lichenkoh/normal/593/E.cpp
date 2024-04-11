#include <vector>
#include <iostream>
#include <complex>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MOD 1000000007LL
#define PB push_back
#define UNDEF -1
ll **A;
ll **B;
ll **C;
ll **TMP;
bool cat[21][21];
ll n,m,s;
ll *v, *w;

void mul(ll **P, ll **Q, ll **R) {
	for (ll i = 0; i < s; i++) {
		for (ll j = 0; j < s; j++) {
			ll ans = 0;
			for (ll k = 0; k < s; k++) {
				ans = (ans + (P[i][k] * Q[k][j])%MOD)%MOD;
			}
			R[i][j] = ans;
		}
	}
}

void mov(ll **P, ll **Q) {
	for (ll i = 0; i < s; i++) {
		for (ll j = 0; j < s; j++) {
			P[i][j] = Q[i][j];
		}
	}
}

void ex(ll e) {
	mov(C,A);
    for (ll i = 0; i < s; i++) {
    	for (ll j = 0; j < s; j++) {
    		B[i][j] = 0;
    	}
    }
    for (ll i = 0; i < s; i++) {
    	B[i][i] = 1;
    }
    while (e > 0) {
        if (e%2 == 1) {
        	mul(B,C,TMP);
        	mov(B,TMP);
        }
        mul(C,C,TMP);
        ll **xchg = TMP;
        TMP = C;
        C = xchg;
        //mov(C,TMP);
        e /= 2;
    }
    return;
}


void go(ll e) {
	ex(e);
	for (ll i = 0; i < s; i++) {
		ll ans = 0;
		for (ll j = 0; j < s; j++) {
			ll toadd = (B[i][j] * v[j])%MOD;
			ans = (ans + toadd)%MOD;
		}
		w[i] = ans;
	}
	for (ll i = 0; i < s; i++) {
		v[i] = w[i];
	}
}

ll get(ll x, ll y) {
	if (1 <= x && x <= n && 1 <= y && y <= m) {
		ll ans = (x-1)*m + (y-1);
		assert(0 <= ans && ans < 21);
		return ans;
	}
	return -1;
}

void sete(ll x, ll y, ll v) {
	if (x != -1 && y != -1) {
		A[x][y] = v;
		A[y][x] = v;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	A = new ll*[21];
	B = new ll*[21];
	C = new ll*[21];
	TMP = new ll*[21];
	for (ll i = 0; i < 21; i++) {
		A[i] = new ll[21];
		B[i] = new ll[21];
		C[i] = new ll[21];
		TMP[i] = new ll[21];
	}
	ll q; cin >> n; cin >> m; cin >> q;
	s = n*m;
	v = new ll[s];
	w = new ll[s];
	for (ll i = 0; i <s; i++) {
		v[i] = 0; w[i] = 0;
	}
	v[get(1,1)] = 1;
	for (ll x = 0; x < s; x++) {
		for (ll y = 0; y < s; y++) {
			A[x][y] = 0;
		}
	}
	for (ll i = 0; i < s; i++) {
		A[i][i] = 1;
	}
	for (ll x = 1; x <= n; x++) {
		for (ll y = 1; y <= m; y++) {
			ll xy = get(x,y);
			for (ll i = -1; i <= 1; i += 2) {
				sete(xy,get(x+i,y), 1);
				sete(xy,get(x,y+i), 1);
			}
		}
	}
	for (ll x = 1; x <= n; x++) {
		for (ll y = 1; y <= m; y++) {
			cat[x][y] = false;
		}
	}
	ll prevt = 1;
	for (ll ii = 0; ii < q; ii++) {
		ll tp,x,y,t;
		cin >> tp; cin >> x; cin >> y; cin >> t;
		go(t-prevt);
		if (tp == 1) {
			ll ans = v[get(x,y)];
			printf("%I64d\n", ans);
		}
		else if (tp == 2) {
			cat[x][y] = true;
			for (ll i = -1; i <= 1; i += 2) {
				ll xy = get(x,y);
				sete(xy,get(x+i,y), 0);
				sete(xy,get(x,y+i), 0);
				v[xy] = 0;
			}
		}
		else if (tp == 3) {
			cat[x][y] = false;
			ll xy = get(x,y);
			for (ll i = -1; i <= 1; i += 2) {
				if (!cat[x+i][y]) sete(xy,get(x+i,y), 1);
				if (!cat[x][y+i]) sete(xy,get(x,y+i), 1);
			}
		}
		else {
			assert(false);
		}
		//cout << "Vector at time: " << t << endl;
		//for (ll i = 0; i < s; i++) {
		//	cout << v[i] << " ";
		//}
		//cout << endl;
		prevt = t;
	}
}