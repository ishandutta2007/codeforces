#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		scanf("%d %d",&n,&m);
		
		map<int,int> mp;
		rep(i,n){
			int a;
			scanf("%d",&a);
			mp[a]++;
		}
		
		vector<int> t;
		for(auto a:mp)t.push_back(a.second);
		sort(t.begin(),t.end());
		t.erase(unique(t.begin(),t.end()),t.end());
		
		vector<vector<int>> num(t.size());
		
		for(auto a:mp){
			num[distance(t.begin(),lower_bound(t.begin(),t.end(),a.second))].push_back(a.first);
		}
		rep(i,t.size())sort(num[i].rbegin(),num[i].rend());
		
		vector<pair<int,int>> ng;
		rep(i,m){
			int u,v;
			scanf("%d %d",&u,&v);
			ng.emplace_back(u,v);
			ng.emplace_back(v,u);
		}
		
		
		sort(ng.begin(),ng.end());
		long long ans = 0LL;
		
		for(auto a:mp){
			long long x = a.first;
			long long y = a.second;
			rep(i,t.size()){
				rep(j,num[i].size()){
					if(num[i][j]==x)continue;
					if(binary_search(ng.begin(),ng.end(),make_pair(a.first,num[i][j])))continue;
					ans = max(ans,((long long)y+t[i]) * ((long long)x+num[i][j]));
					break;
				}
			}
		}
		
		printf("%lld\n",ans);
	}
	
	return 0;
}