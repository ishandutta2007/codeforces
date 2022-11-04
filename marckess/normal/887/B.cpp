#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int mv[] = {0, 1, 2}, n;
	int c[10][10];

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++)
			cin >> c[i][j];
	}

	bitset<1005> bs;

	do {
		for (int i = 0; i < 6; i++) {
			bs[c[mv[0]][i]] = 1;
			if (n > 1) {
				for (int j = 0; j < 6; j++) {
					bs[c[mv[0]][i]+c[mv[1]][j]*10] = 1;
					if (n > 2) {
						for (int k = 0; k < 6; k++) {
							bs[c[mv[0]][i]+c[mv[1]][j]*10+c[mv[2]][k]*100] = 1;
						}
					}
				}
			}	
		}
	} while (next_permutation(mv, mv+n));

	int res = 0;

	while (bs[res+1])
		res++;

	cout << res << endl;

	return 0;
}