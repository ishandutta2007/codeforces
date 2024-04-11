#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	string s; cin >> s;
	string p; cin >> p;

	int ns = (int)s.length();
	int np = (int)p.length();

	vector<int> P(ns);

	for (int i = 0; i < ns; ++i){
		cin >> P[i];
		P[i]--;
	}

	int lo = 0, hi = ns;

	while (lo + 1 < hi){
		int m = (lo + hi) / 2;
		vector<bool> dead( ns );

		for (int i = 0; i < m; ++i)
			dead[ P[i] ] = true;

		bool ok = true;

		for (int i = 0, pos = 0; i < np; ++i){
			while (pos < ns && (dead[pos] || s[pos] != p[i]))
				pos++;

			if (pos == ns){
				ok = false;
				break;
			}
			else pos++;
		}

		if (ok) lo = m;
		else hi = m;
	}

	cout << lo << endl;

	return 0;
}