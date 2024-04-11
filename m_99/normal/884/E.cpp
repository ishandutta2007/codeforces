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
#define Inf 1000000300000000000

int get(char &c){
	if(isdigit(c))return c-'0';
	return 10 + (c-'A');
}

int main(){	
	
	int n,m;
	cin>>n>>m;
	
	vector<int> B(m>>2,0);
	vector<int> newB(m>>2);
	dsu D(m);
	int ans = 0;
	vector<int> pa(m,-1);
	char s[1<<12];
	rep(i,n){
		scanf("%s",s);
		
		rep(j,m>>2){
			newB[j] = get(s[j]);
		}
		
		if((newB[0]>>3)!=0){
			if((B[0]>>3)==0)ans++;
		}
		
		for(int j=1;j<m;j++){
			if(((newB[j>>2]>>(3-(j&3)))&1)==0)continue;
			
			
			if(((B[j>>2]>>(3-(j&3)))&1)){
				if(((newB[(j-1)>>2]>>(3-((j-1)&3)))&1)){
					if(!D.same(j,j-1))ans--;
					D.merge(j-1,j);
				}
			}
			else if(((newB[(j-1)>>2]>>(3-((j-1)&3)))&1)){
				D.merge(j,j-1);
			}
			else{
				ans++;
			}
			
		}
		
		
		dsu newD(m);
		pa.assign(m,-1);
		rep(j,m){
			if(((newB[j>>2]>>(3-(j&3)))&1)){
				if(pa[D.leader(j)]==-1)pa[D.leader(j)] = j;
				else newD.merge(j,pa[D.leader(j)]);
			}
		}
		
		
		swap(B,newB);
		swap(D,newD);
	}
	
	cout<<ans<<endl;
	
    return 0;
}