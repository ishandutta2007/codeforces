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
		multiset<int> S;
		vector<int> a(2*n);
		rep(i,2*n){
			scanf("%d",&a[i]);
			S.insert(a[i]);
		}
		int xstart;
		{
			auto it = S.end();
			it--;
			xstart = *it;
			S.erase(it);
		}
		vector<pair<int,int>> ans;
		rep(i,2*n){
			if(S.find(a[i])==S.end())continue;
			multiset<int> cS = S;
			ans.emplace_back(xstart,a[i]);
			auto it = S.lower_bound(a[i]);
			S.erase(it);
			
			while(S.size()!=0){
				it = S.end();
				it--;
				int x = *it;
				S.erase(it);
				it = S.find(max(ans.back().first,ans.back().second)-x);
				if(it==S.end())break;
				it = S.lower_bound(max(ans.back().first,ans.back().second)-x);
				ans.emplace_back(*it,x);
				S.erase(it);
			}
			if(ans.size()==n)break;
			S = cS;
			ans.resize(0);
		}
		
		if(ans.size()==n){
			printf("YES\n");
			printf("%d\n",ans[0].first+ans[0].second);
			rep(i,n){
				printf("%d %d\n",ans[i].first,ans[i].second);
			}
		}
		else{
			printf("NO\n");
		}
		
		
	}
	
    return 0;
}