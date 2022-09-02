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
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int n, p, q, r;
int A[500050], B[500050], C[500050];
vector <t3> E;

void solve(){
	scanf("%d%d%d%d", &n, &p, &q, &r);
	for(int i=1;i<=n;i++) scanf("%d%d%d", A+i, B+i, C+i), C[i] = r - C[i];
	for(int i=1;i<=n;i++) {
		E.emplace_back(1, A[i], B[i]);
		E.emplace_back(C[i] + 1, p, B[i]);
		E.emplace_back(C[i] + 1, A[i], q);
	}
	sort(all(E));
	map <int, int> M;
	ll now = 0, ans = 0;
	M[0] = q + 1;
	M[p + 1] = 0;
	for(int i=0;i<sz(E);i++) {
		int x = get<1>(E[i]), y = get<2>(E[i]);
		auto it = M.lower_bound(x);
		if(it->Se < y) {
			while(it->Se <= y) {
				int u = min(x, it->Fi);
				auto jt = it; --jt;
				int l = jt->Fi;
				now += (u - l) * (ll)(y - it->Se);
				if(it->Fi <= x) M.erase(it);
				it = jt;
			}
			M[x] = y;
		}
		ans += now * (ll)((i == sz(E) - 1 ? r + 1: get<0>(E[i + 1])) - get<0>(E[i]));
	}
	printf("%lld\n", (ll)p * q * r - ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
};