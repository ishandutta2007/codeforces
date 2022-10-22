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
		vector<int> u(n-1),v(n-1),w(n-1),c(n-1);
		rep(i,n-1){
			scanf("%d %d %d %d",&u[i],&v[i],&w[i],&c[i]);
			u[i]--;v[i]--;
			mp[make_pair(u[i],v[i])] = i;
			mp[make_pair(v[i],u[i])] = i;
		
			E[u[i]].push_back(v[i]);
			E[v[i]].push_back(u[i]);
		}
		
		ps.resize(n),sz.resize(n);
		
		dfs(0,-1,E);
		
		vector<long long> x1,y1,x2,y2;
		long long sum = 0LL;
		rep(i,n-1){
			int Ind = mp[make_pair(i+1,ps[i+1])];
			if(c[Ind]==1){
				x1.push_back(w[Ind]);
				y1.push_back(sz[i+1]);
			}
			else{
				x2.push_back(w[Ind]);
				y2.push_back(sz[i+1]);
			}
			
			sum += (long long)w[Ind] * sz[i+1];
		}
		vector<long long> ans1 = get(x1,y1),ans2 = get(x2,y2);
		
		int ans = Inf;
		
		rep(i,ans1.size()){
			long long need = (sum-ans1[i]) - S;
			int d = distance(ans2.begin(),lower_bound(ans2.begin(),ans2.end(),need));
			if(d==ans2.size())continue;
			ans = min(ans,d*2+i);
		}
		printf("%d\n",ans);
		
		
		
	}
	
	return 0;
}