#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

stack<ll> st[64], res;
int n;
ll a, s = 0;

void no () {
	cout << "No" << endl;
	exit(0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		s ^= a;
		
		int mx = 0;
		for (int j = 0; j < 60; j++)
			if (a & (1ll << j))
				mx = j;
		st[mx].push(a);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= 60; j++) {
			if (j == 60) no();
			if (s & (1ll << j) && st[j].size()) {
				s ^= st[j].top();
				res.push(st[j].top());
				st[j].pop();
				break;
			}
		}

	cout << "Yes" << endl;
	while (res.size()) {
		cout << res.top() << " ";
		res.pop();
	}
	cout << endl;

	return 0;
}