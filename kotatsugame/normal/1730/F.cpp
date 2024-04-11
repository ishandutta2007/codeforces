#include<iostream>
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

#include<cassert>
using namespace std;
int N,K;
int P[5000],invP[5000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>K;
	for(int i=0;i<N;i++)
	{
		cin>>P[i];
		P[i]--;
		invP[P[i]]=i;
	}
	vector<pair<int,int> >now,nxt;
	now.push_back(make_pair(0,0));
	vector<int>cnt(2*K+1);
	vector<int>need(2*K+1);
	atcoder::fenwick_tree<int>BIT(N);
	for(int i=0;i<N;i++)
	{
		if(i>K)BIT.add(invP[i-K-1],1);
		nxt.clear();
		for(int t=-K;t<=K;t++)
		{
			if(i+t<0||i+t>=N)continue;
			cnt[t+K]=BIT.sum(invP[i+t],N);
			need[t+K]=0;
			for(int u=-K;u<=K;u++)
			{
				if(i+u<0||i+u>=N)continue;
				if(invP[i+u]>invP[i+t])need[t+K]|=1<<u+K;
			}
		}
		for(pair<int,int>p:now)
		{
			int j=p.first;
			{
				int d=max(K-i,0);
				int m=__builtin_ctz(~(j>>d))+d;
				//while(j>>m&1)m++;
				if(j>>m+K+1)continue;
			}
			for(int t=max(-K,-i);t<=K&&t<N-i;t++)
			{
				if(j>>t+K&1)continue;
				if(j>>t+K+K+1)continue;
				int nj=j;nj|=1<<t+K;
				nj>>=1;
				int c=p.second+cnt[t+K];
				c+=__builtin_popcount(j&need[t+K]);
				//for(int u=-K;u<=K;u++)if(j>>u+K&1&&invP[i+u]>invP[i+t])c++;
				nxt.push_back(make_pair(nj,c));
			}
		}
		sort(nxt.begin(),nxt.end());
		now.clear();
		for(int j=0;j<nxt.size();)
		{
			int v=nxt[j].first;
			int c=nxt[j].second;
			now.push_back(make_pair(v,c));
			j++;
			while(j<nxt.size()&&nxt[j].first==v)j++;
		}
	}
	cout<<now[0].second<<endl;
}