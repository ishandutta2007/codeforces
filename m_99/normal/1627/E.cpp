#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000000000000000
int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n,m,kk;
		scanf("%d %d %d",&n,&m,&kk);
		
		vector<long long> x(n);
		rep(i,n)scanf("%lld",&x[i]);
		vector<vector<int>> t(n);
		t[0].push_back(0);
		t.back().push_back(m-1);
		vector<int> a(kk),b(kk),C(kk),d(kk);
		vector<long long> h(kk);
		rep(i,kk){
			scanf("%d %d %d %d %lld",&a[i],&b[i],&C[i],&d[i],&h[i]);
			a[i]--;b[i]--;C[i]--;d[i]--;
			t[a[i]].push_back(b[i]);
			t[C[i]].push_back(d[i]);
		}
		rep(i,n){
			sort(t[i].begin(),t[i].end());
			t[i].erase(unique(t[i].begin(),t[i].end()),t[i].end());
		}
		
		vector E(n,vector(0,vector<int>()));
		vector<vector<long long>> dis(n);
		rep(i,n){
			E[i].resize(t[i].size());
			dis[i].resize(t[i].size(),Inf);
		}
		
		rep(i,kk){
			int dd = distance(t[a[i]].begin(),lower_bound(t[a[i]].begin(),t[a[i]].end(),b[i]));
			E[a[i]][dd].push_back(i);
		}
		
		dis[0][0] = 0;
		
		rep(i,n){
			priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> Q;
			rep(j,dis[i].size()){
				if(dis[i][j]==Inf)continue;
				Q.emplace(dis[i][j],j);
			}
			while(Q.size()>0){
				
				long long D = Q.top().first;
				int r = i;
				int c = Q.top().second;
				Q.pop();
				if(dis[r][c]!=D)continue;
				if(c!=0){
					long long DD = D + x[r] * abs(t[r][c] - t[r][c-1]);
					int rr = r,cc = c-1;
					if(dis[rr][cc]>DD){
						dis[rr][cc] = DD;
						Q.emplace(DD,cc);
					}
				}
				if(c+1!=dis[r].size()){
					long long DD = D + x[r] * abs(t[r][c] - t[r][c+1]);
					int rr = r,cc = c+1;
					if(dis[rr][cc]>DD){
						dis[rr][cc] = DD;
						Q.emplace(DD,cc);
					}
				}			
				
			}
			
			rep(j,E[i].size()){
				if(dis[i][j]==Inf)continue;
				rep(k,E[i][j].size()){
					int ind = E[i][j][k];
					int rr = C[ind];
					int cc = distance(t[rr].begin(),lower_bound(t[rr].begin(),t[rr].end(),d[ind]));
					long long DD = dis[i][j] - h[ind];
					dis[rr][cc] = min(dis[rr][cc],DD);
				}
			}
		}	
		
		long long ans = dis.back().back();
		if(ans==Inf)printf("NO ESCAPE\n");
		else printf("%lld\n",ans);
		
	}
	
	return 0;
}