#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forab(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;
string s, t, a, b;
vi res;

bool ana (string a, string b) {
	sort(ALL(a)), sort(ALL(b));
	return a == b;
}

void shift (int x) {
	res.pb(x);
	for (int i = 0; i < x; i++)
		a[i] = s[n-i-1];
	for (int i = x; i < n; i++)
		a[i] = s[i-x];
	swap(a, s);
}

int f1 (int i) {
	int j = i;
	while (s[j] != t[i]) j++;
	shift(n-j);
	return j - i;
}

void f2 (int i) {
	shift(i);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> s >> t;

	if (!ana(s, t)) {
		cout << -1 << endl;
		return 0;
	}

	b.resize(n);
	int k = 0;
	for (int i = n-2; i >= 0; i -= 2)
		b[i] = t[k++];
	for (int i = 1 - n % 2; i < n; i += 2)
		b[i] = t[k++];
	swap(b, t);

	a.resize(n);
	for (int i = 0; i < n; i++) {
		int j = f1(i);
		f2(j);
		shift(n);
	}

	cout << res.size() << endl;
	for (int x : res)
		cout << x << " ";
	cout << endl;

	return 0;
}