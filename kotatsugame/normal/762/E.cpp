#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

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

using namespace std;
int N,K;
vector<int>X[10101];
atcoder::fenwick_tree<int>P[10101];
main()
{
	cin>>N>>K;
	vector<pair<int,pair<int,int> > >F;
	for(int i=0;i<N;i++)
	{
		int x,r,f;cin>>x>>r>>f;
		F.push_back(make_pair(x,make_pair(r,f)));
	}
	sort(F.begin(),F.end());
	for(pair<int,pair<int,int> >p:F)X[p.second.second].push_back(p.first);
	for(int i=0;i<10101;i++)
	{
		P[i]=atcoder::fenwick_tree<int>(X[i].size());
	}
	priority_queue<pair<int,pair<int,int> > >Q;
	long long ans=0;
	for(pair<int,pair<int,int> >p:F)
	{
		int x=p.first,r=p.second.first,f=p.second.second;
		while(!Q.empty()&&-Q.top().first<x)
		{
			pair<int,pair<int,int> >q=Q.top();Q.pop();
			int f=q.second.second,x=-q.first-q.second.first;
			P[f].add(lower_bound(X[f].begin(),X[f].end(),x)-X[f].begin(),-1);
		}
		int lx=x-r;
		for(int tf=f-K;tf<=f+K;tf++)if(tf>=0&&tf<10101)
		{
			ans+=P[tf].sum(lower_bound(X[tf].begin(),X[tf].end(),lx)-X[tf].begin(),
				lower_bound(X[tf].begin(),X[tf].end(),x)-X[tf].begin());
		}
		P[f].add(lower_bound(X[f].begin(),X[f].end(),x)-X[f].begin(),1);
		Q.push(make_pair(-(x+r),make_pair(r,f)));
	}
	cout<<ans<<endl;
}