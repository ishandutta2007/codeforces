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
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000000





int main(){
	
	int n,q;
	cin>>n>>q;
	
	map<int,pair<int,int>> mp;
	mp[0] = make_pair(n,0);
	fenwick_tree<long long> F(n+1);
	vector<long long> Add(n,0);
	rep(_,q){
		string s;
		cin>>s;
		
		if(s=="Query"){
			int x;
			scanf("%d",&x);
			x--;
			auto it=  mp.upper_bound(x);
			it--;
			long long ans = F.sum(0,x+1);//seg.get(x);
			//cout<<ans<<endl;
			ans += Add[it->second.second];
			printf("%lld\n",ans);
		}
		else if(s=="Add"){
			int c,x;
			scanf("%d %d",&c,&x);
			Add[c-1] += x;
		}
		else{
			int l,r,c;
			scanf("%d %d %d",&l,&r,&c);
			l--;
			c--;
			
			auto it= mp.upper_bound(l);
			it--;
			vector<int> ll,rr,cc;
			ll.push_back(l);
			rr.push_back(r);
			cc.push_back(c);
			while(it!=mp.end()){
				int L = it->first;
				int R = it->second.first;
				int C = it->second.second;
				if(L >= r)break;
				//seg.apply(L,R,Add[C] - Add[c]);
				it = mp.erase(it);
				bool f0 = (L<=l&&l<R);
				bool f1 = (L<=r&&r<R);
				
				if(f0){
					ll.push_back(L);
					rr.push_back(l);
					cc.push_back(C);
					//seg.apply(L,l,Add[c]-Add[C]);
				}
				if(f1){
					ll.push_back(r);
					rr.push_back(R);
					cc.push_back(C);
				//	seg.apply(r,R,Add[c]-Add[C]);
				}
				F.add(max(L,l),Add[C]-Add[c]);
				F.add(min(r,R),-(Add[C]-Add[c]));
				//seg.apply(max(L,l),min(R,r),Add[C]-Add[c]);
			}
			rep(i,ll.size()){
				if(ll[i]==rr[i])continue;
			//	seg.apply(ll[i],rr[i],-Add[cc[i]]);
				mp[ll[i]] = make_pair(rr[i],cc[i]);
			}
		}
	}
	
	
	return 0;
}