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

	int N;
	string S;
	cin >> N >> S;

	int nl = 0, nr = 0, nu = 0, nd = 0;
	for (char ch : S) {
		if (ch == 'L') nl++;
		if (ch == 'R') nr++;

		if (ch == 'U') nu++;
		if (ch == 'D') nd++;
	}
	
	int ans = min(nl, nr) + min(nu, nd);
	cout << (2 * ans) << endl;


	return 0;
}