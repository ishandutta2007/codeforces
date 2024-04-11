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

vector<long long> a,b;
vector<vector<pair<int,int>>> E;
vector<int> pre;
pair<int,int> pp(-1,-1);
long long mid;
void dfs(int cur,vector<vector<pair<int,int>>> &e,int pe,long long curA){
	
	rep(i,e[cur].size()){
		if(pp.first!=-1)return;
		int to = e[cur][i].first,ind = e[cur][i].second;
		if(ind==pe)continue;
		if(curA <= a[to])continue;
		
		if(to==0 || pre[to]!=-1){
			pp.first = to;
			pp.second = cur;
			return;
			
		}
		else{
			pre[to] = cur;
			dfs(to,e,ind,curA+b[to]);
		}
	}
}

void solve(){
	int n,m;cin>>n>>m;
	
	a.resize(n),b.resize(n);
	a[0] = 0,b[0] = 0;
	rep(i,n-1){
		cin>>a[i+1];
	}
	rep(i,n-1){
		cin>>b[i+1];
	}
	E.assign(n,vector<pair<int,int>>());
	rep(i,m){
		int x,y;
		cin>>x>>y;
		x--;y--;
		E[x].emplace_back(y,i);
		E[y].emplace_back(x,i);
	}
	
	long long ok = Inf,ng = 0;
	
	
	while(ok-ng>1LL){
		mid = (ok+ng)/2;
		
		dsu D(n);
		long long cur = mid;
		bool f = true;
		auto e = E;
		
		while(D.size(0)!=n){
			pp = make_pair(-1,-1);
			pre.assign(n,-1);
			dfs(0,e,-1,cur);
			if(pp.first==-1){
				f = false;
				break;
			}
			{
				int temp = pp.first;
				while(temp!=-1){
					if(!D.same(0,temp)){
						D.merge(0,temp);
						cur += b[temp];
					}
					temp = pre[temp];
				}
			}
			{
				int temp = pp.second;
				while(temp!=-1){
					if(!D.same(0,temp)){
						D.merge(0,temp);
						cur += b[temp];
					}
					temp = pre[temp];
				}
			}
			
			vector<vector<pair<int,int>>> ee(n);
			rep(i,n){
				int from = i;
				if(D.same(i,0))from = 0;
				rep(j,e[i].size()){
					int to = e[i][j].first,ind = e[i][j].second;
					if(D.same(to,0))to = 0;
					if(from==to)continue;
					ee[from].emplace_back(to,ind);
				}
			}
			swap(e,ee);
		
			
		}
		if(f){
			ok = mid;
		}
		else{
			ng = mid;
		}
		
	}
	
	cout<<ok<<endl;
	
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		solve();
	}
		
	
	return 0;
}