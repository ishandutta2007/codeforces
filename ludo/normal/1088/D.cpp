#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

#define cin haha
#define cout oheoh

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int sgn(int x) { return (x > 0) - (x < 0); }

bool swapab = false;

int query(int c, int d)
{
	int mult = 1;
	if (swapab) swap(c, d), mult = -1;

	printf("? %d %d\n", c, d);
	fflush(stdout);

#ifdef DEBUG
	int a = 948742, b= a;
	// int a = 0b011101, b = 0b100010;
	// int a = 9, b = 9 + 4;
	// int a = 3, b = 1;

	int X = (a ^ c) - (b ^ d);
	cerr << sgn(X) << endl;
	return mult * sgn(X);
#endif

	int r;
	scanf("%d", &r);
	return mult * r;
}

void report(int a, int b)
{
	if (swapab) swap(a, b);

	printf("! %d %d\n", a, b);
	fflush(stdout);
	exit(0);
}

int main()
{
	int ans = query(0, 0);

	int diff = 0;
	if (ans > 0) swapab = true, ans = -ans;

	if (ans < 0) {
		int ca = 0, cb = 0;
		// a < b
		for (int i = 29; i >= 0; i--) {
			int r = query(ca | (1<<i), cb | (1<<i));
			if (r > 0) {
				// 0.. VS 1..
				cb |= 1<<i;
				if (query(ca, cb) > 0) {
					swapab = !swapab;
					swap(ca, cb);
				}
			} else {
				if (query(ca | (1<<i), cb) < 0) {
					ca |= 1<<i;
					cb |= 1<<i;
				}
			}
		}
		report(ca, cb);
	} else {
		int c = 0;
		for (int i = 29; i >= 0; i--) {
			int r = query(c | (1<<i), c);
			if (r < 0) c |= 1<<i;
		}
		report(c, c);
	}

	cerr << "a and b differ by " << diff << endl;


	report(0, diff);
	return 0;
}