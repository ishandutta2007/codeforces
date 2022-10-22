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
#define Inf (long long)1000000000000000

long long get(vector<int> a,vector<int> b){
	vector<vector<int>> inds(4);
	rep(i,b.size()){
		inds[b[i]].push_back(i);
	}
	
	fenwick_tree<int> F(b.size());
	rep(i,a.size())F.add(i,1);
	long long ret =0LL;
	for(int i=a.size()-1;i>=0;i--){
		int ind = inds[a[i]].back();
		inds[a[i]].pop_back();
		F.add(ind,-1);
		ret += F.sum(ind,a.size());
		
		
	}
	return ret;
}


int main(){
	
	int _t;
	cin>>_t;
	
	map<char,int> cti;
	cti['A'] = 0;
	cti['N'] = 1;
	cti['O'] = 2;
	cti['T'] = 3;
	
	string sx = "ANOT";
	
	rep(_,_t){
		
		string s;
		cin>>s;
		
		long long  maxi = -1;
		
		vector<int> ss(s.size());
		vector<int> cnt(4,0);
		rep(i,ss.size()){
			ss[i] = cti[s[i]];
			cnt[ss[i]]++;
		}

		vector<int> x = {0,1,2,3};
		vector<int> ans;
		do{
			vector<int> tt;
			rep(i,4){
				rep(j,cnt[x[i]])tt.push_back(x[i]);
			}
			long long ret = get(ss,tt);
			if(ret>maxi){
				maxi = ret;
				ans = x;
			}
		}
		while(next_permutation(x.begin(),x.end()));
		
		vector<int> tt;
		rep(i,4){
			rep(j,cnt[ans[i]])tt.push_back(ans[i]);
		}
		
		string P = "";
		rep(i,tt.size())P += sx[tt[i]];
		
		cout<<P<<endl;
		
	}
	
	return 0;
}