#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) emplace_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
 
const int MX = 200005;
int n, a[MX], b[MX], res;
queue<int> q;
set<int> st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		st.insert(a[i]);
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		q.push(b[i]);
		if (b[i]) res = max(res, n + max(0, i - (b[i] - 1) + 1));
	}

	int f = 1;
	if (b[n - 1] != 1) { 
		for (int i = n - 2; i >= 0; i--) {
			if (!b[i]) {
				f = 0; 
				break;
			}
			if (b[i + 1] != b[i] + 1) {
				f = 0;
				break;
			}
			if (b[i] == 1) {
				break;
			}
		}
	}
	st.erase(0);

	int ned = b[n-1] + 1, aux = 0;
	if (st.size() == n) {
		ned = 1;
		res = 1e9;
		f = 1;
	}

	while (ned <= n) {
		if (!st.count(ned)) {
			aux = 1e9;
			break;
		}
		q.push(ned);
		ned++;
		st.insert(q.front());
		q.pop();
		aux++;
	}
	if (!f) aux = 1e9;

	cout << min(res, aux) << endl;
 
	return 0;
}