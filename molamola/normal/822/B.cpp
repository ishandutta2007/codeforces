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

void solve(){
	int n, m;
	scanf("%d%d", &n, &m);
	string s, t;
	cin >> s >> t;
	vector <int> ans;
	int res = 1e9;
	rep(i, sz(t) - sz(s) + 1) {
		vector <int> v;
		rep(j, sz(s)) if(s[j] != t[i+j]) v.pb(j+1);
		if(res > sz(v)) res = sz(v), ans = v;
	}
	printf("%d\n", res);
	for(int e : ans) printf("%d ",e); puts("");
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d\n", tc);
		solve();
	}
	return 0;
};