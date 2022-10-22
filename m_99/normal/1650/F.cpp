#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 100000000000000000

vector<long long> e,t,p;
		
pair<long long,vector<int>> get(vector<int> ind){
	int n = ind.size();
	vector dp(n+1,vector<pair<long long,int>>(101,make_pair(Inf,-1)));
	
	dp[0][0] = make_pair(0,-1);
	rep(i,n){
		rep(j,101){
			if(dp[i][j].first==Inf)continue;
			int ii = i+1;
			int jj = j;
			auto pp = dp[i][j];
			pp.second = j;
			dp[ii][jj] = min(dp[ii][jj],pp);
			
			jj = min(100LL,jj + p[ind[i]]);
			pp.first += t[ind[i]];
			dp[ii][jj] = min(dp[ii][jj],pp);
		}
	}
	pair<long long,vector<int>> ret(Inf,vector<int>());
	
	ret.first = dp.back().back().first;
	if(ret.first==Inf)return ret;
	int cur = 100;
	for(int i=n;i>=1;i--){
		if(dp[i][cur].second==cur)continue;
		ret.second.push_back(ind[i-1]);
		cur = dp[i][cur].second;
	}
	return ret;
	
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		
		cin>>n>>m;
		
		vector<long long> a(n);
		rep(i,n)scanf("%lld",&a[i]);
		
		vector<vector<int>> plan(n);
		e.resize(m),p.resize(m),t.resize(m);
		rep(i,m){
			scanf("%lld %lld %lld",&e[i],&t[i],&p[i]);
			e[i]--;
			plan[e[i]].push_back(i);
		}
		vector<pair<long long,vector<int>>> ans(n);
		bool f  =true;
		rep(i,n){
			ans[i] = get(plan[i]);
			if(ans[i].first == Inf){
				f = false;
				break;
			}
		}
		if(!f){
			cout<<-1<<endl;
			continue;
		}
		
		vector<int> ind(n);
		rep(i,n)ind[i] = i;
		sort(ind.begin(),ind.end(),[&](int x,int y){
			return a[x]<a[y];//ans[x].first + a[x]<ans[y].first + a[y];
		});
		long long cur = 0LL;
		vector<int> as;
		rep(i,n){
			int ii = ind[i];
			auto tt = ans[ii].second;
			rep(j,tt.size()){
				as.push_back(tt[j]);
			}
			cur += ans[ii].first;
			if(cur > a[ii]){
				f = false;
				break;
			}
		}
		if(!f){
			cout<<-1<<endl;
			continue;
		}
		else{
			cout<<as.size()<<endl;
			rep(i,as.size()){
				if(i!=0)printf(" ");
				printf("%d",as[i]+1);
			}
			printf("\n");
		}
	}
	
	return 0;
}