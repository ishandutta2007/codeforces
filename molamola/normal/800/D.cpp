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
typedef pair<int, int> Pi;
typedef long long ll;
#define pii Pi
#define pll PL
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef tuple<int, int, int, int> t4;
typedef pair<ll, ll> PL;
typedef long double ldouble;

const int MOD = 1e9 + 7;
int pw[7];
int n;
int C[1000010];

ll G[1000010];
ll pw2[1000010];

struct str{
	str(){}
	str(int a, int b, int c){}
	int a, b, c;
	void update(int x){
		c = (c + (ll)x * x) % MOD;
		b = (b + x) % MOD;
		a = (a + 1) % MOD;
	}
	inline void add(str &R){
		a = (a + R.a); if(a >= MOD)a -= MOD;
		b = (b + R.b); if(b >= MOD)b -= MOD;
		c = (c + R.c); if(c >= MOD)c -= MOD;
	}
	inline void sub(str &R){
		a = (a - R.a); if(a < 0)a += MOD;
		b = (b - R.b); if(b < 0)b += MOD;
		c = (c - R.c); if(c < 0)c += MOD;
	}
	inline int make(){
		if(a == 0)return 0;
		if(a == 1)return c;
		ll temp = pw2[a - 2];
		return temp * ((ll)b * b % MOD + c) % MOD;
	}
} D[1000010];

vector <int> add;
vector <int> sub;

int F[1000010];

inline int valid(int *a, int e){
	for(int j=0;j<6;j++){
		int t = e % 10;
		if(t + a[j] == 10)return 0;
		e /= 10;
	}
	return 1;
}

void solve(){
	pw2[0] = pw[0] = 1;
	for(int i=1;i<7;i++)pw[i] = 10 * pw[i-1];
	for(int i=1;i<1000000;i++)pw2[i] = pw2[i-1] * 2 % MOD;
	rep(i, 64)if(i){
		int t = 0;
		rep(j, 6)if(1<<j & i)t += pw[j];
		if(__builtin_popcount(i) & 1)add.pb(t);
		else sub.pb(t);
	}
	scanf("%d", &n);
	rep(i, n){
		int x; scanf("%d", &x);
		C[x]++;
	}
	for(int i=999999;i>=0;i--){
		int aa[6] = {}, t = i;
		rep(j, 6)aa[j] = t % 10, t /= 10;
		for(int e : add)if(valid(aa,e))D[i].add(D[i+e]);
		for(int e : sub)if(valid(aa,e))D[i].sub(D[i+e]);
		for(int j=0;j<C[i];j++){
			D[i].update(i);
		}
	}
	rep(i, 1000000)F[i] = D[i].make();
	for(int i=0;i<1000000;i++){
		int aa[6] = {}, t = i;
		rep(j, 6)aa[j] = t % 10, t /= 10;
		for(int e : add)if(valid(aa, e)){
			F[i] -= F[i+e];
			if(F[i] < 0)F[i] += MOD;
		}
		for(int e : sub)if(valid(aa, e)){
			F[i] += F[i+e];
			if(F[i] >= MOD)F[i] -= MOD;
		}
		G[i] = (ll)i * F[i];
	}
	ll ans = 0;
	rep(i, 1000000)ans ^= G[i];
	printf("%lld\n", ans);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		//printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}