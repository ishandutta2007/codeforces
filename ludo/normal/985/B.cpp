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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<bitset<2000>> G;
	REP(i, N) {
		string S;
		cin >> S;
		S = string(2000 - M, '1') + S;
		assert(S.size() == 2000);
		G.pb(bitset<2000>(S));
	}

	vector<int> sum(M, 0);
	REP(i, N) REP(j, M) {
		sum[j] += G[i].test(j);
	}

	bool ret = false;
	REP(i, N) {
		bool thisOne = true;
		REP(j, M) {
			thisOne &= sum[j] - G[i].test(j) > 0;
			if (!thisOne) break;
		}
		if (thisOne) { ret = true; break; }
	}

	cout << (ret ? "YES" : "NO") << endl;
	
	return 0;
}