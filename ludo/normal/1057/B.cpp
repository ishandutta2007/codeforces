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

#define RET(x) { printf("%d\n", x); return 0; }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vi v(N);
	REP(i, N) {
		cin >> v[i];
		v[i] -= 100;
	}

	for (int w = N; w > 0; w--) {
		int l = 0, pf = 0;
		REP(i, w) pf += v[i];
		while (1) {
			if (pf > 0) RET(w);
			if (l + w >= N) break;
			pf += v[l + w];
			pf -= v[l++];
		}
	}
	RET(0);
}