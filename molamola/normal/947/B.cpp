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
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

ll S[100010];
ll ans[100010];
int N;
ll V[100010], T[100010];
ll ST[100010];

void solve(){
	scanf("%d", &N);
	for(int i=1;i<=N;i++) scanf("%lld", V+i);
	for(int i=1;i<=N;i++) scanf("%lld", T+i), ST[i] = ST[i-1] + T[i];
	for(int i=1;i<=N;i++) {
		int t = (int)(upper_bound(ST + 1, ST + 1 + N, ST[i-1] + V[i]) - ST);
		ll del = ST[i-1] + V[i] - ST[t-1];
		S[i]++, S[t]--;
		ans[t] += del;
	}
	for(int i=1;i<=N;i++) S[i] += S[i-1];
	for(int i=1;i<=N;i++) ans[i] += S[i] * T[i];
	for(int i=1;i<=N;i++) printf("%lld ", ans[i]); puts("");
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}