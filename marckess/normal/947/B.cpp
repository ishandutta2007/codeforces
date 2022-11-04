#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005;

int n;
ll v[MX], t[MX];
ll acu[MX], res[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		t[i] += t[i-1];
	}

	for (int i = 1; i <= n; i++) {
		int a = i, b = n+1, rep = 20;

		while (rep--) {
			int m = (a+b)/2;
			
			if (t[m] - t[i-1] > v[i])
				b = m;
			else
				a = m;
		}

		acu[i]++;
		acu[b]--;
		res[b] += v[i] - (t[b-1] - t[i-1]);
	}

	for (int i = 1; i <= n; i++) {
		acu[i] += acu[i-1];

		cout << res[i] + (t[i] - t[i-1]) * acu[i] << " ";
	}
	cout << endl;

	return 0;
}