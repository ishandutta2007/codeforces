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

const int maxn = 2e5;
int N, M, A, B[maxn];

const ll mod = 998244353;
const ll inv2 = (mod + 1) / 2;

ll powmod(ll b, ll e)
{
	ll r = 1;
	while (e) {
		if (e & 1) r = (r * b) % mod;
		e >>= 1;
		b = (b * b) % mod;
	}
	return r;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> A;
	REP(i, M) cin >> B[i];

	ll slack = N - 2 * B[M - 1];

	ll MUL = powmod(A, slack);

	for (int i = 0; i < M; i++) {
		ll width = B[i] - (i == 0 ? 0 : B[i - 1]);
		ll Apw = powmod(A, width);
		Apw = (Apw * (Apw + 1)) % mod;
		Apw = (Apw * inv2) % mod;

		MUL = (MUL * Apw) % mod;
	}

	cout << MUL << endl;

	return 0;
}