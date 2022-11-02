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

void run(int N, vi &ans, int prod)
{
	if (N == 1) {
		ans.pb(prod);
		return;
	} else if (N == 2) {
		ans.pb(prod);
		ans.pb(prod + prod);
		return;
	} else if (N == 3) {
		ans.pb(prod);
		ans.pb(prod);
		ans.pb(prod + prod + prod);
		return;
	}

	// bigger cases...
	for (int i = 1; i <= N; i += 2) {
		ans.pb(prod); // remove i
	}
	run(N / 2, ans, prod + prod);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vi ans;

	run(N, ans, 1);

	bool fst = true;
	for (int i : ans) {
		if (fst) fst =false;
		else printf(" ");
		printf("%d", i);
	}
	printf("\n");

	return 0;
}