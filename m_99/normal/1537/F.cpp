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

bool check(vector<vector<int>> E,vector<long long> s,vector<long long> t){
	long long s0 = 0,s1 = 0;
	rep(i,s.size()){
		s0 += s[i];
		s1 += t[i];
	}
	if(abs(s0-s1)%2==1)return false;
	bool f = false;
	queue<int> Q;
	vector<int> color(E.size(),-1);
	Q.push(0);
	color[0] = 0;
	while(Q.size()>0){
		int u = Q.front();
		Q.pop();
		rep(i,E[u].size()){
			int v = E[u][i];
			if(color[v]==-1){
				color[v] = color[u] ^ 1;
				Q.push(v);
			}
			if(color[u]==color[v]){
				f = true;
				break;
			}
		}
		if(f)break;
	}
	if(f)return true;
	s0 = 0,s1 = 0;
	long long t0 = 0,t1 = 0;
	rep(i,s.size()){
		if(color[i]==0){
			s0 += s[i];
			t0 += t[i];
		}
		else{
			s1 += s[i];
			t1 += t[i];
		}
	}
	if(s0-t0==s1-t1)return true;
	return false;
	
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n,m;
		scanf("%d %d",&n,&m);
		
		vector<long long> s(n),t(n);
		rep(i,n)scanf("%lld",&s[i]);
		rep(i,n)scanf("%lld",&t[i]);
		
		dsu D(n);
		vector<int> a(m),b(m);
		rep(i,m){
			scanf("%d %d",&a[i],&b[i]);
			a[i]--;b[i]--;
			D.merge(a[i],b[i]);
		}
		
		auto g = D.groups();
		
		vector<int> gind(n),gpos(n);
		rep(i,g.size()){
			sort(g[i].begin(),g[i].end());
			rep(j,g[i].size()){
				int u = g[i][j];
				gind[u] = i;
				gpos[u] = j;
			}
		}
		
		vector<vector<vector<int>>> E(g.size());
		vector<vector<long long>> ss(g.size()),tt(g.size());
		rep(i,g.size()){
			E[i].resize(g[i].size());
		}
		rep(i,n){
			ss[gind[i]].push_back(s[i]);
			tt[gind[i]].push_back(t[i]);
		}
		
		rep(i,m){
			int ind = gind[a[i]];
			int x = gpos[a[i]],y = gpos[b[i]];
			E[ind][x].push_back(y);
			E[ind][y].push_back(x);
		}
		
		bool f  =true;
		
		rep(i,g.size()){
			if(check(E[i],ss[i],tt[i]))continue;
			f=false;
			break;
		}
		
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}