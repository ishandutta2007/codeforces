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
 
const int mod = 998244353;
int N, X[100010], V[100010], P[100010], Q[100010];
 
struct mat {
	int p[2][2];
	mat operator*(mat a) {
		mat res;
		rep(i, 2) rep(j, 2) res.p[i][j] = 0;
		rep(i, 2) rep(k, 2) rep(j, 2) res.p[i][j] = (res.p[i][j] + (ll) p[i][k] * a.p[k][j]) % mod;
		return res;
	}
	void init() {
		rep(a, 2) rep(b, 2) p[a][b] = (a == b ? 1 : 0);
	}
};
 
mat T[1<<18], MV[100010];
const int ADD = 1<<17;
 
void upd(int a) {
	T[ADD+a] = MV[a];
	for(int t=(ADD+a)/2;t;t>>=1) T[t] = T[t*2+1] * T[t*2];
}
 
mat read(int l, int r) {
	l += ADD, r += ADD;
	mat rl, rr; rl.init(); rr.init();
	while(l <= r) {
		if(l & 1) rl = T[l++] * rl;
		if(!(r & 1)) rr = rr * T[r--];
		l >>= 1, r >>= 1;
	}
	return rr * rl;
}
 
pii apply(mat M, pii a) {
	pii res = pii(0, 0);
	res.Fi = ((ll)M.p[0][0] * a.Fi + (ll)M.p[0][1] * a.Se) % mod;
	res.Se = ((ll)M.p[1][0] * a.Fi + (ll)M.p[1][1] * a.Se) % mod;
	return res;
}
 
int pw(int x, int y = mod - 2) {
	int res = 1;
	while(y) {
		if(y & 1) res = (ll) res * x % mod;
		x = (ll) x * x % mod;
		y >>= 1;
	}
	return res;
}
 
struct event {
	pii tm;
	int i, ri, rj;
	bool operator<(const event &rhs) const {
		return (ll)tm.Fi * rhs.tm.Se < (ll)tm.Se * rhs.tm.Fi;
	}
};
vector <event> E;
 
int main() {
	scanf("%d", &N);
	for(int i=1;i<=N;i++) {
		scanf("%d%d%d", X+i, V+i, P+i);
		P[i] = (ll) P[i] * pw(100) % mod;
		Q[i] = (mod + 1 - P[i]) % mod;
	}
	for(int i=1;i<N;i++) {
		MV[i].p[0][0] = MV[i].p[0][1] = P[i+1];
		MV[i].p[1][0] = MV[i].p[1][1] = Q[i+1];
	}
	for(int i=1;i<N;i++) T[ADD+i] = MV[i];
	for(int i=ADD-1;i;i--) T[i] = T[i*2+1] * T[i*2];
	for(int i=1;i<N;i++) {
		int len = X[i+1] - X[i];
		if(V[i] > V[i+1]) E.pb({pii(len, V[i] - V[i+1]), i, 0, 0});
		E.pb({pii(len, V[i] + V[i+1]), i, 0, 1});
		if(V[i] < V[i+1]) E.pb({pii(len, V[i+1] - V[i]), i, 1, 1});
	}
	sort(all(E));
	int ans = 0;
	for(auto ele : E) {
		int ntm = ele.tm.Fi * (ll) pw(ele.tm.Se) % mod;
		int x = ele.i;
		int l_p, r_p;
		mat m = read(1, x-1);
		pii mv = apply(m, pii(P[1], Q[1]));
		l_p = (ele.ri == 0 ? mv.Fi : mv.Se);
		m = read(x+1, N-1);
		pii temp = pii(P[x+1], Q[x+1]);
		if(ele.rj == 0) temp.Se = 0;
		else temp.Fi = 0;
		mv = apply(m, temp);
		r_p = (mv.Fi + mv.Se) % mod;
		ans = (ans + (ll)ntm * l_p % mod * (ll)r_p) % mod;
		MV[x].p[ele.rj][ele.ri] = 0;
		upd(x);
	}
	printf("%d\n", ans);
	return 0;
}