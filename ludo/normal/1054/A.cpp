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

	int x, y, z, t1, t2, t3;
	cin >> x >> y >> z >> t1 >> t2 >> t3;

	int tstarts = abs(x - y) * t1;
	int telev = abs(z - x) * t2;
	telev += abs(x - y) * t2;
	telev += 3 * t3;

	cerr << tstarts << " " << telev << endl;

	if (telev <= tstarts)
	cout << "YES" << endl;
else cout << "NO" << endl;

	return 0;
}