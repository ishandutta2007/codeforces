#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;

int n, l[1010], r[1010], chk[1010];

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", l+i);
	for(int i=1;i<=n;i++) scanf("%d", r+i);
	int cnt = 0, now = n, ans[1010];
	while(1) {
		vector <int> f;
		for(int i=1;i<=n;i++) if(chk[i] == 0 && l[i] + r[i] == 0) {
			f.pb(i);
		}
		if(szz(f) == 0) {
			if(cnt < n) {
				puts("NO");
				return 0;
			}
			break;
		}
		for(int e : f) ans[e] = now, chk[e] = 1;
		for(int e : f) {
			for(int j=1;j<e;j++) if(!chk[j]) {
				r[j]--;
				if(r[j] < 0) { puts("NO"); return 0; }
			}
			for(int j=e+1;j<=n;j++) if(!chk[j]) {
				l[j]--;
				if(l[j] < 0) { puts("NO"); return 0; }
			}
		}
		--now;
		cnt += szz(f);
	}
	puts("YES");
	for(int i=1;i<=n;i++) printf("%d ", ans[i]); puts("");
	return 0;
}