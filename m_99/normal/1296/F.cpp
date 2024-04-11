#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

vector<int> get(vector<vector<int>> &E,int s){
	int n = E.size();
	vector<int> ret(n,Inf);
	ret[s] = 0;
	queue<int> Q;
	Q.push(s);
	
	while(Q.size()>0){
		int u = Q.front();
		Q.pop();
		
		rep(i,E[u].size()){
			int v = E[u][i];
			if(ret[v]==Inf){
				ret[v] = ret[u]+1;
				Q.push(v);
			}
		}
	}
	return ret;
}

int main(){
	
	int n;
	cin>>n;
	
	vector<vector<int>> E(n);
	vector<int> a(n-1),b(n-1);
	rep(i,n-1){
		cin>>a[i]>>b[i];
		a[i]--;b[i]--;
		E[a[i]].push_back(b[i]);
		E[b[i]].push_back(a[i]);
	}
	
	vector<vector<int>> dis(n);
	rep(i,n){
		dis[i] = get(E,i);
	}
	
	vector<int> ans(n-1,1000000);
	int m;
	cin>>m;
	vector<int> x(m),y(m),f(m);
	vector<pair<int,int>> P(m);
	rep(i,m){
		cin>>x[i]>>y[i]>>f[i];
		x[i]--;y[i]--;
		P[i] = make_pair(f[i],i);
	}
	
	sort(P.begin(),P.end());
	
	rep(i,m){
		int xx = x[P[i].second],yy = y[P[i].second];
		rep(j,n-1){
			if(min(dis[xx][a[j]] + dis[b[j]][yy]+1,dis[yy][a[j]] + dis[b[j]][xx]+1) == dis[xx][yy]){
				ans[j] = P[i].first;
			}
		}
	}
	
	rep(i,m){
		int xx = x[P[i].second],yy = y[P[i].second];
		int mini = 1000000;
		rep(j,n-1){
			if(min(dis[xx][a[j]] + dis[b[j]][yy]+1,dis[yy][a[j]] + dis[b[j]][xx]+1) == dis[xx][yy]){
				mini = min(mini,ans[j]);
			}
		}
		if(mini!=P[i].first){
			cout<<-1<<endl;
			return 0;
		}
	}
	
	rep(i,n-1){
		if(i!=0)cout<<' ';
		cout<<ans[i];
	}
	cout<<endl;
	
	
	
	return 0;
}