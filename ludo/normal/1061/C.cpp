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

// int gcd(int a, int b) { while (b) a %= b, swap(a,b); return a; }

const int maxn = 1e6 + 1;
const int mod = 1e9 + 7;
int nrseqs[maxn + 1] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vi A(n);
	for (int &x : A) cin >> x;

	nrseqs[0] = 1;
	for (int v : A) {
		vi divslo, divshi;
		for (int j = 1; j * j <= v; j++) {
			if (v % j == 0) {
				divslo.pb(j);
				divshi.pb(v / j);
			}
		}
		// remove the duplicate square
		if (!divshi.empty() && divshi.back() * divshi.back() == v)
			divshi.pop_back();

		reverse(all(divslo));
		// divshi (concat) divslo is sorted descendingly.

		for (int i : divshi)
			if ((nrseqs[i] += nrseqs[i-1]) >= mod)
				nrseqs[i] -= mod;
		for (int i : divslo)
			if ((nrseqs[i] += nrseqs[i-1]) >= mod)
				nrseqs[i] -= mod;
	}

	int ret = 0;
	for (int i = 1; i <= maxn; i++)
		if ((ret += nrseqs[i]) >= mod) ret -= mod;

	cout << ret << endl;
	return 0;
}