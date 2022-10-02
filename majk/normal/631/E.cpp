#include <iostream>
#include <set>
#include <functional>
#include <limits>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

/** Multiply two 64-bit unsigned integers to get a 128-bit unsigned integer (as a pair of ull) */
pair<ull,ull> mulull(ull a, ull b) {
#ifdef __SIZEOF_INT128__
	__int128 result = (__int128) a * (__int128) b;
	return {(ull) (result >> 64), (ull) result};
#else
	ull c = (ui)a, d = a>>32, e = (ui)b, f = b>>32, g = d*f, h = d*e, i = f*c, j = c*e, k = (j>>32)+(ui)h+(ui)i, l = g+(h>>32)+(i>>32)+(k>>32);
	return {l, ((h+i) << 32) + j};
#endif
}

bool fractionGreaterOrEqual(ll a, ll b, ll c, ll d) {
	if (b < 0) { b = -b; a = -a; }
	if (d < 0) { d = -d; c = -c; }
	return a < 0 && c < 0 ? mulull(-a, d) <= mulull(-c, b) : (a >= 0) && (c < 0 || mulull(a, d) >= mulull(c, b));
}

namespace Envelope {
	template<typename T>
	struct Line {
		T m, b; int id;
		mutable function<const Line<T> *()> succ;

		bool operator<(const Line &rhs) const {
			if (rhs.b != numeric_limits<T>::min()) return m < rhs.m;
			const Line *s = succ();
			if (!s) return 0;
			return b - s->b < (s->m - m) * rhs.m;
		}
	};

	template<typename T>
	struct Upper : public multiset<Envelope::Line<T>> {
		using parent = multiset<Line<T>>;

		bool bad(typename parent::iterator y) {
			auto z = next(y);
			if (y == parent::begin()) {
				return z != parent::end() && y->m == z->m && y->b <= z->b;
			} else {
				auto x = prev(y);
				if (z == parent::end()) {
					return y->m == x->m && y->b <= x->b;
				} else {
					return fractionGreaterOrEqual(x->b - y->b, y->m - x->m, y->b - z->b, z->m - y->m);
				}
			}
		}

		void insert_line(T m, T b, int i = 0) {
			auto y = parent::insert({m, b, i});
			y->succ = [=] { return next(y) == parent::end() ? 0 : &*next(y); };
			if (bad(y)) { parent::erase(y); return; }
			while (next(y) != parent::end() && bad(next(y))) parent::erase(next(y));
			while (y != parent::begin() && bad(prev(y))) parent::erase(prev(y));
		}

		T operator[](T x) const {
			auto l = parent::lower_bound({x, numeric_limits<T>::min()});
			return l == parent::end() ? numeric_limits<T>::min() : l->m * x + l->b;
		}

		int best(T x) const {
			auto l = parent::lower_bound({x, numeric_limits<T>::min()});
			return l == parent::end() ? -1 : l->id;
		}
	};

	// Lower envelope. WARNING: the internal representation changes m & b.
	template<typename T>
	struct Lower : public Upper<T> {
		void insert_line(T m, T b, int i = 0) { Upper<T>::insert_line(-m, -b, i); }
		T operator[](T x) const { return -Upper<T>::operator[](x); }
	};
}

int main() {
    int N; cin >> N;
    vector<ll> A(N); for (ll&a:A) cin >> a;
    vector<ll> P(N+1, 0); for (int i = 0; i < N; ++i) P[i+1] = P[i] + A[i];
    ll ans = 0, tot = 0;
    {
        ll cur = 0;
        Envelope::Upper<ll> CHT;
        for (int j = 0; j < N; ++j) {
            ll a = A[j];
            CHT.insert_line(a, P[j+1] - j * a);
            tot += (j+1) * a;
            cur += a;
            ans = max(ans, CHT[j] - P[j+1]);
        }
    }

    
    {
        Envelope::Upper<ll> CHT;
        ll cur = 0;
        for (int j = N-1; j >= 0; --j) {
            ll a = A[j];
            CHT.insert_line(a, - (P[N] - P[j]) - j * a);
            cur += a;
            ans = max(ans, CHT[j] + (P[N] - P[j]));
        }
    }
    cout << ans + tot << endl;
}