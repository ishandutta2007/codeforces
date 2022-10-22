#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){

	int N;
	cin>>N;
	vector<long long> A(N);
	
	vector<vector<int>> ind(60,vector<int>(0));
	
	for(int i=0;i<N;i++){
		cin>>A[i];
		long long a = A[i];
		
		for(int j=0;j<60;j++){
			if(a&1){
				ind[j].push_back(i);
			}
			a>>=1;
		}
		
	}
	
	map<int,int> mp;
	for(int i=0;i<60;i++){
		if(ind[i].size()>=3){
			cout<<3<<endl;
			return 0;
		}
		
		if(ind[i].size()==2){
			mp[ind[i][0]] = -1;
			mp[ind[i][1]] = -1;
		}
	}
	int cnt = 0;
	for(auto &a:mp){
		a.second = cnt;
		cnt++;
	}
	
	
	
	vector<vector<int>> E(cnt,vector<int>(0));
	for(int i=0;i<60;i++){
		if(ind[i].size()==2){
			E[mp[ind[i][0]]].push_back(mp[ind[i][1]]);
			E[mp[ind[i][1]]].push_back(mp[ind[i][0]]);
		}
	}
	
	int ans = Inf;
	for(int i=0;i<cnt;i++){
		for(int j=0;j<cnt;j++){
			if(i==j)continue;
			
			vector<int> dis(cnt,-1);
			dis[i] = 0;
			queue<int> q;
			q.push(i);
			
			while(q.size()!=0){
				int from = q.front();
				q.pop();
				for(int k=0;k<E[from].size();k++){
					int to = E[from][k];
					if(dis[to]!=-1)continue;
					dis[to] = dis[from]+1;
					q.push(to);
				}
			}
			if(dis[j]==-1)continue;
			int aa = dis[j];
			set<pair<int,int>> used;
			
			int now = j;
			while(true){
				for(int k=0;k<E[now].size();k++){
					int to = E[now][k];
					if(dis[now]-1 == dis[to]){
						used.insert(make_pair(now,to));
						used.insert(make_pair(to,now));
						now = to;
						break;
					}
				}
				if(now==i)break;
			}
			
			for(int k=0;k<cnt;k++)dis[k]=-1;
			
			q.push(i);
			dis[i]=0;
			while(q.size()!=0){
				int from = q.front();
				q.pop();
				for(int k=0;k<E[from].size();k++){
					
					int to = E[from][k];
					if(used.find(make_pair(from,to))!=used.end()){
						continue;
					}
					
					if(dis[to]!=-1)continue;
					dis[to] = dis[from]+1;
					q.push(to);
				}
			}
			
			if(dis[j]==-1)continue;
			ans = min(ans,dis[j]+aa);
			
		}
	}
	if(ans>=Inf)cout<<-1<<endl;
	else cout<<ans<<endl;
		
		
	return 0;
}