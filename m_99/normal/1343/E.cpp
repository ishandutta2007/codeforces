#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
 
vector<long long> get(vector<vector<int>> &E,int s){
	vector<long long> ret(E.size(),Inf);
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
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n,m,a,b,c;
		scanf("%d %d %d %d %d",&n,&m,&a,&b,&c);
		a--;b--;c--;
		vector<long long> p(m);
		rep(i,m)scanf("%lld",&p[i]);
		sort(p.begin(),p.end());
		
		p.insert(p.begin(),0);
		rep(i,m){
			p[i+1] += p[i];
		}
		
		vector<vector<int>> E(n);
		rep(i,m){
			int u,v;
			scanf("%d %d",&u,&v);
			u--;v--;
			E[u].push_back(v);
			E[v].push_back(u);
		}
		
		auto da = get(E,a),db = get(E,b),dc = get(E,c);
		
		long long ans = 10000000000000000;
		rep(i,n){
			if(db[i]+da[i]+dc[i]>m)continue;
			long long temp = 0LL;
			temp += p[db[i]]*2;
			temp += p[db[i]+da[i]+dc[i]] - p[db[i]];
			ans = min(ans,temp);
		}
		
		cout<<ans<<endl;
		
	}
	
	return 0;
}