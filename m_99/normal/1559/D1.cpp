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
	
	int n;
	int m[2];
	cin>>n>>m[0]>>m[1];
	
	vector<vector<int>> u(2),v(2);
	
	rep(i,2){
		u[i].resize(m[i]),v[i].resize(m[i]);
		rep(j,m[i]){
			scanf("%d %d",&u[i][j],&v[i][j]);
			u[i][j]--;
			v[i][j]--;
			
		}
	}
	{
		dsu D0(n),D1(n);
		rep(i,m[0]){
			D0.merge(u[0][i],v[0][i]);
		}
		rep(i,m[1]){
			//cout<<u[1][i]<<','<<v[1][i]<<endl;
			D1.merge(u[1][i],v[1][i]);
		}
		
		int c0 = 0,c1 = 0;
		rep(i,n){
			if(D0.leader(i)==i)c0++;
			if(D1.leader(i)==i)c1++;
		}
		
		if(c0>c1){
			swap(u[0],u[1]);
			swap(v[0],v[1]);
			swap(m[0],m[1]);
		}
	}
	
	dsu D0(n),D1(n);
	rep(i,m[0]){
		D0.merge(u[0][i],v[0][i]);
	}
	rep(i,m[1]){
		//cout<<u[1][i]<<','<<v[1][i]<<endl;
		D1.merge(u[1][i],v[1][i]);
	}
		
	
	vector<int> a,b;
	rep(i,n){
		rep(j,n){
			if(D0.same(i,j)||D1.same(i,j))continue;
			a.push_back(i);
			b.push_back(j);
			D0.merge(i,j);
			D1.merge(i,j);
		}
	}
	
	cout<<a.size()<<endl;
	rep(i,a.size()){
		printf("%d %d\n",a[i]+1,b[i]+1);
	}
	
	return 0;
}