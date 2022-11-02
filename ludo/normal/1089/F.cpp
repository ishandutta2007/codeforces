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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	vii pf; // prime factorization
	int fn = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			int e = 0;
			while (n % i == 0) e++, n /= i;
			pf.eb(i, e);
		}
	}
	if (n > 1) pf.eb(n, 1);
	n = fn;

	if (pf.size() == 1) {
		// prime power
		printf("NO\n");
		return 0;
	}

	int p = pf[0].x, q = pf.back().x;

	int k = 0, rem = n - 1;
	while (rem % p != 0) rem -= q, k++;

	int m = rem / p;

	assert(m * p + k * q == n - 1);

	assert(m > 0 && k > 0);

	printf("YES\n");
	printf("2\n%d %d\n%d %d\n", m, n / p, k, n / q);
	// for (ii pr : pf) cerr << pr.x << "^" << pr.y << endl;

	return 0;
}