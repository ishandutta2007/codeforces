#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2000005;
int n, b[MX];
ll sum;
multiset<ll> mst;

void solve () {
	sum = 0;
	mst.clear();
	
	cin >> n;
	n += 2;
	forn (i, n) {
		cin >> b[i];
		sum += b[i];
		mst.insert(b[i]);
	}
	
	forn (i, n) {
		ll acu = sum - b[i];
		mst.erase(mst.find(b[i]));
		
		if (mst.find(acu - b[i]) != mst.end()) {
			mst.erase(mst.find(acu - b[i]));
			for (int x : mst)
				cout << x << " ";
			cout << endl;
			return;
		}
		
		mst.insert(b[i]);
	}
	
	cout << -1 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}