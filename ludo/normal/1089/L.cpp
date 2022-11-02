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

const int INF = 1e9;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vi A(n), B(n);
	for (int &x:A)cin>>x, x--;
	for (int &x:B)cin>>x;

	vi maxt(k, 0), avail;
	REP(i, n) {
		if (B[i] > maxt[A[i]]) {
			if (maxt[A[i]]) avail.pb(maxt[A[i]]);
			maxt[A[i]] = B[i];
		} else avail.pb(B[i]);
	}
	sort(all(avail));

	int needed = k;
	REP(i, k) if (maxt[i] > 0) needed--;
	ll ans = 0;
	REP(i, needed) ans += avail[i];
	cout << ans << endl;


	return 0;
}