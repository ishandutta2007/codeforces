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

int S(ll i)
{
	int r = 0;
	while (i != 0) {
		r += (int) (i % 10LL);
		i /= 10LL;
	}
	return r;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll N;
	cin >> N;

	int ret = 0;
	for (ll i = 0, lim = min(N, (ll) 1e4); i <= lim; i++)
		ret = max(ret, S(i) + S(N - i));

	ll k = 1;
	while (k * 10LL <= N) k *= 10LL;
	// k <= N, maximal

	ll G = k * (N / k);
	assert(G <= N);

	cerr << G << endl;

	int alt1 = S(G - 1) + S(N - (G - 1));
	int alt2 = S(N) + S(0);

	ret = max(ret, alt1);
	ret = max(ret, alt2);
	cout << ret << endl;

	return 0;
}