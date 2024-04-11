#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> a(n);
		priority_queue<pair<int,int>> Q;
		rep(i,n){
			scanf("%d",&a[i]);
			Q.emplace(a[i],i);
		}
		vector<pair<int,int>> ans;
		while(Q.size()>=2){
			auto X = Q.top();
			Q.pop();
			auto Y = Q.top();
			Q.pop();
			if(Y.first > 0){
				Y.first --;
				X.first --;
				ans.emplace_back(X.second,Y.second);
				Q.push(X);
				Q.push(Y);
			}
		}
		printf("%d\n",ans.size());
		rep(i,ans.size()){
			printf("%d %d\n",ans[i].first+1,ans[i].second+1);
		}
	}
	
	return 0;
}