#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007LL
#define PB push_back
#define INF 999999999999999LL
int main() {
	char a[8][8];
	for (ll r = 0; r < 8; r++) {
		for (ll c = 0; c < 8; c++) {
			cin >> a[r][c];
		}
	}
	ll bestwhite = INF;
	ll bestblack = INF;
	for (ll c = 0; c < 8; c++) {
		ll white = INF;
		for (ll r = 7; r >= 0; r--) {
			if (a[r][c] == 'W') {
				white = min(white, r);
			}
			else if (a[r][c] == 'B') {
				white = INF;
			}
		}
		bestwhite = min(bestwhite, white);
		ll black = INF;
		for (ll r = 0; r < 8; r++) {
			if (a[r][c] == 'B') {
				black = min(black, 7-r);
			}
			else if (a[r][c] == 'W') {
				black = INF;
			}
		}
		bestblack = min(bestblack, black);
		//cout << c << ":" << white << "," << black << endl;
	}
	//cout << bestwhite << "," << bestblack << endl;
	if (bestwhite <= bestblack) {
		cout << "A" << endl;
	}
	else {
		cout << "B" << endl;
	}
}