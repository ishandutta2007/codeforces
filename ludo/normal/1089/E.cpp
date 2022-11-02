#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

bool fstpr = true;

void prt(int a, int b) {
	if (fstpr) fstpr = false;
	else printf(" ");

	printf("%c%d", ('a' + a), b + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	// do the first (n - n%8) cells, by filling each row completely
	// last row, only n%8 cells to be filled in.

	int q = n / 8, r = n % 8;

	int a = 0, b = 0;
	for (int i = 0; i < q; i++) {
		int lv = (i + 1 == q && r == 0) ? 7 : (b == 6 ? 5 : 6);

		prt(a, b);
		for (int j = 0; j < 8; j++) {
			if (j != b && j != lv) prt(a, j);
		}

		b = lv;
		prt(a, b);
		a++;
	}

	if (q == 0) {
		prt(0, 0);
		r--;
	}

	if (r > 0) {
		prt(7, b);
		r--;
		for(int j = 0; j < 7 && r; j++) {
			if (j != b) {
				prt(7, j);
				r--;
			}
		}
	}
	prt(7,7);

	printf("\n");
	return 0;
}