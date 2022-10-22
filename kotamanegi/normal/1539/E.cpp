#line 1 "Contests/Codeforces_1539/E/main.cpp"
using namespace std;
#line 2 "library/bits/stdc++.h"

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#line 3 "Contests/Codeforces_1539/E/main.cpp"

// add your library with double quotation #include"" here.
// define your macros here.
#line 1 "library/atcoder/lazysegtree.hpp"



#line 5 "library/atcoder/lazysegtree.hpp"
#include <cassert>
#line 8 "library/atcoder/lazysegtree.hpp"

#line 1 "library/atcoder/internal_bit.hpp"



#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder


#line 10 "library/atcoder/lazysegtree.hpp"

namespace atcoder {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  // namespace atcoder


#line 7 "Contests/Codeforces_1539/E/main.cpp"
using namespace atcoder;

using namespace std;
typedef string::const_iterator State;
#define eps 1e-8L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

#define int long long
vector<int> cards;
vector<pair<int,int>> lefts;
vector<pair<int,int>> rights;
int ans_kouho[2][200000];
int op(int a,int b){
    return max(a,b);
}
int e(){
    return -1;
}
int mapping(int a, int b){
    if(a >= b) return -1;
    return b;
}
int composition(int a,int b){
    return max(a,b);
}
int id(){
    return -1;
}
#define LEN 1000000
void solve(){
    // write your solution here.
    int n,m;
    cin >> n >> m;
    map<int,int> zipper;
    lefts.push_back(mp(0,0));
    rights.push_back(mp(0,0));
    cards.push_back(0);
    REP(i,n){
        int k;
        cin >> k;
        cards.push_back(k);
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        lefts.push_back(mp(a,b+1));
        rights.push_back(mp(c,d+1));
        zipper[a] = 1;
        zipper[b+1] = 1;
        zipper[c] = 1;
        zipper[d+1] = 1;
        zipper[k] = 1;
    }
    n++;
    zipper[0] = 0;
    {
        int itr = 0;
        for(auto &x:zipper){
            x.second = itr;
            itr++;
        }
        REP(i,cards.size()){
            cards[i] = zipper[cards[i]];
        }
        REP(t,2){
            REP(i,lefts.size()){
                lefts[i].first = zipper[lefts[i].first];
                lefts[i].second = zipper[lefts[i].second];
            }
            swap(lefts,rights);
        }
    }
    lazy_segtree<int,op,e,int,mapping,composition,id> L(LEN),R(LEN);
    L.set(0,0);
    R.set(0,0);
    for(int i = 1;i < n;++i){
        // update L latest -> R
        pair<int,int> R_update = mp(-1,-1);
        if(L.prod(0,LEN) != -1){
            // exists
            if(lefts[i].first <= cards[i-1] and cards[i-1] < lefts[i].second){
                // left constaints OK
                if(rights[i].first <= cards[i] and cards[i] < rights[i].second){
                    // right constraints OK
                    R_update = mp(cards[i-1],i-1);
                }
            }
        }
        // update R latest -> L
        pair<int,int> L_update = mp(-1,-1);
        if(R.prod(0,LEN) != -1){
            // exists
            if(rights[i].first <= cards[i-1] and cards[i-1] < rights[i].second){
                // left constaints OK
                if(lefts[i].first <= cards[i] and cards[i] < lefts[i].second){
                    // right constraints OK
                    L_update = mp(cards[i-1],i-1);
                }
            }
        }
        // apply constraints
        if(!(lefts[i].first <= cards[i] and cards[i] < lefts[i].second)){
            // L latest will disappear
            L.apply(0,LEN,i-1);
        }
        if(!(rights[i].first <= cards[i] and cards[i] < rights[i].second)){
            // R latest will disappear
            R.apply(0,LEN,i-1);
        }
        L.apply(0,rights[i].first,i-1);
        L.apply(rights[i].second,LEN,i-1);
        R.apply(0,lefts[i].first,i-1);
        R.apply(lefts[i].second,LEN,i-1);
        if(L_update.first != -1){
            L.set(L_update.first,L_update.second);
        }
        if(R_update.first != -1){
            R.set(R_update.first,R_update.second);
        }
        // save
        ans_kouho[0][i] = L.prod(0,500001);
        ans_kouho[1][i] = R.prod(0,500001);
    }
    int itr = n-1;
    int target = -1;
    vector<int> ans(n,0);
    if(ans_kouho[0][n-1] != -1){
        target = 0;
    }
    if(ans_kouho[1][n-1] != -1){
        target = 1;
    }
    if(target == -1){
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    while(itr != 0){
        for(int q = ans_kouho[target][itr]+1;q <= itr;++q){
            ans[q] = target;
        }
        itr = ans_kouho[target][itr];
        target ^= 1;
    }
    for(int i = 1;i < n;++i){
        if(i != 1) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}
#undef int

// generated by oj-template v4.7.2 (https://github.com/online-judge-tools/template-generator)
int main() {
    // Fasterize input/output script
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(100);
    // scanf/printf user should delete this fasterize input/output script

    int t = 1;
    //cin >> t; // comment out if solving multi testcase
    for(int testCase = 1;testCase <= t;++testCase){
        solve();
    }
    return 0;
}