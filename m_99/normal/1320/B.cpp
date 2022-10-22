#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000



int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> E(n,vector<int>());
	
	vector<vector<int>> E2 = E;
	
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		u--;v--;
		
		E[v].push_back(u);
		
		E2[u].push_back(v);
	}
	
	int k;
	cin>>k;
	
	vector<int> p(k);
	
	for(int i=0;i<k;i++){
		scanf("%d",&p[i]);
		p[i]--;
	}
	
	vector<int> dis(n,Inf);
	dis[p.back()] = 0;
	queue<int> Q;
	Q.push(p.back());
	
	while(Q.size()!=0){
		int from = Q.front();
		Q.pop();
		
		for(int i=0;i<E[from].size();i++){
			int to = E[from][i];
			
			if(dis[to]!=Inf)continue;
			
			dis[to] = dis[from] + 1;
			Q.push(to);
		}
	}

	int mini = 0;
	int maxi = 0;
	
	for(int i=1;i<k;i++){
		if(dis[p[i]]+1 == dis[p[i-1]]){
			int cnt = 0;
			for(int j=0;j<E2[p[i-1]].size();j++){
				int to = E2[p[i-1]][j];
				if(dis[to]+1==dis[p[i-1]])cnt++;
			}
			if(cnt>=2)maxi++;
		}
		else{
			mini ++;
			maxi ++;
		}
	}
	
	cout<<mini<<' '<<maxi<<endl;
	
	return 0;
}