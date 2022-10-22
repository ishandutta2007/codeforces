#include <stdio.h>
#include <bits/stdc++.h>

#include <cassert>
#include <vector>


#include <cassert>
#include <numeric>
#include <type_traits>

namespace atcoder {

namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

#else

template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;

#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

template <class T> struct fenwick_tree {
    using U = internal::to_unsigned_t<T>;

  public:
    fenwick_tree() : _n(0) {}
    explicit fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += U(x);
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<U> data;

    U sum(int r) {
        U s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

}  // namespace atcoder

using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main() {
	
	vector<vector<int>> ys(200001);
	long long S = 0;
	for(int i=1;i<=200000;i++){
		for(int j=i*2;j<=200000;j+=i){
			ys[j].push_back(i);
		}
	}
	//cout<<S<<endl;
	int q;
	cin>>q;
	vector<int> l(q),r(q);
	vector<vector<int>> qs(200005);
	rep(i,q){
		scanf("%d %d",&l[i],&r[i]);
		qs[r[i]].push_back(i);
	}
	vector<long long> ans(q,0);
	rep(i,q){
		long long s = r[i] - l[i] + 1;
		ans[i] = s * (s-1) * (s-2) / 6;
	}
	fenwick_tree<long long> F(200005);
	for(int i=3;i<=200000;i++){
		int c = 1;
		rep(j,30){
			if((i>>j)&1)break;
			c*=2;
		}
		vector<int> t;
		rep(j,ys[i].size()){
			F.add(ys[i][j],ys[i].size()-1-j);
			if(ys[i][j]%c==0&&ys[i][j]*2<i)t.push_back(ys[i][j]);
		}
		rep(j,t.size()){
			for(int k=j+1;k<t.size();k++){
				if(t[j]*2+t[k]*2>i)F.add(t[j]*2,1);
			}
		}
		
		rep(j,t.size()){
			rep(k,ys[i].size()){
				if(t[j] * 2 + ys[i][k] > i)F.add(min(ys[i][k],t[j]*2),1);
			}
		}
		rep(j,qs[i].size()){
			int ii = qs[i][j];
			
			ans[ii] -= F.sum(l[ii],r[ii]);
		}
		
	}
	rep(i,q){
		printf("%lld\n",ans[i]);
	}
	
    return 0;
}