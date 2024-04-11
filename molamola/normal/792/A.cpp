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
typedef pair<ll, ll> PL;
typedef long double ldouble;

void solve(){
	int n, A[200020];
	scanf("%d", &n);
	for(int i=1;i<=n;i++)scanf("%d", A+i);
	sort(A+1, A+1+n);
	pii ans = pii(2e9+5, 0);
	for(int i=2;i<=n;i++){
		int t = A[i] - A[i-1];
		if(ans.Fi > t)ans.Fi = t, ans.Se = 1;
		else if(ans.Fi == t)ans.Se++;
	}
	printf("%d %d\n", ans.Fi, ans.Se);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}