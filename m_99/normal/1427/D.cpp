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
#define Inf 1000000000


int main(){	

	int n;
	cin>>n;
	
	vector<int> a(n);
	rep(i,n){
		cin>>a[i];
	}
	
	vector<vector<vector<int>>> ans;
	
	while(true){
		dsu D(n);
		
		rep(i,n-1){
			if(a[i]+1==a[i+1]){
				D.merge(i,i+1);
			}
		}
		
		if(D.size(0)==n)break;
		
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a[i]==a[j]+1){
					
					for(int k=i;k<n;k++){
						if(D.leader(k)==D.leader(j))break;
						D.merge(i,k);
					}
					goto L;
				}
			}
		}
		L:;
		
		vector<vector<int>> temp(1,vector<int>());
		
		rep(i,n){
			if(i==0 || D.leader(i)==D.leader(i-1))temp.back().push_back(i);
			else{
				temp.push_back(vector<int>(1,i));
			}
		}
		
		vector<int> b;
		ans.push_back(temp);
		
		
		reverse(temp.begin(),temp.end());
		
		rep(i,temp.size()){
			rep(j,temp[i].size()){
				b.push_back(a[temp[i][j]]);
			}
		}
		
		swap(a,b);
		
	}
	
	cout<<ans.size()<<endl;
	rep(i,ans.size()){
		cout<<ans[i].size();
		rep(j,ans[i].size()){
			cout<<' ';
			cout<<ans[i][j].size();
		}
		cout<<endl;
	}
	
    return 0;
}