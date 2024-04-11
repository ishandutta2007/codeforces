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

const int sz = 5e5 + 10;
int nopen[sz] = {}, nclose[sz] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	string S;
	getline(cin, S);

	int nclosed = 0;

	vii v;
	while (n--) {
		getline(cin, S);
		int dx = 0, minx = 0;
		for (char ch : S) {
			dx += (ch == '(' ? 1 : -1);
			minx = min(minx, dx);
		}

		if (dx == 0) {
			if (minx >= 0) { assert(minx == 0); nclosed++; }
		} else if (dx > 0) {
			if (minx >= 0) { assert(minx == 0); nopen[dx]++; }
		} else {
			if (minx == dx) {
				nclose[-dx]++;
			}
		}
	}

	int r = nclosed / 2;
	for (int i = 0; i < sz; i++) r += min(nopen[i], nclose[i]);
	cout << r << endl;

	return 0;
}