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

int t;
string s;
int a = 0, b = 0, c = 0;
char mv[] = {'A', 'a', '1'};

void update (char h, int k) {
	if ('a' <= h && h <= 'z') a+=k;
	else if ('A' <= h && h <= 'Z') b+=k;
	else c+=k;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> t;
	while (t--) {
		cin >> s;

		a = 0, b = 0, c = 0;

		for (char h : s) update(h, 1);

		if (a && b && c) {
			cout << s << endl;
			continue;
		}

		if (min(1, a) + min(1, b) + min(1, c) == 1) {
			update(s[0], -1);
			update(s[1], -1);

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++) {
					update(mv[i], 1);
					update(mv[j], 1);

					if (a && b && c) {
						s[0] = mv[i], s[1] = mv[j];
						cout << s << endl;
						goto fin;
					}

					update(mv[i], -1);
					update(mv[j], -1);
				}
		}

		for (int i = 0; i < s.size(); i++) {
			char h = s[i];
			update(h, -1);

			for (int j = 0; j < 3; j++) {
				update(mv[j], 1);

				if (a && b && c) {
					s[i] = mv[j];
					cout << s << endl;
					goto fin;
				}

				update(mv[j], -1);
			}

			update(h, 1);
		}

		fin:;
	}

	return 0;
}