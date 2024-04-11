#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000
vector<int> p;
vector<vector<int>> depth;
void dfs(vector<vector<int>> &E,int cur,int par,int d){
	p[cur] = par;
	depth[d].push_back(cur);
	rep(i,E[cur].size()){
		int to = E[cur][i];
		if(to==par)continue;
		dfs(E,to,cur,d+1);
	}
}

template <typename T,typename F>
struct SWAG{
	F func;
	T init_value;
	vector<pair<T,T>> X,Y;
	SWAG(F f,T iv):func(f){
		init_value = iv;
	}
	
	void push_front(T x){
		if(X.empty())X.push_back({x,x});
		else X.push_back({x,func(x,X.back().second)});
	}
	
	void push_back(T x){
		if(Y.empty())Y.push_back({x,x});
		else Y.push_back({x,func(Y.back().second,x)});
	}
	
	void pop_front(){
		if(X.empty()){
			int n = Y.size();
			vector<T> t;
			for(int i=0;i<n/2;i++){
				t.push_back(Y.back().first);
				Y.pop_back();
			}
			while(!Y.empty()){
				push_front(Y.back().first);
				Y.pop_back();
			}
			while(!t.empty()){
				push_back(t.back());
				t.pop_back();
			}
			if(!X.empty())X.pop_back();
		}
		else{
			X.pop_back();
		}
	}
	
	void pop_back(){
		if(Y.empty()){
			int n = X.size();
			stack<T> t;
			for(int i=0;i<n/2;i++){
				t.push_back(X.back().first);
				X.pop_back();
			}
			while(!X.empty()){
				push_back(X.back().first);
				X.pop_back();
			}
			while(!t.empty()){
				push_front(t.back());
				t.pop_back();
			}
			if(!Y.empty())Y.pop_back();
		}
		else{
			Y.pop_back();
		}
	}
	
	T get(){
		T ret = init_value;
		if(!X.empty())ret = func(ret,X.back().second);
		if(!Y.empty())ret = func(ret,Y.back().second);
		return ret;
	}
	
	T front(){
		if(!X.empty())return X.back().first;
		if(!Y.empty())return Y[0].first;
		return init_value;
	}
	
	T back(){
		if(!Y.empty())return Y.back().first;
		if(!X.empty())return X[0].first;
		return init_value;
	}
	
	int size(){
		return X.size()+Y.size();
	}
	
};

int main(){
	
	int _t;
	cin>>_t;
	
	auto f = [](long long a,long long b){
		return max(a,b);
	};
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		vector<vector<int>> E(n);
		rep(i,n-1){
			int v;
			scanf("%d",&v);
			v--;
			E[i+1].push_back(v);
			E[v].push_back(i+1);
		}
		vector<long long> a(n,0);
		rep(i,n-1){
			scanf("%lld",&a[i+1]);
		}

		
		
		p.assign(n,-1);
		depth.assign(n+1,vector<int>());
		dfs(E,0,-1,0);
		//cout<<'a'<<endl;
		vector<long long> dp(n,-1);
		dp[0] = 0;
		//cout<<'b'<<endl;
		
		for(int i=1;i<depth.size();i++){
			if(depth[i].size()==0)break;
			vector<pair<long long,int>> V;
			rep(j,depth[i].size()){
				V.emplace_back(a[depth[i][j]],depth[i][j]);
			}
			sort(V.begin(),V.end());
			rep(j,V.size()){
				int ind = V[j].second;
				dp[ind] = dp[p[ind]] + max(V.back().first-V[j].first,V[j].first-V[0].first);
			}
			
			SWAG<long long,decltype(f)> S0(f,-Inf),S1(f,-Inf);
			
			rep(j,V.size()){
				int ind = V[j].second;
				S1.push_back(a[ind] + dp[p[ind]]);
			}
			
			rep(j,V.size()){
				int ind = V[j].second;
				S1.pop_front();
				dp[ind] = max(dp[ind],a[ind] + S0.get());
				dp[ind] = max(dp[ind],-a[ind] + S1.get());
				S0.push_back(-a[ind] + dp[p[ind]]);
				
			}
			
			
		}
		long long ans = 0LL;
		rep(i,n)ans = max(ans,dp[i]);
		
		printf("%lld\n",ans);
		
		
	}
		
	
	return 0;
}