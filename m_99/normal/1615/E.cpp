#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001
vector<vector<int>> E;
vector<int> l,r;
int lc = 0;

void dfs(int cur,int p){
	l[cur] = 0;
	rep(i,E[cur].size()){
		int to = E[cur][i];
		if(to==p)continue;
		dfs(to,cur);
		l[cur] = max(l[cur],l[to]+1);
	}
}

void dfs2(int cur,int p){
	if(l[cur]!=-1){
		r.push_back(l[cur]+1);
	}
	int m = -1,ind = -1;
	rep(i,E[cur].size()){
		int to = E[cur][i];
		if(to==p)continue;
		if(l[to]>m){
			m = l[to];
			ind = to;
		}
	}
	if(ind==-1)return;
	l[ind] = -1;
	rep(i,E[cur].size()){
		int to = E[cur][i];
		if(to==p)continue;
		dfs2(to,cur);
	}
}

int main(){
	

	int _t;
	_t = 1;
	
	rep(_,_t){
		
		int n,k;
		scanf("%d %d",&n,&k);
		E.assign(n,vector<int>());
		
		rep(i,n-1){
			int u,v;
			scanf("%d %d",&u,&v);
			u--;v--;
			E[u].push_back(v);
			E[v].push_back(u);
		}
		
		l.resize(n);
		r.resize(0);
		dfs(0,-1);
		dfs2(0,-1);
		
		long long rr = k;
		if(rr>r.size() && rr>n/2)rr = n/2;
		//cout<<rr<<endl;
		long long ans = 0;
		ans += rr * (n-rr);
		
		long long bb = n;
		sort(r.rbegin(),r.rend());
		/*rep(i,r.size()){
			cout<<r[i]<<endl;
		}*/
		rep(i,min((int)r.size(),k)){
			bb -= r[i];
		}
		if(bb>n/2)bb = n/2;
		ans -= bb * (n-bb);
		
		cout<<ans<<endl;
		
	}
	
	return 0;
}