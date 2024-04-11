#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000



int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<int> d(m);
	for(int i=0;i<m;i++)scanf("%d",&d[i]);
	sort(d.begin(),d.end());
	
	int g,r;
	cin>>g>>r;
	/*
	vector<vector<int>> E(m*g,vector<int>());
	
	for(int i=0;i<m;i++){
		for(int j=0;j<g;j++){
			int from = i*g+j;
			
			if(i!=0){
				if(j+d[i]-d[i-1]<=g){
					int to = (i-1)*g + (j+d[i]-d[i-1])%g;
					E[from].push_back(to);
				}
			}
			if(i!=m-1){
				if(j+d[i+1]-d[i]<=g){
					int to = (i+1)*g + (j+d[i+1]-d[i])%g;
					E[from].push_back(to);
				}
			}
		}
	}
	*/
	
	vector<int> dis(m*g,Inf);
	dis[0] = 0;
	deque<pair<int,int>> Q;
	Q.emplace_back(0,0);
	
	while(Q.size()!=0){
		int D = Q.back().first;
		int now = Q.back().second;
		Q.pop_back();
		
		int x = now/g;
		int y = now%g;
		
		if(x!=0){
			if(y+d[x]-d[x-1]<=g){
				int to = (x-1)*g + (y+d[x]-d[x-1])%g;
				if(dis[to]==Inf){
					if(to%g==0){
						dis[to] = dis[now]+1;
						Q.emplace_front(dis[to],to);
					}
					else{
						dis[to] = dis[now];
						Q.emplace_back(dis[to],to);
					}
				}
			}
		}
		if(x!=m-1){
			if(y+d[x+1]-d[x]<=g){
				int to = (x+1)*g + (y+d[x+1]-d[x])%g;
				if(dis[to]==Inf){
					if(to%g==0){
						dis[to] = dis[now]+1;
						Q.emplace_front(dis[to],to);
					}
					else{
						dis[to] = dis[now];
						Q.emplace_back(dis[to],to);
					}
				}
			}
		}

	}
	/*
	for(int i=0;i<m;i++){
		for(int j=0;j<g;j++){
			cout<<dis[i*g+j]<<',';
		}
		cout<<endl;
	}*/
	
	int ans = Inf;
	for(int i=0;i<m;i++){
		int x = i*g;
		if(dis[x]==Inf)continue;
		if(n-d[i]>g)continue;
		ans = min(ans,n-d[i] + (g+r) * dis[x]);
	}
	
	if(ans==Inf)cout<<-1<<endl;
	else cout<<ans<<endl;
	
	return 0;
}