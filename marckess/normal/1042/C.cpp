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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX];
vi pos, neg, cer;

bool comp (int i, int j) {
	return abs(a[i]) < abs(a[j]);
}

void p (int i, int j) {
	cout << "1 " << i << " " << j << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];

		if (!a[i]) cer.pb(i);
		else if (a[i] > 0) pos.pb(i);
		else neg.pb(i);
	}

	sort(ALL(pos), comp);
	sort(ALL(neg), comp);

	int act = -1;

	if (pos.size() || neg.size() > 1) {
		if (cer.size()) {
			act = cer[0];
			for (int i = 1; i < cer.size(); i++)
				p(cer[i], act);
		}

		if (neg.size() % 2) if (act != -1) p(neg[0], act);
		else act = neg[0];

		if (act != -1) cout << "2 " << act << endl;

		if (pos.size()) {
			act = pos[0];
			for (int i = neg.size() % 2; i < neg.size(); i++)
				p(neg[i], act);

			for (int i = 1; i < pos.size(); i++)
				p(pos[i], act);
		} else {
			act = neg[neg.size()%2];
			for (int i = neg.size()%2+1; i < neg.size(); i++)
				p(neg[i], act);
		}

	} else {
		act = cer[0];
		for (int i = 1; i < cer.size(); i++)
			p(cer[i], act);
		for (int i = 0; i < neg.size(); i++)
			p(neg[i], act);
	}

	return 0;
}