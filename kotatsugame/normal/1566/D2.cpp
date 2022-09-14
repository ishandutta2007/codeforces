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
int T,N,M;
int s[300][300];
pair<int,int>si[300];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		vector<pair<int,int> >A(N*M);
		for(int i=0;i<N*M;i++)
		{
			int a;scanf("%d",&a);
			A[i]=make_pair(a,i);
		}
		sort(A.begin(),A.end());
		for(int i=0;i<A.size();)
		{
			int a=A[i].first;
			int j=i;
			while(j<A.size()&&A[j].first==a)j++;
			if(i/M<j/M)
			{
				int ri=i/M,rj=i%M,rc=M-i%M;
				for(int k=0;k<rc;k++)s[ri][rj+rc-k-1]=A[i+k].second;
				i+=rc;
				while(i/M<j/M)
				{
					int ri=i/M;
					for(int k=0;k<M;k++)s[ri][M-k-1]=A[i+k].second;
					i+=M;
				}
			}
			int ri=i/M,rj=i%M;
			for(int k=0;k<j-i;k++)s[ri][rj+j-i-k-1]=A[i+k].second;
			i=j;
		}
		long long ans=0;
		for(int i=0;i<N;i++)
		{
			atcoder::fenwick_tree<int>P(M);
			for(int j=0;j<M;j++)si[j]=make_pair(s[i][j],j);
			sort(si,si+M);
			for(int j=0;j<M;j++)
			{
				ans+=P.sum(0,si[j].second);
				P.add(si[j].second,1);
			}
		}
		printf("%lld\n",ans);
	}
}