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
typedef pair<int, int> pii;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int n; char A[400010];

string fix(string x, char f) {
	sort(all(x));
	string a; a.resize(sz(x) + (f > 0));
	for(int i=0;i<sz(x);i++) {
		if(i % 2 == 0) a[i/2] = x[i];
		else a[sz(a)-1-i/2] = x[i];
	}
	if(f) a[sz(x)/2] = f;
	return a;
}

void solve() {
	scanf("%d%s", &n, A+1);
	int cnt[130] = {};
	for(int i=1;i<=n;i++) cnt[A[i]]++;
	for(int i=n;i;i--) if(n % i == 0) {
		int g = 0;
		if(i % 2) g = n / i;
		int c1 = 0;
		rep(i, 130) if(cnt[i] & 1) ++c1;
		if(c1 <= g) {
			printf("%d\n", n / i);
			rep(j, n/i) {
				string r;
				for(int k=0;k<i/2;k++) {
					rep(u, 130) if(cnt[u] >= 2) { cnt[u] -= 2, r.pb(u), r.pb(u); break; }
				}
				char g = 0;
				if(i & 1) {
					int f = 0;
					rep(u, 130) if(cnt[u] & 1) { cnt[u]--; g = u; f = 1; break; }
					if(f == 0) { rep(u, 130) if(cnt[u]) { cnt[u]--; g = u; break; } }
				}
				r = fix(r, g);
				printf("%s ", r.c_str());
			}
			puts("");
			break;
		}
	}
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}