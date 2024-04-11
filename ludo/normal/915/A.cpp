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

const bool ONE_TC = true;


void run()
{
	int N, K;
	cin >> N >> K;
	int ret = K;
	REP(i, N) {
		int X;
		cin >> X;
		if (K % X == 0) {
			ret = min(ret, K / X);
		}
	}
	cout << ret << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (ONE_TC) run();
	else {
		int ntc;
		cin >> ntc;
		while (ntc--) run();
	}

	return 0;
}