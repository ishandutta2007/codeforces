#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
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
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

void run() {
	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto &x : v)
		cin >> x;
	
	ll sum = 0;
	ll xoor = 0;
	for (auto &x: v) sum += x;
	for (auto &x: v) xoor ^= x;

	// (sum, xoor) -> (sum + xoor, 0) -> (2 (sum + xoor), sum + xoor).

	cout << 2 << endl;
	cout << xoor << " ";
	cout << (sum + xoor) << endl;

	ll nsum = sum, nxoor = xoor;

	nsum += xoor; nxoor ^= xoor;
	nsum += (sum + xoor); nxoor ^= (sum + xoor);

	assert(nsum == 2LL*nxoor);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ntc;
	cin >> ntc;
	while (ntc--) run();

	return 0;
}