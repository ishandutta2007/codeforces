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

bool solve(vi &v)
{
	int N = v.size();
	int s = 0;

	REP(i, N) s += v[i];
	
	for (int i = 2; i <= 1000; i++) {
		if (s % i != 0) continue;
		// divide into $i$ pieces.
		int neededsum = s / i;
		
		int cur = 0;
		bool valid = true;
		for (int j = 0; j < N; j++) {
			cur += v[j];
			if (cur > neededsum) { valid = false; break; }

			if (cur == neededsum)
				cur = 0;
		}

		if (valid && cur == 0)
			return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string S;
	cin >> n >> S;

	vi A(n, 0);
	REP(i, n) A[i] = S[i] - '0';

	bool ret = solve(A);
	cout << (ret ? "YES" : "NO") << endl;
	return 0;
}