#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 105;
int n, m, r = 0;
char a[MX][MX];
bitset<MX> bs;
stack<int> st;

void del (int j) {
	if (j) {
		for (int i = 0; i < n; i++)
			a[i][j] = a[i][j-1];
	}
	r++;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	bs.set();

	for (int j = 0; j < m; j++) {
		bool f = 0;
		stack<int> st;

		for (int i = 1; i < n; i++) {
			if (bs[i]) {
				if (a[i-1][j] > a[i][j]) {
					del(j);
					f = 1;
					break;
				}
				if (a[i-1][j] < a[i][j]) {
					st.push(i);
				}
			}
		}

		if (!f) {
			while (st.size()) {
				bs[st.top()] = 0;
				st.pop();
			}
		}
	}

	cout << r << endl;

	return 0;
}