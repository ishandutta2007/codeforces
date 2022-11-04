#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, a[MX], b[MX];
ll res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = n-1; i >= 0; i--)
		b[i] = max(a[i]+1, b[i+1]-1);

	for (int i = 1; i < n; i++)
		b[i] = max(b[i], b[i-1]);

	for (int i = 0; i < n; i++)
		res += b[i] - 1 - a[i];

	cout << res << endl;

	return 0;
}