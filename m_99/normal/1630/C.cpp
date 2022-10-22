#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int get(vector<pair<int,int>> lr){
	int n = lr.size();
	int m = Inf,M = -Inf;
	rep(i,n){
		m = min(m,lr[i].first);
		M = max(M,lr[i].second);
	}
	
	rep(i,n){
		lr[i].first -= m;
		lr[i].second -= m;
	}
	int x = M-m+1;
	vector<vector<int>> E(M-m+1);

	rep(i,n){
		E[lr[i].first].push_back(lr[i].second);
	}
	
	vector<int> dis(x,Inf);
	dis[0] = 0;
	deque<int> Q;
	Q.push_back(0);
	while(Q.size()>0){
		int u = Q.front();
		Q.pop_front();
		rep(i,E[u].size()){
			int v = E[u][i];
			if(dis[v] > dis[u]+1){
				dis[v] = dis[u]+1;
				Q.push_back(v);
			}
		}
		if(u!=0){
			int v = u-1;
			if(dis[v] > dis[u]){
				dis[v] = dis[u];
				Q.push_front(v);
			}
		}
	}
	return dis.back();
			
	//return temp.size();
}

int main(){
	
	int n;
	cin>>n;
	
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	
	vector<vector<int>> ind(n);
	rep(i,n){
		ind[a[i]-1].push_back(i);
	}
	
	vector<pair<int,int>> lr;
	rep(i,n){
		if(ind[i].size()<=1)continue;
		lr.emplace_back(ind[i][0],ind[i].back());
	}
	sort(lr.begin(),lr.end());
	
	vector<int> imos(n+1,0);
	rep(i,lr.size()){
		imos[lr[i].first] ++;
		imos[lr[i].second+1] --;
	}
	rep(i,n)imos[i+1] += imos[i];
	int ans = 0;
	rep(i,n){
		if(imos[i]>0)ans++;
	}
	//cout<<ans<<endl;
	vector<vector<pair<int,int>>> LR;
	int mm = -1;
	rep(i,lr.size()){
		if(mm < lr[i].first){
			LR.push_back(vector<pair<int,int>>(1,lr[i]));
			mm = lr[i].second;
		}
		else{
			mm = max(mm,lr[i].second);
			LR.back().push_back(lr[i]);
		}
	}
	rep(i,LR.size()){
		ans -= get(LR[i])+1;
	}
	printf("%d\n",ans);
	
	return 0;
}