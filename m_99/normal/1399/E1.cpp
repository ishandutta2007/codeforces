#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
map<pair<int,int>,int> mp;
vector<int> ps;
vector<int> sz;
void dfs(int cur,int p,vector<vector<int>> &E){
	
	//cout<<cur<<endl;
	
	ps[cur] = p;
	bool f = true;
	sz[cur] = 0;
	rep(i,E[cur].size()){
		int to = E[cur][i];
		if(to==p)continue;
		dfs(to,cur,E);
		f=false;
		sz[cur] += sz[to];
	}
	if(f)sz[cur] ++;
}

vector<long long> get(vector<long long> a,vector<long long> b){
	vector<long long> ret(1,0LL);
	
	priority_queue<pair<long long,int>> Q;
	rep(i,a.size()){
		long long x = a[i]*b[i];
		long long y = ((a[i]/2)*b[i]);
		Q.emplace(x-y,i);
		//cout<<a[i]<<','<<b[i]<<endl;
	}
	
	while(Q.size()!=0){
		ret.push_back(Q.top().first + ret.back());
		int ind = Q.top().second;
		Q.pop();
		a[ind] /= 2;
		if(a[ind]==0)continue;
		long long x = a[ind]*b[ind];
		long long y = (a[ind]/2)*b[ind];
		
		
		Q.emplace(x-y,ind);
		
	}
	return ret;
	
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		long long S;
		scanf("%d %lld",&n,&S);
		
		vector<vector<int>> E(n);
		mp.clear();
		vector<int> u(n-1),v(n-1),w(n-1);
		rep(i,n-1){
			scanf("%d %d %d",&u[i],&v[i],&w[i]);
			u[i]--;v[i]--;
			mp[make_pair(u[i],v[i])] = i;
			mp[make_pair(v[i],u[i])] = i;
		
			E[u[i]].push_back(v[i]);
			E[v[i]].push_back(u[i]);
		}
		
		ps.resize(n),sz.resize(n);
		
		dfs(0,-1,E);
		
		vector<long long> x(n-1),y(n-1);
		long long sum = 0LL;
		rep(i,n-1){
			int Ind = mp[make_pair(i+1,ps[i+1])];
			x[i] = w[Ind];
			y[i] = sz[i+1];
			sum += x[i] * y[i];
		}
		vector<long long> ans = get(x,y);
		
		rep(i,ans.size()){
		
			if(sum - ans[i] <= S){
				printf("%d\n",i);
				break;
			}
		}
		
		
		
	}
	
	return 0;
}