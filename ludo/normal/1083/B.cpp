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

	ll n, k;
	cin >> n >> k;
	string A, B;
	cin >> A >> B;

	ll ret = 0;
	ll ways = 1;
	bool isinf = false;
	REP(i, n) {
		if (!isinf) {
			ways *= 2;
			if (B[i] == 'a') ways--;
			if (A[i] == 'b') ways--;
		}
		isinf |= ways > 1e11;
		ret += isinf ? k : min(ways, k);
	}
	cout << ret << endl;

	return 0;
}