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
typedef tuple<ll, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<ldouble, ldouble> pdd;

int F[1000010];
int G[1000010];
int T[10][1000010];

void solve() {
	for(int i=1;i<=9;i++) F[i] = i;
	for(int i=10;i<=1000000;i++) {
		int t = i % 10;
		F[i] = F[i / 10] * (t == 0 ? 1 : t);
	}
	for(int i=1;i<=9;i++) G[i] = i;
	for(int i=10;i<=1000000;i++) {
		G[i] = G[F[i]];
	}
	for(int i=1;i<=1000000;i++) {
		int v = G[i];
		for(int j=i;j<=1000000;j+=(j&-j)) T[v][j]++;
	}
	int q; scanf("%d", &q);
	while(q--) {
		int l, r, k; scanf("%d%d%d", &l, &r, &k);
		int ans = 0;
		for(int i=r;i;i-=(i&-i)) ans += T[k][i];
		for(int i=l-1;i;i-=(i&-i)) ans -= T[k][i];
		printf("%d\n", ans);
	}
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}