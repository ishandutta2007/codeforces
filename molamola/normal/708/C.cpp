#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

int n;
vector <int> E[400040];
int sub[400040];
int down[400040];

int dfs(int x,int fa){
	int cnt = 1;
	int mn = 1e8;
	for(auto i : E[x]){
		if(i != fa){
			int temp = dfs(i, x);
			mn = min(mn, temp);
			cnt += temp;
		}
	}
	sub[x] = (mn == 1e8 ? 0 : mn);
	return down[x] = cnt;
}

int ans[400040];
int ct;

void predfs(int x, int fa){
	down[x] = 1;
	for(auto i : E[x]){
		if(i != fa){
			predfs(i, x);
			down[x] += down[i];
		}
	}
}

int find_mid(int x){
	while(1){
		int ok = 1, temp = -1;
		for(auto i : E[x]){
			if(down[i] < down[x] && down[i] > n / 2){
				ok = 0;
				temp = i;
				break;
			}
		}
		if(ok)return x;
		x = temp;
	}
}

multiset <int> S[400040], SS;
vector <int> gr[400040];

void dfs2(int x, int fa, int cnt){
	S[cnt].insert(down[x]);
	gr[cnt].pb(x);
	for(auto i : E[x]){
		if(i != fa){
			dfs2(i, x, cnt);
		}
	}
}

void solve(int tc){
	scanf("%d", &n);
	rep(i, n-1){
		int x, y; scanf("%d%d", &x, &y);
		E[x].pb(y);
		E[y].pb(x);
	}
	predfs(1, -1);
	ct = find_mid(1);
	ans[ct] = 1;
	dfs(ct, -1);
	int cnt = 0, z = sz(E[ct]);
	for(auto u : E[ct]){
		dfs2(u, ct, cnt++);
	}
	for(int i=1;i<z;i++){
		for(auto u : S[i])SS.insert(u);
	}
	SS.insert(n - down[E[ct][0]]);
	for(int i=0;i<z;i++){
		//for(auto i : SS)printf("%d ", i); puts("");
		for(auto j : gr[i]){
			int mx = n - down[j];
			int mn = 0;
			if(mx <= n / 2)ans[j] = 1;
			else{
				int x = (mx + mx - n + 1) / 2;
				int y = (n - mn - mn) / 2;
				auto it = SS.lower_bound(x);
				auto jt = SS.upper_bound(y);
				if(it != jt)ans[j] = 1;
				else ans[j] = 0;
			}
		}
		if(i != z-1)for(auto u : S[i])SS.insert(u);
		if(i != z-1)for(auto u : S[i+1])SS.erase(SS.find(u));
		if(i != z-1)SS.erase(SS.find(n - down[E[ct][i]]));
		if(i != z-1)SS.insert(n - down[E[ct][i+1]]);
	}
	for(int i=1;i<=n;i++)printf("%d ", ans[i]);
}

int main(){
	int Tc = 1;//; scanf("%d", &Tc);
	for(int tc=1; tc<=Tc; tc++){
		solve(tc);
	}
	return 0;
}