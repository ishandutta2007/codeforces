#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

#ifdef LOCAL
#include <cassert>
#endif // LOCAL

using namespace std;

#define INF 2147483647
#define MOD 1000000007
#define MAX 100000

typedef long long ll;
typedef pair<int, int> pii;

ll n, k;
int inl, inm;

// ll mat[4][4] = { { 1, 1, 0, 0 }, { 1, 0, 0, 0 }, { 0, 0, 1, 1 }, { 0, 1, 1, 1 } };
ll mat[4][4] = {
	{ 1, 1, 0, 0 },
	{ 1, 0, 0, 1 } ,
	{ 0, 0, 1, 1 },
	{ 0, 0, 1, 1 }
};

int main()
{
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
#else
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#endif // LOCAL

	cin >> n >> k >> inl >> inm;

	if (log2(k) >= inl || inm == 1) {
		cout << 0 << endl;
		return 0;
	}

	ll e = n - 1, ret[4] = { 1, 1, 0, 0 };
	while (e) {

//		for (int i = 63; i >= 0; i--) {
//			cerr << ((e >> i) & 1);
//		}
//		cerr << ": " << endl;

		if (e & 1) {
			ll newret[4] = {};
			for (int l = 0; l < 4; l++) {
				for (int r = 0; r < 4; r++) {
					newret[r] += ret[l] * mat[l][r];
					newret[r] %= inm;
				}
			}
			for (int i = 0; i < 4; i++) {
				ret[i] = newret[i];
//				cerr << ret[i] << ", ";
			}
//			cerr << endl;
		}
		// multiply matrix
		ll newmat[4][4] = {};
		for (int l = 0; l < 4; l++) {
			for (int m = 0; m < 4; m++) {
				for (int r = 0; r < 4; r++) {
					newmat[l][r] += mat[l][m] * mat[m][r];
					newmat[l][r] %= inm;
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				mat[i][j] = newmat[i][j];
//				cerr << mat[i][j] << " ";
			}
//			cerr << endl;
		}
//		cerr << endl;
		e >>= 1;
	}

	ll iszero = ret[0] + ret[1];
	ll isone = ret[2] + ret[3];

//	 cout << iszero << " " << isone << endl;

	ll ans = 1;

	for (int i = 0; i < inl; i++, k >>= 1) {

//		cerr << i << ": " << (k & 1) << " " << ans << endl;

		ans *= (k & 1) ? isone : iszero;
		ans %= inm;
	}

	cout << ans << endl;

    return 0;
}