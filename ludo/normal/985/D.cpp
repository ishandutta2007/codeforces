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

ll ceildiv(ll a, ll b) {
	return (a + b - 1) / b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll N, H;
	cin >> N >> H;

	ll lo = 0, hi = 2e9;
	while (hi - lo > 1) {
		ll x = (lo + hi) / 2LL;

		ll s = x * (x + 1) / 2;
		if (x >= H) {
			ll I = 1 + (x - H) / 2;
			s -= I * (I - 1);
			if ((x - H) % 2 == 1) {
				s -= I;
			}
		}

		if (s >= N) hi = x;
		else lo = x;
	}

	cout << hi << endl;
	return 0;
}