#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 5005;
int n, bs[MX], x[MX];
ll res;
vi p, cn, st;
stack<ii> a[MX];

void pre () {
	for (int i = 2; i < MX; i++) 
		if (!bs[i]) {
			p.pb(i);
			for (int j = i * i; j < MX; j += i)
				bs[j] = 1;
		}
}

int count (int n, int p) {
	int res = 0, x = p;
	while (x <= n) {
		res += n / x;
		x *= p;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(); cin.tie(0);
	pre();

	cin >> n;
	for (int i = 0; i < n; i++)	{
		int k;
		cin >> k;
		k = max(k, 1);
		x[k]++;
		st.pb(k);
	}

	sort(all(st));
	st.erase(unique(all(st)), st.end());

	for (int i = 0; i < st.size(); i++) {
		cn.pb(x[st[i]]);
		for (int j = 0; j < p.size() && p[j] <= st[i]; j++) {
			a[i].emplace(p[j], count(st[i], p[j]));
			res += 1ll * cn.back() * count(st[i], p[j]);
		}
	}

	int i = st[0] == 1, j = int(st.size()) - 1;
	while (i <= j) {
		ll dif = 0;
		int ini, fin;

		for (int k = i; k <= j;) {
			int s = 0, act = k;
			
			while (k <= j && a[k].top().fi == a[act].top().fi) {
				s += cn[k];
				k++;
			}

			if (1ll * a[act].top().se * (s - (n - s)) > dif) {
				dif = 1ll * a[act].top().se * (s - (n - s));
				ini = act;
				fin = k - 1;
			}
		}

		if (dif == 0) break;

		int pw = a[ini].top().se;
		i = ini, j = fin;
		while (ini <= fin) {
			if (a[ini].top().se == pw) a[ini].pop();
			else a[ini].top().se -= pw;
			if (a[ini].empty()) i++;
			ini++;
		}

		res -= dif;
	}

	cout << res << endl;

	return 0;
}