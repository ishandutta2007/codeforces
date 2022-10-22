#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001
int n;
vector<vector<int>> E;
vector<long long> h;
vector<long long> x,y,m;

void dfs(int cur,int p){
	m[cur] = 0;
	x[cur] = 0;
	y[cur] = 0;
	vector<long long> t;
	rep(i,E[cur].size()){
		int to = E[cur][i];
		if(to==p)continue;
		dfs(to,cur);
		m[cur] = max(m[cur],m[to]);
		x[cur] += x[to];
		y[cur] += x[to];
		t.push_back(y[to] - x[to]);
	}
	x[cur] += max(0LL,h[cur] - m[cur]);
	m[cur] = max(m[cur],h[cur]);
	
	sort(t.begin(),t.end());
	if(t.size()>0)y[cur] += t[0];
}

int main(){
	cin>>n;
	E.resize(n);
	h.resize(n);
	rep(i,n)scanf("%lld",&h[i]);
	
	rep(i,n-1){
		int u,v;
		scanf("%d %d",&u,&v);
		u--;v--;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	int ind = 0;
	rep(i,n){
		if(h[ind]<h[i])ind = i;
	}
	x.resize(n);
	y.resize(n);
	m.resize(n);
	dfs(ind,-1);
	
	/*
	rep(i,n)cout<<x[i]<<',';
	cout<<endl;
	rep(i,n)cout<<y[i]<<',';
	cout<<endl;
	*/
	
	long long ans = h[ind]*2;
	vector<long long> t;
	rep(i,E[ind].size()){
		int to = E[ind][i];
		ans += x[to];
		t.push_back(y[to] - x[to]);
	}
	sort(t.begin(),t.end());
	
	int ii = t.size();
	rep(i,min(2,ii)){
		ans += t[i];
	}
	
	cout<<ans<<endl;
	
	return 0;
}