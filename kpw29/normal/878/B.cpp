#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)

vector <pll> Vu;
int main() {
	int N, K, M, i, j;
	scanf("%d %d %d", &N, &K, &M);
	for (i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		if (!Vu.empty() && Vu.back().first == t) {
			Vu.back().second++;
			if (Vu.back().second == K) Vu.pop_back();
		}
		else Vu.emplace_back(t, 1);
	}

	ll s = 0;
	for (auto it : Vu) s += it.second;
	if (M == 1 || s == 0) return !printf("%lld\n", s);

	s *= M;
	int st = 0, en = (int)Vu.size() - 1;
	while (st < en) {
		if (Vu[st].first != Vu[en].first) return !printf("%lld\n", s);
		if (Vu[st].second + Vu[en].second == K) {
			s -= (ll)(M - 1) * K;
			st++, en--;
			continue;
		}
		if (Vu[st].second + Vu[en].second > K) s -= (ll)(M - 1)*K;
		return !printf("%lld\n", s);
	}
	if (st > en) return !printf("0\n");
	if (st == en) {
		ll x = Vu[st].second * M;
		if (x % K == 0) return !printf("0\n");
		else return !printf("%lld\n", s - (x / K)*K);
	}
	return 0;
}