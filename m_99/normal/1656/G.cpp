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
		int n;
		cin>>n;
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		
		vector<int> cnt(n,0);
		rep(i,n){
			a[i]--;
			cnt[a[i]]++;
		}
		
		int Oc = 0;
		rep(i,n){
			Oc += cnt[i]%2;
		}
		if(Oc>=2 || Oc%2!=n%2){
			printf("NO\n");
			continue;
		}
		
		vector<vector<int>> inds(n);
		int l = 0,r = n-1;
		rep(i,n){
			rep(j,cnt[i]/2){
				inds[i].push_back(l);
				inds[i].push_back(r);
				l++;
				r--;
			}
		}
		if(n%2==1){
			rep(i,n){
				if(cnt[i]%2==1)inds[i].push_back(l);
			}
		}
		dsu D(n);
		vector<int> ans(n);
		rep(i,n){
			ans[i] = inds[a[i]].back();
			inds[a[i]].pop_back();
			D.merge(i,ans[i]);
		}
		
		inds.assign(n,vector<int>());
		rep(i,n){
			inds[a[i]].push_back(i);
		}
		
		rep(i,n){
			if(inds[i].size()>=2){
				int x = inds[i][0];
				rep(j,inds[i].size()){
					int y = inds[i][j];
					if(D.same(x,y))continue;
					swap(ans[x],ans[y]);
					D.merge(x,y);
				}
			}
		}
		auto g = D.groups();
		bool f = true;
		vector<pair<int,int>> p(g.size());
		rep(i,g.size()){
			if(g[i].size()==1)f = false;
			int i0,i1;
			rep(j,g[i].size()){
				if(j==0){
					i0 = g[i][j];
					i1 = g[i][j];
				}
				else{
					int ind = g[i][j];
					if(ans[ind]<ans[i0])i0 = ind;
					if(ans[ind]>ans[i1])i1 = ind;
				}
			}
			p[i] = make_pair(i0,i1);
		}
		rep(i,p.size()-1){
			
			int i0 = p[0].first,j0 = p[0].second,i1 = p[i+1].first,j1 = p[i+1].second;
			int X = ans[j0];
			int Y = ans[i0];
			ans[i0] = ans[i1];
			ans[j0] = ans[j1];
			ans[i1] = X;
			ans[j1] = Y;
			
		}
		if(!f){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		{
			vector<int> tt(n);
			rep(i,n){
				tt[ans[i]] = i;
			}
			swap(tt,ans);
		}
		rep(i,n){
			if(i!=0)printf(" ");
			printf("%d",ans[i]+1);
			//cout<<ans[i]+1<<endl;
		}
		printf("\n");
	}
	
	return 0;
}