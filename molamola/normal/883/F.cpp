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

string S[440];

void solve() {
	int n; scanf("%d", &n);
	set <string> S;
	rep(i, n) {
		string t; cin >> t;
		while(1) {
			int ch = 0;
			string r;
			for(int i=0;i<sz(t);i++) if(t[i] == 'u') {
				r = t.substr(0, i) + "oo" + t.substr(i+1); ch = 1; break;
			}
			if(ch == 1) { t = r; continue; }
			for(int i=0;i<sz(t)-1;i++) if(t[i] == 'k' && t[i+1] == 'h') {
				r = t.substr(0, i) + t.substr(i+1); ch = 1; break;
			}
			if(ch == 1) { t = r; continue; }
			break;
		}
		S.insert(t);
	}
	printf("%d\n", sz(S));
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}