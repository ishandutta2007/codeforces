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

ll sqr(int x) {
	return 1ll * x * x;
}

ll ans = inf64;
int n;
vec< pii > a;
vec< int > prmn, sfmn, prmx, sfmx;

bool check(ll d) {
	for(int i = 0, j = 0;i < n;i++) {
		j = max(j, i);
		while(j + 1 < n && sqr(a[j + 1].first - a[i].first) <= d) j++;
		int mn, mx;
		mn = +inf;
		mx = -inf;
		if(i == 0 && j == n - 1) return 1;
		if(i > 0) mn = min(mn, prmn[i - 1]), mx = max(mx, prmx[i - 1]);
		if(j + 1 < n) mn = min(mn, sfmn[j + 1]), mx = max(mx, sfmx[j + 1]);
		ll tmp = 0;
		tmp = max(tmp, sqr(mx - mn));
		if(abs(mx) < abs(mn)) swap(mx, mn);
		tmp = max(tmp, sqr(mx) + sqr(a[i].first));
		tmp = max(tmp, sqr(mx) + sqr(a[j].first));
		if(tmp <= d) return 1;
	}
	return 0;
}

bool solve() {
	
	scanf("%d", &n);
	
	a.resize(n);
	
	for(int i = 0;i < n;i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}
	
	for(int it2 = 0;it2 < 2;it2++) {
		for(int it = 0;it < 2;it++) {
			sort(ALL(a));
	
			prmn.clear();
			prmx.clear();
			sfmn.clear();
			sfmx.clear();

			prmn = sfmn = vec< int >(n, +inf);
			prmx = sfmx = vec< int >(n, -inf);
	
			for(int T1 = +inf, T2 = -inf, i = 0;i < n;i++) {
				T1 = min(T1, a[i].second);
				T2 = max(T2, a[i].second);
				prmn[i] = T1;
				prmx[i] = T2;
			}

			for(int T1 = +inf, T2 = -inf, i = n - 1;i >= 0;i--) {
				T1 = min(T1, a[i].second);
				T2 = max(T2, a[i].second);
				sfmn[i] = T1;
				sfmx[i] = T2;
			}

			int mn, mx;

			mn = +inf;
			mx = -inf;

			for(int i = 0;i < n;i++) {
				mn = min(mn, a[i].first);
				mx = max(mx, a[i].first);
			}

			ans = min(ans, sqr(mx - mn));

			mn = +inf;
			mx = -inf;

			for(int i = 0;i < n;i++) {
				mn = min(mn, a[i].second);
				mx = max(mx, a[i].second);
			}

			ans = min(ans, sqr(mx - mn));

			ll bl, br, bm;

			bl = 0, br = inf64;

			while(br - bl > 1) {
				bm = (bl + br) / 2;
				if(check(bm)) br = bm;
				else bl = bm + 1;
			}

			if(check(bl)) ans = min(ans, bl);
			else ans = min(ans, br);
		
			for(int i = 0;i < n;i++) a[i].first *= -1;
		}

		for(int i = 0;i < n;i++) {
			swap(a[i].first, a[i].second);
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