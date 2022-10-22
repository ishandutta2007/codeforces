#include <stdio.h>
#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

using namespace atcoder;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

long long get(vector<long long> &a,long long t){
	int n = a.size();
	long long ret = 0;
	long long M = 1000000000000000000;
	for(int i=1;i<n-1;i++){
		long long x = a[0] * a[i] + t * (a[0]+a[i]);
		long long y = a[n-1] * a[i] + t * (a[n-1]+a[i]);
		if(x>y)swap(x,y);
		ret += x;
		M = min(M,y);
	}
	M = min(M,a[0]*a[n-1] + t * (a[0]+a[n-1]));
	ret += M;
	return ret;
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		vector<long long> a(n);
		rep(i,n)scanf("%lld",&a[i]);
		sort(a.begin(),a.end());
		{
			long long T = 0;
			rep(i,n-1){
				T += a[0] + a[i+1];
			}
			if(T>0){
				cout<<"INF"<<endl;
				continue;
			}
		}
		
		{
			long long T = 0;
			rep(i,n-1){
				T += a[n-1] + a[i];
			}
			if(T<0){
				cout<<"INF"<<endl;
				continue;
			}
		}
		long long l = -3000000,r = 3000000;
		while(r-l>=2){
			long long m0 = l + (r-l)/3;
			long long m1 = m0 + (r-l)/3;
			if(get(a,m0)<get(a,m1))l = m0;
			else r = m1;
			
		}
		
		long long ans= -1000000000000000000;
		for(int i=l-1;i<=r+1;i++){
			ans = max(ans,get(a,i));
		}
		printf("%lld\n",ans);
			
		
	}
	
	return 0;
}