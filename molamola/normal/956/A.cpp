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

int n, m;
char A[110][110];

void solve() {
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%s", A[i]);
	rep(i, n) rep(j, i) rep(k, m) rep(u, k) {
		int c = (A[i][k] == '#') + (A[j][k] == '#') + (A[i][u] == '#') + (A[j][u] == '#');
		if(c == 3) { puts("No"); return; }
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