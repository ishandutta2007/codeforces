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

int n, m;
char A[110][110];

void solve(){
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%s", A[i]);
	char T[4] = "RGB";
	sort(T, T + 3);
	int ok = 0;
	do{
		char B[110][110] = {};
		if (n % 3 == 0) {
			rep(k, 3) rep(i, n / 3) rep(j, m) B[k * n / 3 + i][j] = T[k];
		}
		int f = 1;
		rep(i, n) rep(j, m) if (B[i][j] != A[i][j]) f = 0;
		if (f) ok = 1;
		f = 1;
		if (m % 3 == 0) {
			rep(k, 3) rep(i, m / 3) rep(j, n) B[j][k * m / 3 + i] = T[k];
		}
		rep(i, n) rep(j, m) if (B[i][j] != A[i][j]) f = 0;
		if (f) ok = 1;
	} while (next_permutation(T, T + 3));
	puts(ok ? "YES" : "NO");
}

int main(){
	int T = 1; //scanf("%d", &T);
	while (T--) {
		solve();
	}

	return 0;
}