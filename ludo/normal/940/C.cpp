#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define rep(i,a,b) for (auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ostream& operator<<(ostream &out, const ii &pr) { return out << '(' << pr.x << ',' << pr.y << ')'; }

int N, K;
string S;

bool used[26] = {};
int nused = 0, lk[26] = {};
char usedc[26] = {};

void run()
{
	cin >> N >> K >> S;
	for (char ch : S) used[ch - 'a'] = true;
	REP(i, 26) if (used[i]) {
		lk[i] = nused;
		usedc[nused++] = 'a' + i;
	}

	if (K > N) {
	    while (N < K) {
		    S += usedc[0];
		    N++;
	    }
		return;
	}
	while (N > K) {
		S.pop_back();
		N--;
	}

	int idx = N - 1;
	while (idx >= 0) {
		if (lk[S[idx] - 'a'] != nused - 1) {
			S[idx] = usedc[lk[S[idx] - 'a'] + 1];
			return;
		}
		S[idx] = usedc[0];
		idx--;
	}
	assert(false);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	run();
	cout << S << endl;
	return 0;
}