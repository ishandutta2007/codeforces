#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}
vd conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vd res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
	rep(i,0,sz(b)) in[i].imag(b[i]);
	fft(in);
	for (C& x : in) x *= x;
	rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
	return res;
}

ll rd(double x){
	if(x > 0) return (x + 0.5);
	return (x - 0.5);
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int n, m, Q;
	cin >> n >> m >> Q;
	const int M = int(1e5) + 2;
	vector<int> a(n);
	vector<int> b(m);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	vector<ll> all_score(2*M, 0);
	for(int q = 0; q < 2; q++){
		vector<int> ac = a;
		vector<int> bc = b;
		ac.insert(ac.begin(), q * M);
		ac.insert(ac.end(), q * M);
		bc.insert(bc.begin(), q * M);
		bc.insert(bc.end(), q * M);
		vector<double> freq_a(M, 0);
		vector<double> freq_b(M, 0);
		for(int i = 1; i + 1 < (int)ac.size(); i++){
			if(ac[i-1] < ac[i] && ac[i] >= ac[i+1]) freq_a[ac[i]] += 1;
			if(ac[i-1] >= ac[i] && ac[i] < ac[i+1]) freq_a[ac[i]] -= 1;
		}
		for(int i = 1; i + 1 < (int)bc.size(); i++){
			if(bc[i-1] < bc[i] && bc[i] >= bc[i+1]) freq_b[bc[i]] += 1;
			if(bc[i-1] >= bc[i] && bc[i] < bc[i+1]) freq_b[bc[i]] -= 1;
		}
		vector<double> score = conv(freq_a, freq_b);
		for(int i = 0; i < (int)score.size(); i++){
			all_score[i] += rd(score[i]);
		}
	}
	all_score[0] -= 1;
	for(int j = 1; j < 2*M; j++){
		all_score[j] += all_score[j-1];
	}
	for(int _ = 0; _ < Q; _++){
		int x;
		cin >> x;
		cout << -all_score[x-1] << '\n';
	}
}