#include<bits/stdc++.h>
using namespace std;

#define REP(i, n) for (auto i = 0; i < n; i++) 
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;

const int MOD = 1e9 + 7;
const int maxn = 301;

vi primes;
int nck[maxn][maxn], fct[maxn];

int ADD(int a, int b) { return (a + b) % MOD; }
int MUL(int a, int b) { return (int) (1LL * a * b % MOD); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int upto = sqrt(MOD) + 1;
	vector<bool> isprime(upto, true);
	for (int i = 2; i * i < upto; i++) {
		if (!isprime[i]) continue;
		for (int j = i * i; j < upto; j += i) isprime[j] = false;
	}
	for (int i = 2; i < upto; i++) {
		if (isprime[i]) primes.pb(i);
	}

	fct[0] = 1;
	for (int i = 1; i < maxn; i++) fct[i] = MUL(fct[i - 1], i);
	for (int i = 0; i < maxn; i++) {
		nck[i][0] = nck[i][i] = 1;
		for (int j = 1; j < i; j++) nck[i][j] = ADD(nck[i-1][j-1], nck[i-1][j]);
	}

	int N;
	cin >> N;
	vi a(N);
	REP(i, N) cin >> a[i];
	REP(i, N) {
		int alt = 1;
		for (int p : primes) {
			if (p * p > a[i]) break;
			while (a[i] % (p * p) == 0) a[i] /= p * p;
			if (a[i] % p == 0) {
				a[i] /= p;
				alt *= p;
			}
		}
		a[i] = alt * a[i];
	}
	sort(ALL(a));

	vi cnt;
	for (int i = 0; i < N; i++) {
		if (!i || a[i] != a[i-1]) cnt.pb(0);
		cnt.back()++;
	}

	vi curdp(N + 1, 0), nxtdp(N + 1, 0);
	curdp[0] = 1;
	int ltotal = 1, ntotal;
	for (int c : cnt) {
		ntotal = ltotal + c;

		for (int j = 0; j <= ltotal; j++) {
			// j: # of wrong adjacencies
			for (int k = 1; k <= min(c, ltotal); k++) {
				for (int l = 0; l <= min(j, k); l++) {
					int jp = j - l + c - k;
					if (jp >= ntotal) continue;
					// jp < ntotal
					// j - l + c - k < ntotal
					// j + c - k - ntotal < l
					// l >= j + c - k - ntotal + 1
					// j - l >= 0, c - k >= 0
					// cerr << "BEFORE: " << c << ", " << jp << "/" << ntotal << ": " << nxtdp[jp] << endl;
					nxtdp[jp] = ADD(nxtdp[jp], MUL(MUL(curdp[j], nck[j][l]), MUL(nck[ltotal - j][k - l], nck[c - 1][k - 1])));
					// cerr << "AFTER:  " << c << ", " << jp << ": " << nxtdp[jp] << endl;
				}
			}
		}
		ltotal = ntotal;
		curdp = nxtdp;
		fill(ALL(nxtdp), 0);

		// for (int i : curdp) cerr << i << " ";
		// cerr << endl;
	}
	assert(ltotal == N + 1);
	
	int ans = curdp[0];
	for (int c : cnt) {
		ans = MUL(ans, fct[c]);
	}

	cout << ans << endl;
	return 0;
}