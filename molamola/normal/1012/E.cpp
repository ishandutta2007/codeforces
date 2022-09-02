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
#include <bitset>
#include <time.h>
#include <limits.h>

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

int N, S;
int A[200020], B[200020];
vector <int> vx;
int pp[200020]; int Find(int x) { return pp[x] == x ? x : pp[x] = Find(pp[x]); }
vector <int> vs[2][200020];
int nxt[200020];

int main() {
	scanf("%d%d", &N, &S);
	for(int i=1;i<=N;i++) scanf("%d", A+i);
	for(int i=1;i<=N;i++) vx.pb(A[i]);
	sort(all(vx)); vx.resize(unique(all(vx)) - vx.begin());
	for(int i=1;i<=N;i++) A[i] = (int)(lower_bound(all(vx), A[i]) - vx.begin() + 1);
	for(int i=1;i<=N;i++) B[i] = A[i];
	sort(B+1, B+1+N);
	int cnt = 0;
	for(int i=1;i<=N;i++) if(B[i] != A[i]) ++cnt;
	if(cnt > S) {
		puts("-1");
		return 0;
	}
	for(int i=1;i<=N;i++) pp[i] = i;
	for(int i=1;i<=N;i++) if(A[i] != B[i]) {
		vs[0][A[i]].pb(i);
		vs[1][B[i]].pb(i);
	}
	int L = szz(vx);
	for(int i=1;i<=L;i++) {
		int n = szz(vs[0][i]);
		rep(j, n) {
			int x = vs[0][i][j], y = vs[1][i][j];
			nxt[x] = y;
			int px = Find(x), py = Find(y);
			if(px != py) pp[px] = py;
		}
	}
	for(int i=1;i<=L;i++) {
		int n = szz(vs[0][i]);
		for(int j=1;j<n;j++) {
			int x = vs[0][i][0];
			int y = vs[0][i][j];
			int px = Find(x), py = Find(y);
			if(px != py) {
				swap(nxt[x], nxt[y]);
				pp[px] = py;
			}
		}
	}
	int c[200020] = {};
	for(int i=1;i<=N;i++) c[Find(i)]++;
	vector <pii> v;
	for(int i=1;i<=N;i++) if(pp[i] == i && A[i] != B[i]) v.pb(pii(c[i], i));
	sort(all(v)); reverse(all(v));
	S -= cnt;
	vector <vector <int> > ans;
	if(S > 2 && szz(v) > 2) {
		int r = min(S, szz(v));
		int save = nxt[v[0].Se];
		for(int i=0;i<r-1;i++) nxt[v[i].Se] = nxt[v[i+1].Se];
		nxt[v[r-1].Se] = save;
		vector <int> nv;
		for(int i=0;i<r;i++) nv.pb(v[i].Se);
		reverse(all(nv));
		ans.pb(nv);
		for(int i=1;i<r;i++) pp[Find(v[i].Se)] = Find(v[0].Se);
	}
	
	for(int i=1;i<=N;i++) if(A[i] != B[i] && pp[i] == i) {
		vector <int> v; v.pb(i);
		for(int t=nxt[i];t!=i;t=nxt[t]) {
			v.pb(t);
		}
		ans.pb(v);
	}
	printf("%d\n", szz(ans));
	for(auto e : ans) {
		printf("%d\n", szz(e));
		for(int f : e) printf("%d ", f); puts("");
	}
	
	return 0;
}