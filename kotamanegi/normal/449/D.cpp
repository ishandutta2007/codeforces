#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"
#define int ll

using namespace std;
typedef string::const_iterator State;
#define eps 1e-9L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()
void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(20);
}

template <std::uint_fast64_t mod>
class modint {
public:
    using u64 = std::uint_fast64_t;
    u64 value = 0;
    modint() :value(0LL) {

    }
    modint(ll a) : value(a% mod) {

    }

    constexpr modint operator+(const modint rhs) const {
        return modint(*this) += rhs;
    }
    constexpr modint operator-(const modint rhs) const {
        return modint(*this) -= rhs;
    }
    constexpr modint operator*(const modint rhs) const {
        return modint(*this) *= rhs;
    }
    constexpr modint operator/(const modint rhs) const {
        return modint(*this) /= rhs;
    }
    constexpr modint& operator+=(const modint rhs) {
        value += rhs.value;
        if (value >= mod) {
            value -= mod;
        }
        return *this;
    }
    constexpr modint& operator-=(const modint rhs) {
        if (value < rhs.value) {
            value += mod;
        }
        value -= rhs.value;
        value += mod;
        value %= mod;
        return *this;
    }
    constexpr modint& operator*=(const modint rhs) {
        value = (value * rhs.value) % mod;
        return *this;
    }
    constexpr modint& operator/=(modint rhs) {
        ll rem = mod - 2;
        while (rem) {
            if (rem % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            rem /= 2LL;
        }
        return *this;
    }
    bool operator <(modint rhs) const {
        return value < rhs.value;
    }
    friend ostream& operator<<(ostream& os, modint& p) {
        os << p.value;
        return (os);
    }
};

template<typename A>
A pows(A val, ll b) {
    assert(b >= 1);
    A ans = val;
    b--;
    while (b) {
        if (b % 2) {
            ans *= val;
        }
        val *= val;
        b /= 2LL;
    }
    return ans;
}


int cnter[(1 << 20)];
void solve(){
	int n;
	cin >> n;
	REP(i, n) {
		int a;
		cin >> a;
		cnter[a]++;
	}
	for (int i = 19; i >= 0; --i) {
		REP(q, (1 << 20)) {
			if ((1 << i) & q) {
				cnter[q - (1 << i)] += cnter[q];
			}
		}
	}
	modint<MAX_MOD> ans = 0;
	REP(i, (1 << 20)) {
        modint<MAX_MOD> geko = 1;
        if (cnter[i] != 0) {
            geko = pows<modint<MAX_MOD>>(2, cnter[i]);
        }
        int tmp = 0;
        REP(q, 20) {
            if (i & (1 << q)) tmp++;
        }
        if (tmp % 2 == 0) {
            ans += geko;
        }
        else ans -= geko;
     }
	cout << ans << endl;
}
#undef int
int main() {
	init();
	solve();
}