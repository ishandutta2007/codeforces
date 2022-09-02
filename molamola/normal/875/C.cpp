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

vector <int> L[100010], E[100010];
int n, m;
int chk[100010];

void solve() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) {
		int x; scanf("%d", &x);
		while(x--) {
			int y; scanf("%d", &y);
			L[i].pb(y);
		}
	}
	memset(chk, -1, sizeof chk);
	for(int i=2;i<=n;i++) {
		int len = min(szz(L[i-1]), szz(L[i]));
		int f = -1;
		for(int j=0;j<len;j++) {
			if(L[i-1][j] != L[i][j]) {
				f = j; break;
			}
		}
		if(f != -1) {
			int c = L[i-1][f], e = L[i][f];
			if(c > e) {
				if(chk[c] == 2) { puts("No"); return; }
				chk[c] = 1;
				if(chk[e] == 1) { puts("No"); return; }
				chk[e] = 2;
			}
			else {
				E[e].pb(c);
			}
		}
		else {
			if(szz(L[i-1]) > szz(L[i])) {
				puts("No");
				return;
			}
		}
	}
	queue <int> que;
	for(int i=1;i<=m;i++) if(chk[i] == 1) que.push(i);
	while(!que.empty()) {
		int t = que.front(); que.pop();
		for(int e : E[t]) {
			if(chk[e] == 2) { puts("No"); return; }
			if(chk[e] == -1) chk[e] = 1, que.push(e);
		}
	}
	puts("Yes");
	vector <int> ans;
	for(int i=1;i<=m;i++) if(chk[i] == 1) ans.pb(i);
	printf("%d\n", szz(ans));
	for(int e : ans) printf("%d ", e); puts("");
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}