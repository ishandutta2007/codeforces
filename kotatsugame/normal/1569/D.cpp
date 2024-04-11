#include<cstdio>
#include<vector>
#include<algorithm>

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
int T,N,M,K;
atcoder::fenwick_tree<int>SUM(1e6+5);
long long count(vector<pair<int,int> >&P,const vector<int>&B)
{
	sort(P.begin(),P.end());
	long long ret=0;
	for(int i=0;i<P.size();)
	{
		int x=P[i].first;
		int j=i;
		while(j<P.size()&&P[j].first==x)j++;
		for(int k=i;k<j;k++)
		{
			int y=P[k].second;
			int r=lower_bound(B.begin(),B.end(),y)-B.begin();
			int l=r-1;
			ret+=SUM.sum(B[l]+1,B[r]);
		}
		for(int k=i;k<j;k++)SUM.add(P[k].second,1);
		i=j;
	}
	for(int i=0;i<P.size();i++)SUM.add(P[i].second,-1);
	return ret;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d",&N,&M,&K);
		vector<int>Xs(N),Ys(M);
		for(int i=0;i<N;i++)scanf("%d",&Xs[i]);
		for(int i=0;i<M;i++)scanf("%d",&Ys[i]);
		sort(Xs.begin(),Xs.end());
		sort(Ys.begin(),Ys.end());
		vector<pair<int,int> >Px,Py;
		for(int i=0;i<K;i++)
		{
			int x,y;scanf("%d%d",&x,&y);
			bool fx=false,fy=false;
			{
				auto it=lower_bound(Xs.begin(),Xs.end(),x);
				if(it!=Xs.end()&&*it==x)fx=true;
			}
			{
				auto it=lower_bound(Ys.begin(),Ys.end(),y);
				if(it!=Ys.end()&&*it==y)fy=true;
			}
			if(fx&&!fy)
			{
				Px.push_back(make_pair(x,y));
			}
			if(fy&&!fx)
			{
				Py.push_back(make_pair(y,x));
			}
		}
		printf("%lld\n",count(Px,Ys)+count(Py,Xs));
	}
}