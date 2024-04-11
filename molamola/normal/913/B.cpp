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

int n, p[1010];
vector <int> E[1010];

void solve() {
	scanf("%d", &n);
	for(int i=2;i<=n;i++) {
		scanf("%d", p+i);
		E[p[i]].pb(i);
	}
	for(int i=1;i<=n;i++) if(szz(E[i])) {
		int c = 0;
		for(int e : E[i]) if(szz(E[e]) == 0) ++c;
		if(c <= 2) { puts("No");return; }
	}
	puts("Yes");
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}