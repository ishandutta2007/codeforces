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


int main(){
	
	
	int _t;
	cin>>_t;
	rep(_,_t){
		
		int n,k;
		scanf("%d %d",&n,&k);
		
		map<int,vector<pair<int,int>>> xy,yx;
		vector<int> x(n),y(n),t(n);
		rep(i,n){
			scanf("%d %d %d",&x[i],&y[i],&t[i]);
			xy[x[i]].emplace_back(y[i],i);
			yx[y[i]].emplace_back(x[i],i);
		}
		
		dsu D(n);
		for(auto a:xy){
			auto v = a.second;
			sort(v.begin(),v.end());
			rep(i,v.size()-1){
				if(abs(v[i+1].first-v[i].first)<=k){
					D.merge(v[i].second,v[i+1].second);
				}
			}
		}
		for(auto a:yx){
			auto v = a.second;
			sort(v.begin(),v.end());
			rep(i,v.size()-1){
				if(abs(v[i+1].first-v[i].first)<=k){
					D.merge(v[i].second,v[i+1].second);
				}
			}
		}
		
		auto g = D.groups();
		vector<int> v(g.size(),Inf);
		rep(i,g.size()){
			rep(j,g[i].size()){
				v[i] = min(v[i],t[g[i][j]]);
			}
		}
		
		sort(v.begin(),v.end());
		int ok = Inf,ng = -1;
		while(ok-ng>1){
			int mid = (ok+ng)/2;
			int cnt = v.size();
			rep(i,v.size()){
				if(v[i] <= mid)cnt--;
			}
			cnt -= mid+1;
			if(cnt<=0)ok = mid;
			else ng = mid;
		}
		printf("%d\n",ok);
		
	}
	return 0;
}