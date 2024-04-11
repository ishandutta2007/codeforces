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

char S[1000010];
int N;
vector <int> p, q;
int chkb[1000010];
int P[1000010];
int D[1000010];
int get(int l, int r) { return r >= l && P[r] - P[l-1]; }

void solve() {
	scanf("%d%s", &N, S+1);
	for(int i=1;i<=N;i++) {
		if(S[i] == 'P') p.pb(i);
		else if(S[i] == '*') q.pb(i);
		P[i] = P[i-1] + (S[i] == '*');
	}
	if(sz(p) == 1) {
		int a = p[0];
		int c[2] = {}, d[2] = {};
		for(int e : q) {
			if(e < a) c[0]++, d[0] = max(d[0], a - e);
			else c[1]++, d[1] = max(d[1], e - a);
		}
		if(c[0] > c[1] || (c[0] == c[1] && d[0] < d[1])) printf("%d %d\n", c[0], d[0]);
		else printf("%d %d\n", c[1], d[1]);
	}
	else {
		swap(p, q);
		int low = 1, high = N, res = N + 5;
		while(low <= high) {
			int mid = (low + high) >> 1;
			for(int i=0;i<=sz(q);i++) D[i] = 0;
			for(int i=1;i<=sz(q);i++) {
				int e = q[i-1];
				if(get(D[i-1]+1, e - mid - 1) == 0) D[i] = e;
				if(get(D[i-1]+1, e) == 0) D[i] = max(D[i], e + mid);
				if(i > 1) {
					int f = q[i-2];
					if(get(D[i-2]+1, e - mid - 1) == 0) D[i] = max(D[i], f + mid);
				}
			}
			
			if(D[sz(q)] < p.back()) low = mid + 1;
			else res = mid, high = mid - 1;
		}
		printf("%d %d\n", sz(p), res);
	}
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}