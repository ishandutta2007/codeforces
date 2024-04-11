#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {

	int n, k, a, b, q;

	scanf("%d %d %d %d %d", &n, &k, &a, &b, &q);

	vec< ll > sa(n + 1), sb(n + 1);
	vec< int > marka(n + 1), markb(n + 1);

	for(int ty, d, p, c;q;q--) {
		scanf("%d", &ty);
		if(ty == 1) {
			scanf("%d %d", &d, &c);
			int delt;

			// a

			delt = min(c, a - marka[d]);

			marka[d] += delt;
			for(int cur = d;cur <= n;cur |= (cur + 1)) sa[cur] += delt;

			// b

			delt = min(c, b - markb[d]);

			markb[d] += delt;
			for(int cur = d;cur <= n;cur |= (cur + 1)) sb[cur] += delt;
		}else {
			scanf("%d", &p);
			// [p .. p + k - 1]

			ll ans = 0;

			// b [1 .. p - 1]

			for(int cur = p - 1;cur > 0;cur = (cur & (cur + 1)) - 1) ans += sb[cur];

			// a [p + k .. n]

			if(p + k <= n) {
				for(int cur = n;cur > 0;cur = (cur & (cur + 1)) - 1) ans += sa[cur];
				for(int cur = p + k - 1;cur > 0;cur = (cur & (cur + 1)) - 1) ans -= sa[cur];
			}

			printf("%d\n", (int)ans);
		}

		/*cout << "\na : ";
		for(int i = 1;i <= n;i++) cout << marka[i] << " ";
		cout << "\nb : ";
		for(int i = 1;i <= n;i++) cout << markb[i] << " ";
		cout << "\n\n";*/
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}