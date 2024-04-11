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

// const int maxn = 5;
const int maxn = 30;

string wewant;
int nth = 0;

bool getcol(int x, int y)
{
	string col;
	++y;
	printf("%d %d\n", x, y);
	fflush(stdout);
	cin >> col;

	if (nth++ == 0) {
		wewant = col;
		// cerr << "WE WANT \"" << wewant  << "\"" << endl;
		return true;
	} else {
		return col == wewant;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N;
	cin >> N;

	getcol(0, 0);
	// start color

	int inc = 1 << (maxn - 3);
	int lo = 0;
	int hi = 1 << (maxn - 2);
	while (nth < N && getcol(hi, 0)) {
		lo = hi;
		hi += inc;
		inc >>= 1;

		if (nth == N) hi++;
	}

	while (nth < N) {
		int mi = (lo + hi) / 2;
		if (getcol(mi, 0))
			lo = mi;
		else hi = mi;
	}

	printf("%d %d %d %d\n", lo, 2, hi, 0);

	return 0;
}