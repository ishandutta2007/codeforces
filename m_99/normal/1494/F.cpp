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
#define Inf 1200000000
vector<vector<pair<int,int>>> E;
vector<bool> used;
vector<int> d;
vector<int> a(1,-1);
vector<int> b;
bool check(int ss){
	dsu D(E.size());
	rep(i,E.size()){
		rep(j,E[i].size()){
			if(used[E[i][j].second])continue;
			D.merge(i,E[i][j].first);
		}
	}
	int m = E.size();
	rep(i,E.size()){
		int s = D.size(i);
		if(s==1)m--;
	}
	if(m==0)return true;
	if(D.size(ss)!=m)return false;
	return true;
}

void dfs(int cur){
	rep(i,E[cur].size()){
		int to = E[cur][i].first,ind = E[cur][i].second;
		if(used[ind])continue;
		used[ind] = true;
		dfs(to);
	}
	b.push_back(cur);
}

void ans(int s,int t){
	//cout<<s<<','<<t<<endl;
	rep(i,E[t].size()){
		int to = E[t][i].first,ind = E[t][i].second;
		if(used[ind]){
			a.push_back(to);
			a.push_back(t);
		}
	}
	dfs(t);
	
	rep(i,a.size()){
		b.push_back(a[i]);
	}
	
	cout<<b.size()<<endl;
	
	rep(i,b.size()){
		if(i!=0)printf(" ");
		int x = b[i];
		if(x!=-1)x++;
		printf("%d",x);
	}
	cout<<endl;
	exit(0);
	
}

int main(){
	
	int n,m;
	scanf("%d %d",&n,&m);
	E.resize(n);

	used.resize(m,false);
	d.resize(n,0);
	rep(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		x--;y--;
		
		E[x].emplace_back(y,i);
		E[y].emplace_back(x,i);
		d[x] ++;
		d[y] ++;
	}
	
	
	
	rep(i,n){
		
		vector<int> x;
		rep(j,E[i].size()){
			int to = E[i][j].first;
			if(d[to]&1){
				x.push_back(j);
				d[to]--;
				d[i]--;
				used[E[i][j].second] = true;
			}
		}
		
		vector<int> y;
		rep(j,n){
			if(d[j]&1)y.push_back(j);
		}
		
		if(y.size()==0){
			if(check(i)){
				
				ans(i,i);
				
			}
			else{
				rep(j,E[i].size()){
					int to = E[i][j].first,ind = E[i][j].second;
					if(used[ind]){
						d[to]++;
						d[i]++;
						used[ind] = false;
						if(check(i)){
							ans(E[i][x[j]].first,i);
						}
						d[to]--;
						d[i]--;
						used[ind] = true;
					}
				}
				
			}
		}
		else if(y.size()==2&&(d[i]&1)){
			if(check(i)){
				if(y[0]==i)swap(y[0],y[1]);
				ans(y[0],y[1]);
				
			}
		}
		
		rep(j,x.size()){
			d[E[i][x[j]].first]++;
			d[i]++;
			used[E[i][x[j]].second] = false;
		}
		
	}
		
		
	
	cout<<0<<endl;
	
    return 0;
}