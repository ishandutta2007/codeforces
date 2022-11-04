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

const int MX = 300005;

int n, m;
int bs[MX];
int x, g = 0, acu = 0;
char c;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c;
		bs[i] = int(c == '.');
	}

	bool f = 0;
	for (int i = 1; i <= n; i++) {
		if (bs[i]) {
			f = 1;
			acu++;
		} else {
			if (f)
				g++;
			f = 0;
		}
	}
	if (f)
		g++;

	bs[0] = bs[n+1] = -1;

	while (m--) {
		cin >> x >> c;

		if (c == '.' && !bs[x]) {
			bs[x] = 1;
			acu++;

			if (bs[x-1] == 1 && bs[x+1] == 1)
				g--;

			if (bs[x-1] != 1 && bs[x+1] != 1)
				g++; 
		}

		if (c != '.' && bs[x]) {
			bs[x] = 0;
			acu--;

			if (bs[x-1] == 1 && bs[x+1] == 1)
				g++;

			if (bs[x-1] != 1 && bs[x+1] != 1)
				g--;
		}

		cout << acu - g << endl;
	}

	return 0;
}