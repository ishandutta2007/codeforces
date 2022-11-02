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
#define sz(x) ((int) (x).size())

const int maxn = 3000;

vi pi_fn(const string &s) {
	int n = sz(s); vi p(n, 0);
	for (int i = 1, j = 0; i < n; ) {
		if (s[i] == s[j]) p[i++] = ++j; // match
		else if (j > 0) j = p[j-1]; // fallback
		else i++; // no match
	} return p;
}

vi KMP(const string &pat, const vi &p, const string &text) {
	vi res; // assert(pi(pat) == p);
	for (int i = 0, j = 0; i < sz(text); ) {
		if (text[i] == pat[j]) {
			i++; if (++j == sz(pat)) res.push_back(i-sz(pat)), j = p[j-1];
		} else if (j > 0) j = p[j-1];
		else i++;
	} return res; }


int N, L[maxn] = {}, R[maxn];
string A[maxn], B[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	REP(i, N) cin >> A[i];
	REP(i, N) cin >> B[i];

	REP(i, N) {
		R[i] = sz(A[i]);
		while (L[i] < R[i] && A[i][L[i]] == B[i][L[i]]) L[i]++;
		if (L[i] == R[i]) continue; // equal!

		R[i]--;
		while (A[i][R[i]] == B[i][R[i]]) R[i]--;
		// we should have L[i] <= R[i]
	}

	while (true) {
		char cha = '\0', chb = '\0';
		REP(i, N) {
			if (L[i] == sz(A[i])) continue;
			if (L[i] == 0 || (cha && (cha != A[i][L[i]-1] || chb != B[i][L[i]-1]))) goto donel;
			cha = A[i][L[i]-1]; chb = B[i][L[i]-1];
		}
		REP(i, N) if (L[i] != sz(A[i])) L[i]--;
	}
donel:
	while (true) {
		char cha = '\0', chb = '\0';
		REP(i, N) {
			if (L[i] == sz(A[i])) continue;
			if (R[i] == sz(A[i])-1 || (cha && (cha != A[i][R[i]+1] || chb != B[i][R[i]+1]))) goto doner;

			cha = A[i][R[i]+1]; chb = B[i][R[i]+1];
		}
		REP(i, N) if (L[i] != sz(A[i])) R[i]++;
	}
doner: // dner? yes please!

	int len = -1;
	string S, T;
	REP(i, N) {
		if (L[i] == sz(A[i])) continue;
		if (len < 0) {
			len = R[i] - L[i] + 1;
			S = A[i].substr(L[i], len);
			T = B[i].substr(L[i], len);
			continue;
		}
		// check if it matches...
		REP(j, len) if (A[i][L[i] + j] != S[j] || B[i][L[i] + j] != T[j]) {
			cout << "NO\n";
			return 0;
		}
	}

	vi p = pi_fn(S);
	// do the replacement...
	REP(i, N) {
		vi ret = KMP(S, p, A[i]);
		if (ret.empty()) continue;
		REP(j, len) A[i][ret.front() + j] = T[j];
	}

	REP(i, N) REP(j, sz(A[i])) if (A[i][j] != B[i][j]) { cout <<"NO\n"; return 0; }
	cout << "YES\n" << S << endl << T << endl;
	return 0;
}