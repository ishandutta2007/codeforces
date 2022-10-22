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

int n, l, r, m, sz;
vec< int > a, crd; 

int bp(int x) {
	l = 0, r = sz - 1;
	while(r - l > 1) {
		m = (l + r) / 2;
		if(crd[m] >= x) r = m;
		else l = m + 1;
	}
	if(crd[l] == x) return l;
	else if(crd[r] == x) return r;
	else return -1;
}

bool solve() {

	scanf("%d", &n);

	a.resize(n);

	for(int i = 0;i < n;i++) {
		scanf("%d", &a[i]);
		crd.push_back(a[i]);
	}

	sort(ALL(crd));
	crd.resize(unique(ALL(crd)) - crd.begin());
	sz = (int)crd.size();

	vec< int > cnt(sz), pos(n);
	for(int j = 0;j < n;j++) {
		pos[j] = bp(a[j]);
		cnt[pos[j]]++;
	}
	
	int ans = 0;

	vec< int > T(100000);

	for(int i = 0;i < n;i++) {
		int x, y, curx, cury, len;
		for(int j = 0;j < n;j++) {
			if(i == j) continue;
			len = 0;
			x = a[i];
			y = a[j];
			if(x == 0 && y == 0) {
				ans = max(ans, cnt[bp(0)]);
				continue;
			}
			curx = pos[i];
			cury = pos[j];
			cnt[curx]--;
			cnt[cury]--;
			T[len++] = curx;
			T[len++] = cury;
			for(int z, cur;;) {
				z = x + y;
				if(abs(z) > inf) break;
				cur = bp(z);
				if(cur == -1) break;
				if(cnt[cur] == 0) break;
				cnt[cur]--;
				x = y;
				y = z;
				T[len++] = cur;
			}
			ans = max(ans, len);
			for(int cur = 0;cur < len;cur++) cnt[T[cur]]++;
		}
	}

	cout << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}