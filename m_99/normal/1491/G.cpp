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
#define Inf 1000000001
vector<int> c;

vector<int> x,y;
void Swap(int a,int b){
	swap(c[a],c[b]);
	c[a]*=-1;
	c[b]*=-1;
	x.push_back(a);
	y.push_back(b);
}

int main(){
	
	int n;
	cin>>n;
	c.resize(n);
	
	rep(i,n){
		scanf("%d",&c[i]);
	}
	
	dsu D(n);
	rep(i,n){
		D.merge(i,c[i]-1);
	}
	
	
	
	vector<vector<int>> g;
	{
		auto gg = D.groups();
		rep(i,gg.size()){
			if(gg[i].size()>1){
				g.push_back(gg[i]);
			}
		}
	}
	
	while(g.size()>=2){
		vector<int> p0 = g.back();
		g.pop_back();
		vector<int> p1 = g.back();
		g.pop_back();
		Swap(p0[0],p1[0]);
		
		while(true){
			int xx = abs(c[p0[0]])-1;
			if(c[xx]<0)break;
			Swap(xx,p0[0]);
		}
		while(true){
			int xx = abs(c[p1[0]])-1;
			if(c[xx]<0)break;
			Swap(xx,p1[0]);
		}
		Swap(p0[0],p1[0]);
	}
	
	if(g.size()==1){
		vector<int> p = g[0];
		if(p.size()==2){
			int ind = 0;
			rep(i,n){
				if(c[i]==i+1){
					ind = i;
					break;
				}
			}
			Swap(ind,p[0]);
			Swap(ind,p[1]);
			Swap(ind,p[0]);
			
		}
		else{
			
			int f = p[0];
			int s = c[p[0]]-1;
			
			Swap(f,s);
			
			rep(i,p.size()){
				if(c[p[i]]-1 == f){
					Swap(s,p[i]);
					break;
				}
			}
			while(c[f]<0){
				Swap(f,abs(c[f])-1);
			}
			
		}
	}
	
	rep(i,n){
		if(i!=c[i]-1){
			cout<<"OMG"<<endl;
			return 0;
		}
	}
	
	cout<<x.size()<<endl;
	rep(i,x.size()){
		printf("%d %d\n",x[i]+1,y[i]+1);
	}
	
	
    return 0;
}