#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

//#define MOD 1000000007
#define MOD 998244353

struct mint {
	int i;
	mint() : i(0) {}
	mint(int x) {
		i = int(x % MOD);
		if (i < 0) i += MOD;
	}
	template<class T> mint(T x) {
		i = int(x % MOD);
		if (i < 0) i += MOD;
	}
	mint operator+(const mint x) const {return i + x.i;}
	mint operator-(const mint x) const {return i - x.i;}
	mint operator*(const mint x) const {return (long long)i * x.i;}
	mint operator/(const mint x) const {return (long long)i * x.pow(MOD - 2).i;}
	mint inv() {return pow(MOD - 2);}
	template<class T> mint pow(T p) const {
		long long r = 1;
		long long t = i;
		for(; p > 0; p >>= 1) {
			if (p & 1) r = r * t % MOD;
			t = t * t % MOD;
		}
		return r;
	}
	template<class T1, class T2> static mint pow(T1 a, T2 b) {
		long long r = 1;
		long long t = (long long)(a % MOD);
		for(; b > 0; b >>= 1) {
			if (b & 1) r = r * t % MOD;
			t = t * t % MOD;
		}
		return r;
	}
	mint& operator+=(const mint x) {
		i = (i + x.i) % MOD;
		return *this;
	}
	mint& operator-=(const mint x) {
		i = i - x.i;
		if (i < 0) i += MOD;
		return *this;
	}
	mint& operator*=(const mint x) {
		i = (int)((long long)i * x.i % MOD);
		return *this;
	}
	mint& operator/=(const mint x) {
		i = (long long)i * x.pow(MOD - 2).i % MOD;
		return *this;
	}
};

std::ostream& operator<<(std::ostream& os, const mint& m) {
	return os << m.i;
}

struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < MOD);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
};
#define endl '\n'
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    k--;
    VI l(n), r(n);
    rep(i, n) cin >> l[i] >> r[i];
    int mxr;
    {
        map<int, int> toC;
        rep(i, n) toC[l[i]] = toC[r[i]] = 0;
        mxr = 0;
        for(auto it = toC.begin(); it != toC.end(); it++) {
            it->second = mxr++;
        }
        rep(i, n) l[i] = toC[l[i]], r[i] = toC[r[i]];
    }
    combination comb(n+3);
    VI addEvent, rmEvent;
    rep(i, n) addEvent.push_back(l[i]), rmEvent.push_back(r[i]);
    sort(rall(addEvent));
    sort(rall(rmEvent));
    int now = 0;
    int cnt = 0;
    mint ans = 0;
    while(now < mxr) {
        if (!addEvent.empty() && addEvent.back() == now) {
            if (cnt >= k) ans += comb(cnt, k);
            cnt++;
            addEvent.pop_back();
        } else if (!rmEvent.empty() && rmEvent.back() == now) {
            cnt--;
            rmEvent.pop_back();
        } else {
            now++;
        }
    }
    cout << ans << endl;
    /*
    VI ord(n);
    rep(i, n) ord[i] = i;
    sort(all(ord), [&](int i, int j) {return r[i] < r[j];});
    fenwick_tree<int> ft(mxr);
    mint ans = 0;
    rep(i, n) {
        int li = l[ord[i]], ri = r[ord[i]];
        int cnt = ft.sum(li, ri+1);
        if (cnt >= k) {
            // cnt_C_k
            ans += comb(cnt, k);
        }
        ft.add(ri, 1);
        cout << ord[i] << ' ' << ans << endl;
    }
    cout << ans << endl;
    */
}