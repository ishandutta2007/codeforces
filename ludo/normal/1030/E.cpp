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

const int maxn = 3e5 + 10;
const int maxbits = 64;

int N, a[maxn];

ll run()
{
	int nodd = 0, neven = 1;
	ll ret = 0;
	REP(i, N) {
		if (a[i] & 1) swap(nodd, neven);
		ret += neven;
		// cerr << "ENDING AT " << i << ": " << neven << endl;
		neven++;
	}

// 	cerr << "NOW: " << ret << endl;

	REP(i, N) {
		// if it starts here, which ones are wrong?
		for (int j = i, pf = a[i], mx = a[i]; j < N && pf < 128;) {
			if (pf - mx < mx && pf % 2 == 0) {
//				cerr << "EXCLUDING [" << j << ", " << i << "]" << endl;
				ret--; // do not count this one.
			}
			++j;
			pf += a[j];
			mx = max(mx, a[j]);
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	REP(i, N) {
		ll X;
		cin >> X;
		a[i] = __builtin_popcountll(X);
	}

#ifdef DEBUG
	REP(i, N) cout << a[i] << " ";
	cout << endl;
#endif

	ll ret = run();
	cout << ret << endl;
	return 0;
}