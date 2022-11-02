#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef vector<ll> vi;

ll gcd(ll a, ll b) { while (b) a %= b, swap(a, b); return a; }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll N, M, K;
	cin >> N >> M >> K;

	ll A2 = N * M * 2LL;
	if (A2 % K != 0) {
		cout << "NO" << endl;
		return 0;
	}
	A2 /= K;

	// try
	// (0, 0)
	// (0, y)
	// (u, 0)

	ll g = gcd(2LL * N, K);
	ll h = gcd(2LL * M, K);

	assert(g > 1 || h > 1);

	cout << "YES" << endl;
	cout << "0 0" << endl;
	ll u, y;
	if (g > 1) {
		u = N * 2LL / g;
		y = M / (K / g);
	} else {
		u = N / (K / h);
		y = M * 2LL / h;
	}

	cout << "0 " << y << endl;
	cout << u << " 0" << endl;
	return 0;
}