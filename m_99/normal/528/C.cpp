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
vector<int> aa,bb;

void dfs(int cur,int p,vector<vector<int>> &E,vector<int> &d){
	rep(i,E[cur].size()){
		int to = E[cur][i];
		if(to==p)continue;
		dfs(to,cur,E,d);
	}
	if(p!=-1){
		if(d[cur]==0){
			aa.push_back(p);
			bb.push_back(cur);
			d[p] ^= 1;
		}
		else{
			aa.push_back(cur);
			bb.push_back(p);
			d[cur] ^= 1;
		}
	}
}

int main(){
	
	int n,m;
	scanf("%d %d",&n,&m);
	
	vector<int> a(m),b(m);
	vector<int> c(n,0);
	rep(i,m){
		scanf("%d %d",&a[i],&b[i]);
		a[i]--;b[i]--;
		c[a[i]]++;
		c[b[i]]++;
	}
	vector<int> t;
	rep(i,n){
		if(c[i]%2==1){
			t.push_back(i);
		}
	}
	//cout<<t.size()<<endl;
	rep(i,t.size()/2){
		a.push_back(t[i*2]);
		b.push_back(t[i*2+1]);
	}
	
	vector<vector<int>> E(n);
	
	dsu D(n);
	vector<int> d(n,0);
	rep(i,a.size()){
		if(D.same(a[i],b[i])){
			d[a[i]]^=1;
			aa.push_back(a[i]);
			bb.push_back(b[i]);
		}
		else{
			D.merge(a[i],b[i]);
			E[a[i]].push_back(b[i]);
			E[b[i]].push_back(a[i]);
		}
	}
	
	rep(i,n){
		if(D.leader(i)!=i)continue;
		dfs(i,-1,E,d);
	}
	
	rep(i,n){
		if(d[i]){
			aa.push_back(i);
			bb.push_back(i);
		}
	}
	
	cout<<aa.size()<<endl;
	
	rep(i,aa.size()){
		printf("%d %d\n",aa[i]+1,bb[i]+1);
	}
	return 0;
}