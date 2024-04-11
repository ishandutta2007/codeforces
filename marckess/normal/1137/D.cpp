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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

void query (vi a) {
	assert(!a.empty());
	cout << "next";
	for (int x : a) cout << " " << x;
	cout << endl;
}

vvi read () {
	string r;
	vvi res;

	cin >> r;
	if (r == "stop") exit(0);

	int k = stoi(r);
	while (k--) {
		vi a;
		cin >> r;
		for (char c : r)
			a.pb(c-'0');
		res.pb(a);
	}

	return res;
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);

	while (1) {
		query({1, 2});
		read();
		query({1});
		if (read().size() == 2) break;
	}

	while (1) {
		query({1, 2, 3, 4, 5, 6, 7, 8, 9, 0});
		if (read().size() == 1) break;
	}

	cout << "done" << endl; 

	return 0;
}