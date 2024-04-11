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
	cin >> ntc;
	while (ntc--) {
		ll S, A, B, C;
		cin >> S >> A >> B >> C;

		ll n = S / C; // round down.
		ll q = n / A;
		ll r = n % A;

		ll ret = q * (A + B) + r;
		cout << ret << endl;
	}
	return 0;

}