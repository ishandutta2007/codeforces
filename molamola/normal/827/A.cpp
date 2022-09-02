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
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int n;
string ST[100010];
vector <pii> pos[2000010];
char ans[2000010];

void solve(){
	scanf("%d", &n);
	int L = 0;
	for(int i=1;i<=n;i++) {
		cin >> ST[i];
		int l = sz(ST[i]);
		int k; scanf("%d", &k);
		while(k--) {
			int x; scanf("%d", &x);
			pos[x].pb(pii(x, i));
			pos[x+l].pb(pii(x, -i));
			L = max(L, x + l - 1);
		}
	}
	multiset <pii> S;
	for(int i=1;i<=L;i++) {
		for(pii e : pos[i]) {
			if(e.Se > 0) S.insert(e);
			else S.erase(pii(e.Fi, -e.Se));
		}
		if(sz(S) == 0) ans[i] = 'a';
		else {
			pii e = *S.begin();
			ans[i] = ST[e.Se][i-e.Fi];
		}
	}
	printf("%s\n", ans+1);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
};