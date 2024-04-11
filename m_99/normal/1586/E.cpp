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
vector<int> u,v;

void dfs(int cur,int p,vector<vector<int>> &dp,vector<vector<int>> &E,vector<int> &cnt){
	int C = 0;
	int sum  =0;
	rep(i,E[cur].size()){
		int ind = E[cur][i];
		int to = u[ind] ^ v[ind] ^ cur;
		if(to==p)continue;
		dfs(to,cur,dp,E,cnt);
		if(cnt[ind]){
			C++;
			sum += min(dp[to][0]+1,dp[to][1]);
		}
		else{
			sum += min(dp[to][0],dp[to][1]);
		}
		
	}
	dp[cur][C%2] = sum - C/2;
}

int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> E(n);
	
	dsu D(n);
	rep(i,m){
		int uu,vv;
		scanf("%d %d",&uu,&vv);
		uu--;vv--;
		if(D.same(uu,vv))continue;
		E[uu].push_back(u.size());
		E[vv].push_back(u.size());
		D.merge(uu,vv);
		u.push_back(uu);
		v.push_back(vv);
	}
	
	int _q;
	cin>>_q;
	vector<int> cnt(n-1,0);
	vector<vector<int>> ans(_q);
	rep(_,_q){
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		queue<int> Q;
		Q.push(a);
		vector<int> pre(n,Inf);
		pre[a] = -1;
		while(Q.size()>0){
			int x = Q.front();
			Q.pop();
			rep(i,E[x].size()){
				int ind = E[x][i];
				int y = u[ind] ^ v[ind] ^ x;
				if(pre[y]==Inf){
					pre[y] = ind;
					Q.push(y);
				}
			}
		}
		ans[_].push_back(b);
		while(b!=a){
			cnt[pre[b]] ^= 1;
			int nxt = b ^ u[pre[b]] ^ v[pre[b]];
			ans[_].push_back(nxt);
			b = nxt;
		}
		
		
	}
	
	if(cnt == vector<int>(n-1,0)){
		cout<<"YES"<<endl;
		rep(i,ans.size()){
			printf("%d\n",ans[i].size());
			reverse(ans[i].begin(),ans[i].end());
			rep(j,ans[i].size()){
				if(j!=0)printf(" ");
				printf("%d",ans[i][j]+1);
			}
			printf("\n");
		}
		
	}
	else{
		cout<<"NO"<<endl;
		vector dp(n,vector<int>(2,Inf));
		dfs(0,-1,dp,E,cnt);
		int ans = min(dp[0][0],dp[0][1]);
		printf("%d\n",ans);
	}
	
	return 0;
}