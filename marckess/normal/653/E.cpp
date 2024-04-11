#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const string yes = "possible";
const string no = "impossible";
const int MX = 300005;
int n, m, k, p[MX];
set<int> st[MX], ex;

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	p[parent(a)] = parent(b);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;
	forn (i, m) {
		int a, b;
		cin >> a >> b;
		if (b > 1) st[a].insert(b);
		if (a > 1) st[b].insert(a);
	}

	iota(p, p+MX, 0);
	forn(i, n) ex.insert(i + 1);
	ex.erase(1); 

	for (int i = 2; i <= n; i++)
		if (ex.count(i)) {
			queue<int> p;
			ex.erase(i);

			auto it = ex.begin();

			while (it != ex.end()) {
				int x = *it;

				if (!st[i].count(x)) {
					p.push(x);
					join(i, x);

					auto aux = it;
					it++;
					ex.erase(*aux);
				} else {
					it++;
				}
			}

			while (p.size()) {
				int j = p.front();
				p.pop();
				it = st[i].begin();

				for (int x : st[j]) {
					while (it != st[i].end() && *it < x) {
						if (ex.count(*it)) p.push(*it);
						join(i, *it);
						ex.erase(*it);

						auto aux = it;
						it++;
						st[i].erase(aux);
					}

					if (it != st[i].end() && *it == x) it++;
				}

				while (it != st[i].end()) {
					if (ex.count(*it)) p.push(*it);
					join(i, *it);
					ex.erase(*it);

					auto aux = it;
					it++;
					st[i].erase(*aux);
				}
			}
		}

	int ned = 0, op = 0;
	for (int i = 2; i <= n; i++)
		if (!st[1].count(i))
			if (parent(1) != parent(i)) {
				join(1, i);
				ned++;
			} else {
				op++;
			}

	if (ned <= k && k <= ned + op) {
		for (int i = 2; i <= n; i++)
			if (parent(1) != parent(i)) {
				cout << no << endl;
				return 0;
			}
		cout << yes << endl;
	} else {
		cout << no << endl;
	}

	return 0;
}