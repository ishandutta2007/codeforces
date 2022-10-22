#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000
int n;
vector<vector<int>> E;
vector<int> p;
vector<int> d;
vector<int> c;
void dfs(int cur,int par,int depth){
	d[cur] = depth;
	p[cur] = par;
	rep(i,E[cur].size()){
		int to = E[cur][i];
		if(to==par)continue;
		c[cur]++;
		dfs(to,cur,depth+1);
	}
}

int main(){
	cin>>n;
	E.resize(n);
	p.resize(n,-1);
	
	rep(i,n-1){
		int x,y;
		scanf("%d %d",&x,&y);
		x--;y--;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	d.resize(n,0);
	c.resize(n,0);
	dfs(0,-1,0);
	
	vector<pair<int,int>> L(n);
	rep(i,n){
		L[i] = make_pair(c[i],i);
	}
	sort(L.rbegin(),L.rend());
	
	int q;
	cin>>q;
	
	vector<vector<pair<int,int>>> qs(200003);
	rep(i,q){
		int v,k;
		scanf("%d %d",&v,&k);
		v--;
		qs[k].emplace_back(v,i);
	}
	//rep(i,n)cout<<c[i]<<endl;
	
	vector<int> ans(q);
	vector<int> dp(n,0);
	vector<bool> f(n,false);
	rep(i,200003){
		priority_queue<pair<int,int>> Q;
		rep(j,n){
			if(L[j].first <= i+1)break;
			Q.emplace(d[L[j].second],L[j].second);
			f[L[j].second] = true;
		}
		vector<int> x;
		while(Q.size()>0){
			pair<int,int> t = Q.top();
			Q.pop();
			dp[t.second] -= i+1;
			dp[t.second] += c[t.second];
			x.push_back(t.second);
			if(dp[t.second]<=0){
				continue;
			}
			x.push_back(t.second);
			int pp = p[t.second];
			if(pp==-1)continue;
			dp[pp] += dp[t.second];
			if(f[pp])continue;
			f[pp] = true;
			Q.emplace(d[pp],pp);
		}
		/*
		if(i==3){
			rep(j,n){
			//	cout<<dp[j]<<endl;
			}
		}
		*/
		
		rep(j,qs[i].size()){
			int v = qs[i][j].first;
			int ind  =qs[i][j].second;
			if(f[v]==false){
				ans[ind] = c[v] - (i+1);
			}
			else{
				ans[ind] = max(c[v]-(i+1), dp[v]);
			}
			ans[ind] += i+1;
		}
		rep(j,x.size()){
			f[x[j]] = false;
			dp[x[j]] = 0;
		}
	//	if(i==2)cout<<dp[0]<<endl;
	}
	
	rep(i,q){
		printf("%d\n",ans[i]);
	}
	
	return 0;
	
}