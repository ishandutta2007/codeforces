#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);

		vector<long long> h(n),w(n);
		vector<long long> t;
		rep(i,n){
			scanf("%lld %lld",&h[i],&w[i]);
			if(h[i]>w[i])swap(h[i],w[i]);
			t.push_back(h[i]);
			t.push_back(w[i]);
		}
		
		sort(t.begin(),t.end());
		t.erase(unique(t.begin(),t.end()),t.end());
		
		vector<vector<int>> idx(t.size(),vector<int>());
		
		rep(i,n){
			h[i] = distance(t.begin(),lower_bound(t.begin(),t.end(),h[i]));
			w[i] = distance(t.begin(),lower_bound(t.begin(),t.end(),w[i]));
			idx[w[i]].push_back(i);
		}
		
		map<int,int> mp;
		vector<int> ans(n,-1);
		
		rep(i,t.size()){
			rep(j,idx[i].size()){
				auto it = mp.lower_bound(h[idx[i][j]]);
				if(it==mp.begin())continue;
				it--;
				ans[idx[i][j]] = it->second;
			}
			rep(j,idx[i].size()){
				mp[h[idx[i][j]]] = idx[i][j];
			}
		}
		
		rep(i,n){
			if(ans[i]!=-1)ans[i]++;
			if(i!=0)printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
		
		
	}
	
    return 0;
}