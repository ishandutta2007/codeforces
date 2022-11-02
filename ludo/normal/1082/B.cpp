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
	string S;
	cin >> n >> S;

	int ng = 0;
	for (char ch : S) ng += ch == 'G';

	if (ng == 0) return cout << 0 << endl, 0;
	if (ng == n) return cout << n << endl, 0;

	int ret = 0, curlen = 0, lstlen = 0;
	for (char ch : S) {
		if (ch == 'S') {
			lstlen = curlen;
			curlen = 0;
		} else {
			// GOld
			ret = max(ret, ++curlen);
			ret = max(ret, min(ng, curlen + lstlen + 1));
		}
	}
	cout << ret << endl;
	return 0;
}