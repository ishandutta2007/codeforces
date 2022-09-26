#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int la, ra, ta; cin >> la >> ra >> ta;
	int lb, rb, tb; cin >> lb >> rb >> tb;
	int tg = __gcd(ta, tb);
	int dl = la % tg - lb % tg;
	if (dl < 0) dl += tg;
	int ans = 0;
	ans = max(ans, min(rb - lb + 1 - dl, ra - la + 1));
	ans = max(ans, min(rb - lb + 1, ra - la + 1 - (tg - dl)));
	int dr = ra % tg - rb % tg;
	if (dr < 0) dr += tg;
	ans = max(ans, min(rb - lb + 1, ra - la + 1 - (dr)));
	ans = max(ans, min(ra - la + 1, rb - lb + 1 - (tg - dr)));
	cout << ans << '\n';
}