#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

int N;
vector <int> E[250050];
vector <int> F[250050];
vector <t3> X;
pii FS[250050];

int down[250050], cut[250050];
void pdfs(int x, int fa) {
	down[x] = 1;
	for(int e : E[x]) if(!cut[e] && e != fa) {
		pdfs(e, x);
		down[x] += down[e];
	}
}

int SV[250050], VL[250050], vlz;
void qdfs(int x, int fa, int r) {
	SV[x] = r;
	VL[vlz++] = x;
	for(int e : E[x]) if(!cut[e] && e != fa) {
		qdfs(e, x, r);
	}
}

int pp[250050]; int Find(int x) { return pp[x] == x ? x : pp[x] = Find(pp[x]); }
int par[250050];

void fdfs(int x, int fa) {
	par[x] = fa;
	for(int e : F[x]) if(e != fa) {
		fdfs(e, x);
	}
}

void Do(int rt, vector <t3> &V) {
	pdfs(rt, -1);
	int h = down[rt] / 2;
	while(1) {
		int ch = 0;
		for(int e : E[rt]) if(!cut[e] && down[e] < down[rt] && down[e] > h) {
			rt = e; ch = 1; break;
		}
		if(!ch) break;
	}
	vector <int> child;
	for(int e : E[rt]) if(!cut[e]) child.pb(e);
	SV[rt] = -1;
	vlz = 0; VL[vlz++] = rt;
	int m = szz(child);
	rep(i, m) qdfs(child[i], rt, i);
	rep(i, vlz) pp[VL[i]] = VL[i];
	for(auto &[x, y, i] : V) {
		if(SV[x] == SV[y]) pp[Find(x)] = Find(y);
	}
	rep(i, szz(V)) {
		int x, y, id; tie(x, y, id) = V[i];
		if(SV[x] != SV[y]) {
			int px = Find(x), py = Find(y);
			F[px].pb(py);
			F[py].pb(px);
		}
	}
	fdfs(rt, -1);
	vector <vector<t3> > Y(m);
	for(auto [x, y, i] : V) {
		int px = Find(x), py = Find(y);
		if(px == py) Y[SV[x]].pb(t3(x, y, i));
		else {
			if(par[px] != py) swap(px, py), swap(x, y);
			if(Find(child[SV[px]]) == px) {
				printf("%d %d %d %d\n", child[SV[px]], rt, FS[i].Fi, FS[i].Se);
			}
			else {
				Y[SV[x]].pb(t3(x, child[SV[x]], i));
			}
		}
	}

	rep(i, vlz) F[VL[i]].clear();

	cut[rt] = 1;
	rep(i, m) Do(child[i], Y[i]);
}

int main() {
	scanf("%d", &N);
	rep(i, N-1) {
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].pb(y);
		E[y].pb(x);
	}
	for(int i=1;i<N;i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		FS[i] = {x, y};
		X.pb(t3(x, y, i));
	}
	printf("%d\n", N - 1);
	Do(1, X);
	return 0;
}