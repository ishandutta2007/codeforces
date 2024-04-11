#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int n,k;
int ans;
vector<vector<int>> E;
vector<bool> f;

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		scanf("%d %d",&n,&k);
		
		ans = 0;
		E.assign(n,vector<int>());
		vector<int> d(n,0);
		rep(i,n-1){
			int u,v;
			scanf("%d %d",&u,&v);
			u--;v--;
			E[u].push_back(v);
			E[v].push_back(u);
			d[u]++;
			d[v]++;
		}
		if(k==1){
			printf("%d\n",n-1);
			continue;
		}
		
		f.assign(n,false);
		vector<int> cnt(n,0);
		rep(i,n){
			if(d[i]==1){
				f[i] = true;
				rep(j,E[i].size())cnt[E[i][j]]++;
			}
		}
		
		set<pair<int,int>> S;
		rep(i,n)S.emplace(cnt[i],i);
		
		while(S.size()>0){
			pair<int,int> p;
			{
				auto it = S.end();
				it--;
				p = *it;
				S.erase(it);
			}
			
			if(p.first < k)break;
			p.first -= k;
			cnt[p.second] -= k;
			ans++;
			d[p.second] -= k;
			if(d[p.second] == 1){
				f[p.second] = true;
				rep(i,E[p.second].size()){
					int to = E[p.second][i];
					if(f[to])continue;
					S.erase(make_pair(cnt[to],to));
					cnt[to]++;
					S.insert(make_pair(cnt[to],to));
				}
			}
			S.insert(p);
			
		}
		
		printf("%d\n",ans);
		
	}
	
	return 0;
}