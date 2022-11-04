#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, x[MX], y[MX];
multiset<int> mst;

void main_() {
	cin >> n;
	forn (i, n) cin >> x[i];
	forn (i, n) cin >> y[i];
	
	mst.clear();
	forn (i, n) mst.insert(y[i] - x[i]);
	
	int res = 0;
	while (mst.size()) {
		int x = *mst.rbegin();
		mst.erase(mst.find(x));
		
		auto it = mst.lower_bound(-x);
		if (it != mst.end()) {
			res++;
			mst.erase(it);
		}
	}
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}