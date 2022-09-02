#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;
typedef pair<double, double> pdd;

map <pii, int> X[1010];
set <pii> S[1010];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int main() {
	int N; scanf("%d", &N);
	S[1].insert(pii(-1, 0));
	for(int x=0;;x++) {
		for(int d:{-1,1}) {
			if(szz(S[1]) == N) break;
			S[1].insert(pii(x, x + d));
		}
		for(int d:{-1,1}) {
			if(szz(S[1]) == N) break;
			S[1].insert(pii(x, -x + d));
		}
		if(szz(S[1]) == N) break;
	}
	for(pii e : S[1]) printf("%d %d\n", e.Fi, e.Se);
	/*
	int x=1;
	for(x=1;;x++) {
		for(pii e : S[x]) {
			rep(u, 8) {
				int nx = e.Fi + dx[u];
				int ny = e.Se + dy[u];
				X[x+1][pii(nx, ny)] += 1;
			}
		}
		S[x+1] = S[x];
		for(auto e : X[x+1]) {
			if(e.Se >= 4) S[x+1].insert(e.Fi);
		}
		if(szz(S[x+1]) == szz(S[x])) break;
	}
	printf("%d %d\n", szz(S[x]), N*N/10);
	 */
	return 0;
}