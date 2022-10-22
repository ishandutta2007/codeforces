#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){

	int n;
	cin>>n;
	
	if(n&1){
		cout<<"Second"<<endl;
		vector<int> p(2*n);
		vector<vector<pair<int,int>>> E(n,vector<pair<int,int>>());
		vector<vector<int>> x(n,vector<int>());
		rep(i,2*n){
			scanf("%d",&p[i]);
			x[p[i]-1].push_back(i);
		}
		
		rep(i,n){
			E[x[i][0]%n].emplace_back(x[i][0],x[i][1]);
			E[x[i][1]%n].emplace_back(x[i][1],x[i][0]);
			
			E[i].emplace_back(i,i+n);
			E[i].emplace_back(i+n,i);
		}
		vector<int> ans;
		vector<bool> used(n*2,false);
		
		rep(i,2*n){
			if(used[i])continue;
			int now = E[i][0].first;
			used[now] = true;
			ans.push_back(now);
			int x = 1;
			while(true){
				int t = -1;
				rep(j,E[now%n].size()){
					if(E[now%n][j].first!=now)continue;
					if(used[E[now%n][j].second])continue;
					t=j;
					break;
				}
				if(t==-1)break;
				int nxt = E[now%n][t].second;
				if(x==0)ans.push_back(nxt);
				x^=1;
				now = nxt;
				used[nxt] = true;
			}
		}
		int parity = 0;
		rep(i,ans.size()){
			ans[i]++;
			parity+=ans[i];
			parity%=2;
		}
		
		if(parity==1){
			rep(i,ans.size()){
				if(ans[i]<=n)ans[i]+=n;
				else ans[i]-=n;
			}
		}
		
		rep(i,ans.size()){
			if(i!=0)printf(" ");
			printf("%d",ans[i]);
		}
		cout<<endl;
		
	}
	else{
		printf("First\n");
		rep(i,2*n){
			if(i!=0)printf(" ");
			printf("%d",i%n+1);
		}
		cout<<endl;
	}
	
    return 0;
}