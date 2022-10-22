#include <stdio.h>
#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

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
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

int main(){
	
	int n;
	cin>>n;
	
	vector<int> p(n),pos(n);
	rep(i,n){
		scanf("%d",&p[i]);
		p[i]--;
		
		pos[p[i]] = i;
	}
	
	vector<bool> awaked(n,false);
	dsu D(n);
	vector<set<int>> S(n);
	
	rep(i,n){
		S[i].insert(p[i]);
	}
	
	long long ans = 0LL;
	
	rep(i,n){
		int t = pos[i];
		bool f0 = false,f1 = false;
		if(t!=0)f0 = awaked[t-1];
		if(t!=n-1)f1 = awaked[t+1];
		
		if(f0&&f1){
			int x = D.leader(t-1),y = D.leader(t+1);
			D.merge(x,y);
			if(D.leader(x)!=x)swap(x,y);
			for(auto a:S[y]){
				if(S[x].count(i-a-1))ans++;
			}
			for(auto a:S[y]){
				S[x].insert(a);
			}
			S[y].clear();
		}
		
		if(f0||f1){
			int x;
			if(f0)x = D.leader(t-1);
			else x = D.leader(t+1);
			int y = D.leader(t);
			D.merge(x,y);
			if(D.leader(x)!=x)swap(x,y);
			for(auto a:S[y]){
				S[x].insert(a);
			}
			S[y].clear();
		}
		
		awaked[t] = true;
	}
	cout<<ans<<endl;
	return 0;
}