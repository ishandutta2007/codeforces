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

	int n;
	cin >> n;
	vi v(n);
	for (auto &i : v) cin >> i;
	int sinc = 0;
	vi inc(n);
	for (int i = n - 1; i >= 0; i--) {
		inc[i] = i - (sinc + v[i]);

		inc[i] = inc[i] % n;
		if (inc[i] < 0) inc[i] += n;

		sinc += inc[i];
	}

	cout << (n + 1) << endl;
	REP(i, n) cout << "1 " << (i + 1) << " " << (inc[i]) << endl;
	cout << "2 " << n << " " << n << endl;
	return 0;
}