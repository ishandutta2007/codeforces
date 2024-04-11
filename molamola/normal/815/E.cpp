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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pb(x) push_back(x)
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define Fi first
#define Se second

void Add(map <ll, ll> &M, pll t) {
	if(t.Fi > 1) {
		if(t.Fi / 2 == 2) M[1] += t.Se * 2;
		else M[t.Fi / 2] += t.Se;
	}
	if(t.Fi > 2) {
		if(t.Fi - 1 - t.Fi / 2 == 2) M[1] += t.Se * 2;
		else M[t.Fi - 1 - t.Fi / 2] += t.Se;
	}
}

ll get(ll X, ll x1, ll x2) {
	if(X == 0) return 0;
	if(X == x1 || X == x2) return 1;
	map <ll, ll> M;
	if(X == 2) M[1] += 2;
	else M[X]++;
	ll res = 0;
	while(1) {
		if(sz(M) == 0) break;
		if(sz(M) > 1) {
			auto it = --M.end();
			pll a = *it;
			auto jt = it; --jt;
			pll b = *jt;
			if(abs(a.Fi - b.Fi) == 1 && (a.Fi ^ b.Fi) != 1) {
				if(it->Fi == x1 || it->Fi == x2) res += it->Se;
				if(jt->Fi == x1 || jt->Fi == x2) res += jt->Se;
				M.erase(it);
				M.erase(jt);
				Add(M, a);
				Add(M, b);
				continue;
			}
		}
		auto it = --M.end();
		if(it->Fi == x1 || it->Fi == x2) res += it->Se;
		M.erase(it);
		pll t = *it;
		Add(M, t);
	}
	return res;
}

ll Do(ll l, ll r, ll x1, ll x2, ll y1) {
	if(r-l+1 == x1 || r-l+1 == x2) return (l+r) >> 1;
	if(r-l+1 == 2) {
		return l + y1 - 1;
	}
	ll m = (l + r) >> 1;
	ll a = get(m - l, x1, x2);
	if(a >= y1) return Do(l, m-1, x1, x2, y1);
	else return Do(m+1, r, x1, x2, y1 - a);
}

void solve() {
	ll n, k; scanf("%lld%lld", &n, &k);
	if(k == 1) printf("%d\n", 1);
	else if(k == 2) printf("%lld\n", n);
	else if(n <= 4) {
		int q[4][4] = {
			{1},{1,2},{1,3,2},{1,4,2,3}
		};
		printf("%d\n", q[n-1][k-1]);
	}
	else {
		map <ll, ll> M;
		M[n-2] = 1;
		ll nk = k - 2;
		ll x1 = -1, x2 = -1, y1 = -1;
		while(1) {
			if(sz(M) > 1) {
				auto it = --M.end();
				pll a = *it;
				auto jt = it; --jt;
				pll b = *jt;
				if(abs(a.Fi - b.Fi) == 1 && (a.Fi ^ b.Fi) != 1) {
					ll c = a.Se + b.Se;
					if(nk <= c) {
						x1 = a.Fi, x2 = b.Fi;
						y1 = nk;
						break;
					}
					else {
						M.erase(it);
						M.erase(jt);
						nk -= c;
						Add(M, a);
						Add(M, b);
						continue;
					}
				}
			}
			if(nk <= M.rbegin()->Se) {
				x1 = M.rbegin()->Fi;
				y1 = nk;
				break;
			}
			else {
				nk -= M.rbegin()->Se;
				pll t = *M.rbegin();
				M.erase(--M.end());
				Add(M, t);
			}
		}
		
//		printf("%lld %lld %lld\n", x1, x2, y1);
		
		printf("%lld\n", Do(2, n - 1, x1, x2, y1));
	}
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++) {
	//	printf("Case #%d\n", tc);
		solve();
	}
	return 0;
};