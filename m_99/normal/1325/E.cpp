#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

int calc(vector<vector<int>> &E,int start,vector<pair<int,int>> s){
	vector<bool> used(s.size(),false);
	vector<int> dis(E.size(),Inf);
	queue<int> Q;
	Q.push(start);
	dis[start] = 0;
	
	while(Q.size()!=0){
		int from = Q.front();
		Q.pop();
		
		for(int i=0;i<E[from].size();i++){
			int to = E[from][i];
			if(dis[to]!=Inf)continue;
			dis[to] = dis[from]+1;
			Q.push(to);
			used[distance(s.begin(),lower_bound(s.begin(),s.end(),make_pair(min(from,to),max(from,to))))] = true;
		}
	}
	
	int ret = Inf;
	for(int i=0;i<s.size();i++){
		if(used[i])continue;
		ret = min(ret,dis[s[i].first]+dis[s[i].second]+1);
	}
	
	return ret;
}

int main(){
	
	vector<int> p(1000001,-1);
	vector<long long> P;
	
	for(int i=2;i<p.size();i++){
		if(p[i]==-1){
			P.push_back((long long)i);
			for(int j=i;j<p.size();j+=i){
				if(p[j]==-1)p[j]=i;
			}
		}
	}
	
	map<int,int> mp;
	
	mp[1] = 0;
	for(int i=0;i<P.size();i++){
		mp[P[i]] = i+1;
	}
	
	set<pair<int,int>> S;
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		
		set<int> temp;
		while(p[a]!=-1){
			if(temp.count(p[a])){
				temp.erase(p[a]);
			}
			else{
				temp.insert(p[a]);
			}
			a/=p[a];
		}
		
		if(temp.size()==0)S.insert({mp[1],mp[1]});
		if(temp.size()==1)S.insert({mp[1],mp[*(temp.begin())]});
		if(temp.size()==2)S.insert({mp[*(temp.begin())],mp[*(temp.rbegin())]});
	}
	
	if(S.count({mp[1],mp[1]})){
		cout<<1<<endl;
		return 0;
	}
	
	if(S.size()!=n){
		cout<<2<<endl;
		return 0;
	}
	
	vector<vector<int>> E(mp.size(),vector<int>());
	vector<pair<int,int>> s;
	
	for(auto a:S){
		int u = a.first;
		int v = a.second;
		
		E[u].push_back(v);
		E[v].push_back(u);
		
		s.emplace_back(u,v);
	}
	
	int ans = Inf;
	
	for(int i=0;i<E.size();i++){
		if(i!=0&&P[i-1]>1000)break;
		ans = min(ans,calc(E,i,s));
	}
	
	if(ans==Inf)cout<<-1<<endl;
	else cout<<ans<<endl;
	
	return 0;
}