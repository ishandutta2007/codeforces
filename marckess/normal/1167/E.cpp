#include <bits/stdc++.h>

//#define endl '\n'
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

const int MX = 1000005;
int n, x, a[MX], ini[MX], fin[MX], in[MX];
ll res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (!ini[a[i]]) ini[a[i]] = i;
		fin[a[i]] = i;
		in[i] = x + 1;
	}

	in[n + 1] = x + 1;
	for (int i = x, act = n + 1; i > 0; i--) {
		in[act] = i;
		if (!ini[i]) continue;
		if (fin[i] > act) break;
		act = ini[i];
	}

	for (int i = n; i > 0; i--) 
		in[i] = min(in[i], in[i + 1]);

	for (int i = 1, act = 0; i <= x; i++) {
		res += x - max(in[act + 1], i) + 1;
		if (!ini[i]) continue;
		if (ini[i] < act) break;
		act = fin[i];
	}

	cout << res << endl;

	return 0;
}