#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

int dfs(vector<vector<int>> &E,int now,int p){
	bool f = true;
	int ret = 0;
	for(int i=0;i<E[now].size();i++){
		int to = E[now][i];
		if(to==p)continue;
		int t = dfs(E,to,now);
		
		ret += t;
		if(t==0){
			if(f)f=false;
			else ret++;
		}
	}
	return ret;
}

template <typename T,typename F0,typename F1>
struct rerooting{
	F0 func0;
	F1 func1;
	T init_value;
	
	vector<T> v;
	vector<T> ans;
	vector<bool> visited;
	
	rerooting(vector<vector<int>> &E,F0 f0,F1 f1,T iv):func0(f0),func1(f1){
		init_value = iv;
		v.resize(E.size());
		ans.resize(E.size());
		visited.resize(E.size(),false);
		for(int i=0;i<E.size();i++){
			if(visited[i])continue;
			dfs(E,i,-1);
			redfs(E,i,-1,init_value);
		}
	}
	
	void dfs(vector<vector<int>> &E,int now,int p){
		v[now] = init_value;
		for(int i=0;i<E[now].size();i++){
			int to = E[now][i];
			if(to==p)continue;
			dfs(E,to,now);
			v[now] = func0(v[now],v[to]);
		}
		v[now] = func1(v[now],now,p);
		visited[now]=true;
	}
	
	void redfs(vector<vector<int>> &E,int now,int p,T pv){
		vector<T> S(E[now].size(),init_value);
		if(S.size()>1){
			for(int i=S.size()-2;i>=0;i--){
				int to = E[now][i+1];
				T x = v[to];
				if(to==p)x = pv;
				S[i] = func0(x,S[i+1]);
			}
		}
		
		T temp = init_value;
		for(int i=0;i<E[now].size();i++){
			int to = E[now][i];
			if(to!=p){
				redfs(E,to,now,func1(func0(temp,S[i]),now,to));
				temp = func0(temp,v[to]);
			}
			else{
				temp = func0(temp,pv);
			}
		}
		ans[now] = func1(temp,now,p);
	}
	
};
	
		
int main(){
	
	int _t;
	cin>>_t;
	for(int _=0;_<_t;_++){
		int N;
		cin>>N;
		if(N==1){
			printf("0\n");
			continue;
		}
		vector<vector<int>> E(N,vector<int>());
		vector<int> cnt(N,0);
		
		for(int i=0;i<N-1;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			a--,b--;
			E[a].push_back(b);
			E[b].push_back(a);
			cnt[a]++;
			cnt[b]++;
		}
		
		auto f0 = [](pair<int,int> a,pair<int,int> b){
			pair<int,int> ret(a.first+b.first,a.second+b.second);
			
			return ret;
		};
		
		auto f1 = [](pair<int,int> a,int ind,int p){
			a.first += max(0,a.second-1);
			if(a.first==0)a.second = 1;
			else a.second = 0;
			return a;
		};
		
		rerooting<pair<int,int>,decltype(f0),decltype(f1)> rr(E,f0,f1,{0,0});
		
		int ans = 1000000;
		
		for(int i=0;i<N;i++){
			if(cnt[i]==1){
				ans = min(ans,rr.ans[i].first+1);
			}
		}
		
		printf("%d\n",ans);
	}
	
	
	return 0;
}