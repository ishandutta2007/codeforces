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

void solve(){
	int n; scanf("%d\n", &n);
	char A[220];
	fgets(A, 220, stdin);
	int ans = 0;
	for (int i = 0, now = 0; i <= n; i++) {
		if (i == n || A[i] == ' ') ans = max(ans, now), now = 0;
		else if (isupper(A[i])) ++now;
	}
	printf("%d\n", ans);
}

int main(){
	int T = 1; //scanf("%d", &T);
	while (T--) {
		solve();
	}

	return 0;
}