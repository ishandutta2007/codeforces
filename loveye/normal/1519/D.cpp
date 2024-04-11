#include<bits/stdc++.h>
using namespace std;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define LL long long
#define I inline void

const int N = 1e4 + 5;
int n,a[N],b[N];
LL s[N],ans[N/2][N/2],out;
struct Poly {
	int n;
	LL a[N];
	inline void mulx() {
		rf(i,n,0) a[i+1] = a[i];
		a[0] = 0; ++n;
	}
	inline void plus(Poly &o,LL c) {
		fr(i,0,o.n) a[i] += o.a[i] * c;
	}
	void print() {
		fr(i,0,n) cout << a[i] << ' ';
		cout << endl;
	}
} f,g,h;
int main() {
	cin >> n;
	fr(i,1,n) cin >> a[i];
	fr(i,1,n) cin >> b[i];
	fr(i,1,n) s[i] = s[i-1] + 1ll * a[i] * b[i];
	rf(l,n,1) {
		f.mulx();
		g.mulx();
		h.mulx();
		h.mulx();
		g.a[0] = b[l];
		h.plus(f,g.a[0]);
		f.a[0] = a[l];
		h.plus(g,f.a[0]);
		fr(r,l,n) ans[l][r] = h.a[r-l];
	}
	out = s[n];
	fr(i,1,n) fr(j,i,n) out = max(out,s[n] + ans[i][j] - s[j] + s[i-1]);
	cout << out << endl;
	return 0;
}