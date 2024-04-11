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

	int ntc;
	ll ret = 0;
	cin >> ntc;
	vector<ll> A(ntc);
	REP(i, ntc) cin >> A[i];

	ll X, F;
	cin >> X >> F;

	REP(i, ntc) {
		ll s = (A[i] + F - 1) / (X + F);
		ret += s;
	}

	cout << (ret * F) << endl;

	return 0;
}