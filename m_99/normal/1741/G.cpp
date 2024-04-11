#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 2000000000000000001


vector<int> get(vector<vector<int>> E,int s){
	int n = E.size();
	vector<int> d(n,Inf32);
	d[s] = 0;
	queue<int> Q;
	Q.push(s);
	while(Q.size()>0){
		int u = Q.front();
		Q.pop();
		rep(i,E[u].size()){
			int v = E[u][i];
			if(d[v]==Inf32){
				d[v] = d[u]+1;
				Q.push(v);
			}
		}
	}
	return d;
}

int main(){
	
	int _t;
	cin>>_t;
	rep(_,_t){
		
		int n,m;
		cin>>n>>m;
		
		vector E(n,vector<int>());
		rep(i,m){
			int a,b;
			scanf("%d %d",&a,&b);
			a--,b--;
			E[a].push_back(b);
			E[b].push_back(a);
		}
		
		int f;
		cin>>f;
		vector<int> h(f);
		rep(i,f){
			scanf("%d",&h[i]);
			h[i]--;
		}
		int k;
		cin>>k;
		vector<int> p(k);
		rep(i,k){
			scanf("%d",&p[i]);
			p[i]--;
		}
		
		vector<vector<int>> dis(k+1);
		rep(i,k){
			dis[i] = get(E,h[p[i]]);
		}
		dis[k] = get(E,0);
		
		vector<bool> dp(1<<k);
		dp[0] = true;
		rep(i,f){
			if(binary_search(p.begin(),p.end(),i))continue;
			vector<int> t(k+1);
			t[0] = k;
			rep(j,k)t[j+1] = j;
			vector<int> ok;
			do{
				int cur = 0;
				rep(j,t.size()-1){
					int d0 = dis[k][h[i]];
					int d1;
					d1 = dis[t[j]][0];
					d1 += dis[t[j]][h[p[t[j+1]]]];
					d1 += dis[t[j+1]][h[i]];
					if(d0==d1)cur |= 1<<t[j+1];
					else break;
				}
				ok.push_back(cur);
			}
			while(next_permutation(t.begin(),t.end()));
			vector<bool> ndp(1<<k);
			rep(j,1<<k){
				if(dp[j]==false)continue;
				ndp[j] = true;
				rep(l,ok.size()){
					ndp[j|ok[l]] = true;
				}
				
			}
			swap(dp,ndp);
		}
		int ans = k+5;
		rep(i,dp.size()){
			if(dp[i]==true){
				//cout<<i<<endl;
				ans = min(ans,k - __builtin_popcount(i));
			}
		}
		
		cout<<ans<<endl;
		
	}
	
	return 0;
}