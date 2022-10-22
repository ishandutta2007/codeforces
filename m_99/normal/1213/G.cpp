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
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<int> u(n-1),v(n-1),w(n-1);
	vector<int> t(n-1);
	rep(i,n-1){
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
		u[i]--;v[i]--;
		t[i] = i;
	}
	sort(t.begin(),t.end(),[&](int a,int b){
		return w[a]<w[b];
	});
	
	dsu D(n);
	vector<int> ww(n);
	ww[0] = 0;
	vector<long long> sum(n,0);
	rep(i,n-1){
		int ind = t[i];
		sum[i+1] += (long long)D.size(u[ind])*(long long)D.size(v[ind]);
		D.merge(u[ind],v[ind]);
		sum[i+1] += sum[i];
		ww[1+i] = w[ind];
	}
	sum.push_back(sum.back());
	
	rep(_,m){
		int q;
		scanf("%d",&q);
		int d = distance(ww.begin(),upper_bound(ww.begin(),ww.end(),q));
		d--;
		if(_!=0)printf(" ");
		printf("%lld",sum[d]);
	}
	cout<<endl;
	
	return 0;
}