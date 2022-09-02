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

int N;
char buf[20];
set <int> B, S, Q;
const int INF = 1e9;

inline int get_b() { return szz(B) ? *B.rbegin() : -INF; }
inline int get_s() { return szz(S) ? *S.begin() : INF; }

int main() {
	scanf("%d", &N);
	ll ans = 1;
	const int MOD = 1e9 + 7;
	rep(a,N) {
		scanf("%s", buf);
		int x; scanf("%d", &x);
		if(buf[1] == 'D') {
			int bv = get_b();
			int sv = get_s();
			if(bv < x && x < sv) Q.insert(x);
			else if(x < bv) B.insert(x);
			else S.insert(x);
		}
		else {
			if(B.find(x) != B.end()) {
				if(get_b() != x) ans = 0;
				B.erase(x);
				for(int e : Q) S.insert(e);
				Q.clear();
			}
			else if(S.find(x) != S.end()) {
				if(get_s() != x) ans = 0;
				S.erase(x);
				for(int e : Q) B.insert(e);
				Q.clear();
			}
			else {
				ans = (ans * 2) % MOD;
				for(int e : Q) {
					if(e < x) B.insert(e);
					else if(e > x) S.insert(e);
				}
				Q.clear();
			}
		}
	}
	ans = ans * (int)(Q.size() + 1) % MOD;
	printf("%lld\n", ans);
	return 0;
}