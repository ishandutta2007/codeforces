#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int) (v).size())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

bool works(string &s, int k) {
	int n = sz(s);
	for (int i = k; i < n; i++) {
		if (s[i] != s[i-k]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	string S;
	cin >> S;

	if (!works(S, k)) {
		// increment
		string alt;
		REP(i, n) alt += S[i % k];

		if (S <= alt && works(alt, k)) {
			S = alt;
		} else {
			// increment by one
			int idx = k-1;
			alt[idx]++;

			while (alt[idx] == '9' + 1) {
				alt[idx] = '0';
				if (idx == 0) {
					alt.insert(alt.begin(), '0');
					idx++;
				}
				alt[idx - 1]++;
				idx--;
			}

			for (int i = k; i < sz(alt); i++)
				alt[i] = alt[i-k];

			S = alt;
		}
	}

	assert(works(S, k));

	cout << sz(S) << endl;
	cout << S << endl;
	return 0;
}