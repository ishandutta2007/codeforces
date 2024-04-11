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

const int maxn = 1e5;

int N, A[maxn];

unordered_map<int, int> cnt;
unordered_map<int, int> cnt_popped;

int main()
{
	bool on[26] = {};

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	string S;
	getline(cin, S);
	REP(j, N) {
		getline(cin, S);
		for (char ch : S) {
			on[ch - 'a'] = !on[ch - 'a'];
		}

		int mask = 0;
		REP(i, 26) {
			if (on[i]) {
				mask |= 1 << i;
				on[i] = false;
			}
		}
		A[j] = mask;
	}

	ll ret = 0;
	REP(k, N) {
		int m = A[k];

		ret += cnt[m];
		ret += cnt_popped[m];

		for (int i = 0, j = 1; i < 26; i++, j <<= 1) {
			if (m & j) {
				ret += cnt[m ^ j];
				cnt_popped[m ^ j]++;
			}
		}
		cnt[m]++;
	}

	cout << ret << endl;

	return 0;
}