#include <bits/stdc++.h>
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using namespace std;

#define REP(i,n) for(int i = 0; i < int(n); ++i)
typedef double ld; // 'long double' is 2.2 times slower
struct C {
	ld real, imag;
	C operator * (const C & he) const {
		return C{real * he.real - imag * he.imag,
				real * he.imag + imag * he.real};
	}
	void operator += (const C & he) {
		real += he.real; imag += he.imag;
	}
};
void dft(vector<C> & a, bool rev) {
	const int n = a.size();
	for(int i = 1, k = 0; i < n; ++i) {
		for(int bit = n / 2; (k ^= bit) < bit; bit /= 2);;;
		if(i < k) swap(a[i], a[k]);
	}
	for(int len = 1, who = 0; len < n; len *= 2, ++who) {
		static vector<C> t[30];
		vector<C> & om = t[who];
		if(om.empty()) {
			om.resize(len);
			const ld ang = 2 * acosl(0) / len;
			REP(i, len) om[i] = i%2 || !who ?
					C{cos(i*ang), sin(i*ang)} : t[who-1][i/2];
		}
		for(int i = 0; i < n; i += 2 * len)
			REP(k, len) {
				 const C x = a[i+k], y = a[i+k+len]
						* C{om[k].real, om[k].imag * (rev ? -1 : 1)};
				a[i+k] += y;
				a[i+k+len] = C{x.real - y.real, x.imag - y.imag};
			}
	}
	if(rev) REP(i, n) a[i].real /= n;
}
template<typename T>vector<T> multiply(const vector<T> & a, const vector<T> & b, bool split = false) {
	if(a.empty() || b.empty()) return {};
	int n = a.size() + b.size();
	vector<T> ans(n - 1);
	/* if(min(a.size(),b.size()) < 190) { // BRUTE FORCE
		REP(i, a.size()) REP(j, b.size()) ans[i+j] += a[i]*b[j];
		return ans;
	} */
	while(n&(n-1)) ++n;
	// CF/blog/entry/48417
	auto speed = [&](const vector<C> & w, int i, int k) {
		int j = i ? n - i : 0, r = k ? -1 : 1;
		return C{w[i].real + w[j].real * r, w[i].imag
				- w[j].imag * r} * (k ? C{0, -0.5} : C{0.5, 0});
	};
	if(!split) { // standard fast version
		vector<C> in(n), done(n);
		REP(i, a.size()) in[i].real = a[i];
		REP(i, b.size()) in[i].imag = b[i];
		dft(in, false);
		REP(i, n) done[i] = speed(in, i, 0) * speed(in, i, 1);
		dft(done, true);
		REP(i, ans.size()) ans[i] = is_integral<T>::value ?
				llround(done[i].real) : done[i].real;
	}
	else { // Split big INTEGERS into pairs a1*M+a2,
		const T M = 31600; // where M = sqrt(max_absvalue).
		vector<C> t[2]; // This version is 2.2-2.5 times slower.
		REP(x, 2) {
			t[x].resize(n);
			auto & in = x ? b : a;
			REP(i, in.size()) t[x][i]=C{ld(in[i]%M), ld(in[i]/M)};
			dft(t[x], false);
		}
		T mul = 1;
		for(int s = 0; s < 3; ++s, mul *= M) {
			vector<C> prod(n);
			REP(x, 2) REP(y, 2) if(x + y == s) REP(i, n)
				prod[i] += speed(t[0], i, x) * speed(t[1], i, y);
			dft(prod, true);
			REP(i, ans.size()) ans[i]+= llround(prod[i].real)*mul;
			// in case of modulo: ans[i] = (ans[i] + llround(prod[i].real)%MOD*mul) % MOD;
		}
	}
	return ans;
}

const int N = 2e6 + 6;

int n, x, A[N], cnt[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    int c = 0;

    cnt[0]++;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        c += (A[i] < x);
        cnt[c]++;
    }
    vector<long long> a(n + 1), b(n + 1);
    for (int i = 0; i <= n; i++) {
        a[i] = cnt[i];
        b[i] = cnt[n - i];
    }
    vector<long long> C = multiply(a, b);
    long long ans0 = 0;
    int lst = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] < x)
            lst = i;
        ans0 += (i - lst);
    }
    //C[n] = ans0;
    cout << ans0 << " ";
    for (int k = 1; k <= n; k++)
        cout << C[n + k] << " ";
}