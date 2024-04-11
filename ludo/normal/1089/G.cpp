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

const int INF = 1e9;
int x, a[7];
int mint[8];

void run()
{
	int na = 0;
	scanf("%d", &x);
	fill_n(mint, 8, INF);
	REP(i, 7) {
		scanf("%d", &a[i]);
		na += a[i];
	}

	REP(i, 7) {
		int c = 0;
		REP(j, 7) {
			c += a[(i + j) % 7];
			mint[c] = min(mint[c], j);
			// cerr << "From " << i << " after " << j << " days: " << c << endl;
		}
	}

	assert(mint[na] != INF);
	ll ans = 1;
	x--;

	int q = x / na;
	ans += 7 * q;
	int r = x % na;
	ans += mint[r + 1];
	printf("%lld\n", ans);

	// REP(i, na + 1) cerr << mint[i] << " ";
	// cerr << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ntc;
	scanf("%d", &ntc);
	while(ntc--) run();
	return 0;
}