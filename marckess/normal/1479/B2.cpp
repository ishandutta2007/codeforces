#include <bits/stdc++.h>

//#define endl '\n'
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

const int MX = 100005;
int n, a[MX], bs[MX], dp[MX], ex[MX];
multiset<int> mst;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	mst.insert(0);
	
	for (int i = n - 1, off = 0; i >= 0; i--) {
		if (ex[a[i]] && *mst.rbegin() == bs[a[i]]) {
			auto it = mst.end();
			it--; it--;
			dp[i] = max(*it, *mst.rbegin() + 1);
		} else {
			dp[i] = *mst.rbegin();
		}
		dp[i] += off;
		
		off += a[i] == a[i + 1];
		
		if (ex[a[i + 1]]) {
			mst.erase(mst.find(bs[a[i + 1]]));
			bs[a[i + 1]] = max(bs[a[i + 1]], dp[i] - off);
		} else {
			bs[a[i + 1]] = dp[i] - off;
		}
		ex[a[i + 1]] = 1;
		mst.insert(bs[a[i + 1]]);
	}
	
	cout << n - dp[0] << endl;
	
	return 0;
}