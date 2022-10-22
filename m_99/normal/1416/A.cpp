#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000300



int main(){
	
	int t;
	cin>>t;
	
	rep(_,t){
		int n;
		scanf("%d",&n);
		
		vector<vector<int>> inds(n,vector<int>(1,-1));
		
		rep(i,n){
			int a;
			scanf("%d",&a);
			a--;
			inds[a].push_back(i);
		}
		vector<int> ans(n,Inf);
		rep(i,n){
			int M = 0;
			inds[i].push_back(n);
			rep(j,inds[i].size()-1){
				int t = inds[i][j+1] - inds[i][j];
				t--;
				M = max(M,t);
			}
			if(M<n)ans[M] = min(ans[M],i);
		}
		
		rep(i,n){
			if(i!=0)ans[i] = min(ans[i],ans[i-1]);
		}
		
		rep(i,n){
			if(i!=0)printf(" ");
			if(ans[i]==Inf)printf("-1");
			else printf("%d",ans[i]+1);
		}
		printf("\n");
		
	}
	
    return 0;
}