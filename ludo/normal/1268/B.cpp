#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int) (v).size())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

/*


v
v

*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	ll no = 0, ne = 0;
	REP(i, n) {
		int x;
		cin >> x;

		no += x/2;
		ne += x/2;
		if (x&1)  {
			if (i&1) no++;
			else ne++;
		}
	}
	cout << min(no, ne) << endl;

	return 0;
}