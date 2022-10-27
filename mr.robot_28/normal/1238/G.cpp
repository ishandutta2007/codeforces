#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define forn(i, n) for (int i = 0; i < int(n); ++i)

typedef long long li;
typedef pair<int, int> pt;

const int N = 500 * 1000 + 13;

int n, m, c, c0;
pair<int, pt> a[N];

li solve() {
	scanf("%d%d%d%d", &n, &m, &c, &c0);
	forn(i, n) scanf("%d%d%d", &a[i].x, &a[i].y.x, &a[i].y.y);
	a[n++] = mp(m, mp(0, 0));
	sort(a, a + n);

	int sum = c0;
	map<int, int> q;
	q[0] = c0;
	
	li ans = 0;
	forn(i, n) {
		int x = a[i].x;
		int cnt = a[i].y.x;
		int cost = a[i].y.y;
	
		int dist = x - (i ? a[i - 1].x : 0);
		while (!q.empty() && dist > 0) {
			int can = min(q.begin()->y, dist);
			ans += q.begin()->x * 1ll * can;
			sum -= can;
			dist -= can;
			q.begin()->y -= can;
			if (q.begin()->y == 0) q.erase(q.begin());
		}
		
		if (dist > 0) 
			return -1;
		
		int add = min(c - sum, cnt);
		sum += add;
		
		while (add < cnt && !q.empty() && q.rbegin()->x > cost) {
			if (cnt - add >= q.rbegin()->y) {
				add += q.rbegin()->y;
				q.erase(--q.end());
			} else {
				q.rbegin()->y -= cnt - add;
				add = cnt;
			}
		}
		
		q[cost] += add;
	}
	
	return ans;
}

int main() {
	int q;
	scanf("%d", &q);
	forn(i, q) printf("%lld\n", solve());
}